#include <iostream>
#include "SortTestHelper.h"
#include "SortingAlg.h"

int main() {
    int n = 10000;
    int *arr1 = SortTestHelper::createRandomArray(n, 1, 100);
    int *arr2 = SortTestHelper::copyArr(arr1, n);

    int *arr3 = SortTestHelper::createNearRandomArray(n, 100);
    int *arr4 = SortTestHelper::copyArr(arr3, n);
    //栈中实例化对象
    SortingAlg<int> sortingAlg;

    SortTestHelper::testSort(arr1, n, &sortingAlg, &SortingAlg<int>::mergeSortingBU, "mergeSortingBU");

    SortTestHelper::testSort(arr2, n, &sortingAlg, &SortingAlg<int>::mergeSorting, "mergeSorting");

    SortTestHelper::testSort(arr3, n, &sortingAlg, &SortingAlg<int>::selectSorting, "selectSorting");

    SortTestHelper::testSort(arr4, n, &sortingAlg, &SortingAlg<int>::shellSorting, "shellSorting");
    return 0;
}
