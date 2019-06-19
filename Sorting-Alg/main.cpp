#include <iostream>
#include "SortTestHelper.h"

int main() {
    int n = 100;
    int *arr1 = SortTestHelper::createRandomArray(n, 1, 100);
    SortTestHelper::printArray(arr1, n);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}