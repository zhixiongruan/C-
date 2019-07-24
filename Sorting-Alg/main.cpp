#include <iostream>
#include "SortTestHelper.h"
#include "SortingAlg.h"
#include "BinarySearchTree.h"

int main() {
    int n = 100;
#if 0
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
#endif

#if 1
    srand(time(NULL));
    BinarySearchTree<int,int> bst1 = BinarySearchTree<int,int>();
    int *a = new int[n];
    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%n;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        a[i] = key;
        bst1.insertNode(key,value);
    }
    bst1.levelOrder();
    std::cout<<std::endl;
    int i = a[40];
    if( bst1.contain( i )){
        bst1.remove(i);
        std::cout<< "After remove " << i << " size = " << bst1.size() <<std::endl;
        bst1.levelOrder();
    }

#endif
    return 0;
}
