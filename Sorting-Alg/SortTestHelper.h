//
// Created by zhixiong ruan on 2019-06-18.
//

#ifndef SORTING_ALG_SORTTESTHELPER_H
#define SORTING_ALG_SORTTESTHELPER_H

#include <iostream>
#include <cassert>
#include <ctime>

namespace SortTestHelper{

    //生成n个randl到randr的随机数
    int* createRandomArray(int n, int randL, int randR) {
        assert(randL<=randR);
        int *arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i++) {
            arr[i] = rand()%(randR - randL + 1) + randL;
        }
        return arr;
    }

    template <typename T>
    void printArray(T arr[], int n){
        for(int i = 0; i < n; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}

#endif //SORTING_ALG_SORTTESTHELPER_H
