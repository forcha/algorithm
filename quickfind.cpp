#include <algorithm>
#include <array>
#include <iostream>

class QuickFind {

public:
  QuickFind();

  bool connected(int p, int q);
  void connect(int p, int q);

  void printDebugInfo() {  }

private:
  std::array<int, 10> array;
};

QuickFind::QuickFind() {
  int n = 0;
  for (int i = 0; i < 10; i++) {
    array[i] = i;
  }

  for (int i = 0; i < 10; i++) {
    std::cout << array[i] << std::endl;
  }

  std::for_each(array.begin(), array.end(), [] (int &value) { std::cout << value << '\n'; });

//  std::for_each(array.begin(), array.end(), [&n] (int &value) { value = n; n++; });
}

bool QuickFind::connected(int p, int q) {
  return array[p] == array[q];
}

void QuickFind::connect(int p, int q) {
  int pid = array[p];
  int qid = array[q];

  std::for_each(array.begin(), array.end(), [pid, qid] (int &value) {
    if (value == pid) {
      value = qid;
    }
  });
}

int main(int argc, char const *argv[])
{
  QuickFind quickFind;

  quickFind.printDebugInfo();

  quickFind.connect(0, 1);
  quickFind.connect(1, 2);
  quickFind.connect(3, 5);
  quickFind.connect(8, 9);

  quickFind.printDebugInfo();

  std::cout << "connected(7, 9) = " << quickFind.connected(7, 9) << "\n"; 
  std::cout << "connected(0, 2) = " << quickFind.connected(0, 2) << "\n"; 

  return 0;
}
