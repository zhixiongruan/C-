//
// Created by zhixiong ruan on 2019-06-20.
//

#ifndef SORTING_ALG_SORTINGALG_H
#define SORTING_ALG_SORTINGALG_H
#include <algorithm>
#include <iostream>

template <typename T>
class SortingAlg {
public:
    SortingAlg();
    ~SortingAlg();
    void selectSorting(T arr[], int n);
    void insertSorting(T arr[], int n);

};
/**
 * 构造函数
 * @tparam T
 */
template<typename T>
SortingAlg<T>::SortingAlg() {}
/**
 * 虚构函数
 * @tparam T
 */
template<typename T>
SortingAlg<T>::~SortingAlg() {}

/**
 * 选择排序，从第一个数开始，依次找到当前位置最小值，然后交换；继续下一个寻找
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void SortingAlg<T>::selectSorting(T arr[], int n) {
    for (int i = 0; i < n; i++){
        int k = i;
        for (int j = i + 1; j < n; j++){
            if(arr[j] < arr[k]) {
                k = j;
            }
        }
        std::swap(arr[i], arr[k]);
    }
}

template <typename T>
void SortingAlg<T>::insertSorting(T arr[], int n) {

    for (int i = 1; i < n; i++){
        for (int j = i; j > 0 ; j--){
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
            } else {
                break;
            }
        }
    }

}


#endif //SORTING_ALG_SORTINGALG_H
