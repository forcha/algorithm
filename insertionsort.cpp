#include <iostream>
#include <vector>
#include <utility>
#include "util.h"

template<typename T>
void sort(std::vector<T> & container) {
  size_t length = container.size();
  for (size_t i = 0; i < length; i++) {
    for (size_t j = i; j > 0; j--) {
      if (container[j] < container[j - 1]) {
        std::swap(container[j], container[j - 1]);
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  std::vector<int> vec {1, 5, 7, 2, 3, 6, 9, 4, 2};

  std::cout << "Before: " << vec << '\n';
  sort(vec);

  std::cout << "After: " << vec << '\n';
  return 0;
}
