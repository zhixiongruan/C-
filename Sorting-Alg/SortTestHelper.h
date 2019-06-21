//
// Created by zhixiong ruan on 2019-06-18.
//

#ifndef SORTING_ALG_SORTTESTHELPER_H
#define SORTING_ALG_SORTTESTHELPER_H

#include <iostream>
#include <cassert>
#include <ctime>
#include "SortingAlg.h"

namespace SortTestHelper{

    /**
     * 生成长度为n的randl到randr的随机数组
     * @param n
     * @param randL
     * @param randR
     * @return
     */
    int* createRandomArray(int n, int randL, int randR) {
        assert(randL<=randR);
        int *arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i++) {
            arr[i] = rand()%(randR - randL + 1) + randL;
        }
        return arr;
    }

    /**
     * 生成长度为n的randl到randr的随机数组
     * @param n
     * @param randL
     * @param randR
     * @return
     */
    int* createNearRandomArray(int n, int rands) {
        int *arr = new int[n];
        for (int j = 0; j < n; j++) {
            arr[j] = j;
        }
        srand(time(NULL));
        for(int i = 0; i < rands; i++) {
            std::swap(arr[rand()%n],arr[rand()%n]);
        }
        return arr;
    }

    /**
     * 打印数组
     * @tparam T
     * @param arr
     * @param n
     */
    template <typename T>
    void printArray(T arr[], int n){
        for(int i = 0; i < n; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    /**
     * 验证数组是否为从小到大的有序数组
     * @tparam T
     * @param arr
     * @param n
     * @return
     */
    template <typename T>
    bool vertifySortArr(T arr[], int n){
        for(int i = 0; i < n - 1; i++){
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    /**
     * 复制一新数组
     * @tparam T
     * @param arr
     * @param n
     * @return
     */
    template <typename T>
    T* copyArr(T arr[], int n) {
        T *arrNew = new T[n];
        for (int i = 0; i < n; i++) {
            arrNew[i] = arr[i];
        }
        return arrNew;
    }

    /**
     * 测试排序算法花费时间
     * @tparam T
     * @param arr
     * @param n
     * @param sorting
     * @param sortName
     * @return
     */
    template <typename T>
    void testSort(T arr[], int n, SortingAlg<T> *obj, void (SortingAlg<T>::*sorting)(T[], int), const std::string sortName) {
        clock_t startTime = clock();
        (obj->*sorting)(arr, n);
        clock_t endTime = clock();
        assert(vertifySortArr(arr, n));
        std::cout << sortName << " 执行时间：" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;
    }
}

#endif //SORTING_ALG_SORTTESTHELPER_H
