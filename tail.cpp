#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <algorithm>
#include <exception>

const unsigned long kDefaultLines = 10;

std::pair<std::string, unsigned long> parse_args(int argc, char const *argv[]) {
  unsigned long lines = kDefaultLines;
  if (argc == 2) {
    return std::make_pair(std::string(argv[1]), lines);
  } else {
    lines = std::stoul(argv[1]);
    return std::make_pair(std::string(argv[2]), lines);
  }
}

void print_last_n_lines(const std::string &filename, const unsigned long lines) {
  std::vector<std::string> buffer(lines);
  unsigned long size = 0;

  std::ifstream file(filename);
  while (file.peek() != EOF) {
    getline(file, buffer[size % lines]);
    size++;
  }

  unsigned long start = size > lines ? (size % lines) : 0;
  unsigned long count = std::min(lines, size);
  for (unsigned long i = 0; i < count; ++i) {
    std::cout << buffer[(start + i) % lines] << std::endl;
  }
}

int main(int argc, char const *argv[])
{
  try {
    unsigned long lines;
    std::string filename;
    std::tie(filename, lines) = parse_args(argc, argv);
    print_last_n_lines(filename, lines);
    return 0;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
}
