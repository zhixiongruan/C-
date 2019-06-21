#include <iostream>
#include "SortTestHelper.h"
#include "SortingAlg.h"

int main() {
    int n = 100;
    int *arr1 = SortTestHelper::createRandomArray(n, 1, 100);
    SortTestHelper::printArray(arr1, n);
    SortingAlg<int> sortingAlg;
    sortingAlg.selectSorting(arr1,n);
    SortTestHelper::printArray(arr1,n);
    return 0;
}