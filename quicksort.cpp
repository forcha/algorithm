#include <iostream>
#include <vector>
#include "util.h"

void partition(std::vector<int> & arr, int left, int right) {
  if (left >= right) return;

  std::cout << "arr: " << arr << "\n";

  int i = left;
  int j = right;
  int pivotIndex = (left + right) / 2;
  int pivot = arr[pivotIndex];

  while (i <= j) {
    while (arr[i] < pivot) { ++i; }

    while (arr[j] > pivot) { --j; }

    if (i > j) break;

    std::cout << " swap " << i << " with " << j << std::endl; 
    std::swap(arr[i], arr[j]);
    ++i; --j;
  }

  if (left < j) {
    partition(arr, left, j);
  }

  if (i < right) {
    partition(arr, i, right);
  }
}

int main(int argc, char const *argv[])
{
  std::vector<int> arr {4, 5, 1, 2, 4, 5, 6, 2, 4, 8, 9, 1 };

  partition(arr, 0, arr.size() - 1);

  std::cout << "result: " << arr << "\n";

  return 0;
}