#include <iostream>
#include "SortTestHelper.h"
#include "SortingAlg.h"

int main() {
    int n = 100;
    int *arr1 = SortTestHelper::createRandomArray(n, 1, 100);
    int *arr2 = SortTestHelper::copyArr(arr1, n);

    int *arr3 = SortTestHelper::createNearRandomArray(n, 100);
    int *arr4 = SortTestHelper::copyArr(arr3, n);
    //栈中实例化对象
    SortingAlg<int> sortingAlg(n);
    SortingAlg<int> sortingAlg1(arr2,n);
//    sortingAlg.heapSorting(arr1,n);
//    SortTestHelper::printArray(arr1,n);
//
//    sortingAlg.quickSorting(arr2, n);
//    SortTestHelper::printArray(arr2,n);

    SortTestHelper::testSort(arr1, n, &sortingAlg, &SortingAlg<int>::quickSorting, "quickSorting");

    SortTestHelper::testSort(arr2, n, &sortingAlg1, &SortingAlg<int>::heapSorting, "heapSorting");
//
//    SortTestHelper::testSort(arr3, n, &sortingAlg, &SortingAlg<int>::selectSorting, "selectSorting");
//
//    SortTestHelper::testSort(arr4, n, &sortingAlg, &SortingAlg<int>::shellSorting, "shellSorting");
    return 0;
}
