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
    void bubbleSorting(T arr[], int n);
    void shellSorting(T arr[], int n);
    void mergeSorting(T arr[], int n);
    void mergeSortingBU(T arr[], int n);
    void quickSorting(T arr[], int n);

private:
    void insertSorting(T arr[], int l, int r);
    void merge(T arr[], int l, int min, int r);
    void mergeSorting(T arr[], int l, int r);
    void quickSorting(T arr[], int l, int r);
    int partition(T arr[], int l, int r);

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

/**
 * 插入排序,相邻两个数比较，大的数排后面，
 * 该排序算法对于那种大部分已经排好序，只有少部分需要排序的数组，
 * 排序速度较快
 * @tparam T
 * @param arr
 * @param n
 */
template <typename T>
void SortingAlg<T>::insertSorting(T arr[], int n) {

    for (int i = 1; i < n; i++){
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--){
                std::swap(arr[j], arr[j - 1]);
        }
    }
}

/**
 * 对数组中一部分进行排序
 * @tparam T
 * @param arr
 * @param l
 * @param r
 */
template <typename T>
void SortingAlg<T>::insertSorting(T arr[], int l, int r) {

    for (int i = l + 1; i <= r; i++){
        for (int j = i; j > l && arr[j] < arr[j - 1]; j--){
            std::swap(arr[j], arr[j - 1]);
        }
    }
}

/**
 * 冒泡排序
 * @tparam T
 * @param arr
 * @param n
 */
template <typename T>
void SortingAlg<T>::bubbleSorting(T arr[], int n) {

    for (int i = 0; i < n - 1; i++){
        bool flag = true;
        for (int j = 1; j < n - i; j++){
            if (arr[j] < arr[j - 1]){
                std::swap(arr[j], arr[j - 1]);
                flag = false;
            }
        }

        if (flag) {
            return;
        }
    }
//    写法2里:
//    bool swapped;
//    do{
//        swapped = false;
//        for( int i = 1 ; i < n ; i ++ )
//            if( arr[i-1] > arr[i] ){
//                swap( arr[i-1] , arr[i] );
//                swapped = true;
//            }
//
//        n --;
//
//    } while (swapped);

}

/**
 * Shell排序可以说是插入排序的升级版，相比较插入排序，
 * Shell排序首先使用大间隔、少元素的插入排序，使得每次移动的数据少，但是移动的跨度大；
 * 然后再使用小间隔，略多数量元素的插入排序，经过上一步插入排序，很多数据已经距离排序位置不远了，
 * 这样第二次插入排序时，需要移动的数据的数量就会减少，
 * 间隔最终减小到1.Shell排序的执行时间依赖于增量序列。
 * 可以理解为分别用逐步减小一定倍数（下面代码为3倍）的步长做插入排序
 * @tparam T
 * @param arr
 * @param n
 */

template <typename T>
void SortingAlg<T>::shellSorting(T arr[], int n) {
    int h = 1;
    while(h > n/3){
        h = h * 3 + 1;
    }
    // h可为：1，4，13，40，121，364...

    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && arr[j] < arr[j - h]; j = j - h) {
                std::swap(arr[j], arr[j - h]);
            }
        }
        h = h / 3;
    }
}

/**
 * 归并排序的排序方法，新建一个数组用于复制需要排序的数组
 * @tparam T
 * @param arr
 * @param l
 * @param mid
 * @param r
 */
template<typename  T>
void SortingAlg<T>::merge(T arr[], int l, int mid, int r){

    T aux[r-l+1];
    for( int i = l ; i <= r; i ++ )
        aux[i-l] = arr[i];

    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){

        if( i > mid )   { arr[k] = aux[j-l]; j ++;}
        else if( j > r ){ arr[k] = aux[i-l]; i ++;}
        else if( aux[i-l] < aux[j-l] ){ arr[k] = aux[i-l]; i ++;}
        else                          { arr[k] = aux[j-l]; j ++;}
    }
}

/**
 * 归并排序递归方法，
 * 优化：1。可以把小于一定长度的部分进行插入排序；
 * 2。如果左边最后一个数已经小于右边第一个数，就不需要进行归并排序了
 * @tparam T
 * @param arr
 * @param l
 * @param r
 */
template<typename  T>
void SortingAlg<T>::mergeSorting(T arr[], int l, int r){

    if (r - l <= 15){
        insertSorting(arr, l, r);
        return;
    }
    int min = (l + r) / 2;
    mergeSorting(arr, l, min);
    mergeSorting(arr, min + 1, r);
    if (arr[min] > arr[min + 1]){
        merge(arr, l, min, r);
    }
}

/**
 * 归并排序
 * @tparam T
 * @param arr
 * @param n
 */
template<typename  T>
void SortingAlg<T>::mergeSorting(T arr[], int n){

    mergeSorting(arr, 0, n - 1);
}

/**
 * 归并排序，自底向上的归并排序
 * 1. 首先将数列划分成微小的数列，每个数列也就一到两个元素。
 * 2. 不断合并
 * @tparam T
 * @param arr
 * @param n
 */
template<typename  T>
void SortingAlg<T>::mergeSortingBU(T arr[], int n){

    // Merge Sort Bottom Up 优化
    for( int i = 0 ; i < n ; i += 16 )
        insertSorting(arr,i,std::min(i+15,n-1));

    for( int sz = 16; sz <= n ; sz += sz )
        for( int i = 0 ; i < n - sz ; i += sz+sz )
            if( arr[i+sz-1] > arr[i+sz] )
                merge(arr, i, i+sz-1, std::min(i+sz+sz-1,n-1) );
}

/**
 * 快速排序划分方法，
 * 用第一个数将数组划分为大于第一个数的前一部分和小于第一个数的后一部分
 * 把第一个设为数组中随机一个数是为了从概率上大大的减小了第一个数为最小或最大及相近数的概率
 * @tparam T
 * @param arr
 * @param l
 * @param r
 */
template<typename  T>
int SortingAlg<T>::partition(T arr[], int l, int r){

    swab(arr[l], arr[rand()%(r-l+1)+l]);
    T tem = arr[l];
    int j = l;
    for (int i = l + 1; i <= r; i++){
        if (arr[i] < tem) {
            j++;
            if (j != i)
                std::swap(arr[j], arr[i]);
        }
    }
    std::swap(arr[l], arr[j]);
    return j;
}

/**
 * 快速排序递归方法，
 * 优化：1。可以把小于一定长度的部分进行插入排序；
 * 2。如果左边最后一个数已经小于右边第一个数，就不需要进行归并排序了
 * @tparam T
 * @param arr
 * @param l
 * @param r
 */
template<typename  T>
void SortingAlg<T>::quickSorting(T arr[], int l, int r){

    if (r - l <= 15){
        insertSorting(arr, l, r);
        return;
    }
    int p = partition(arr, l, r);
    quickSorting(arr, l, p - 1);
    quickSorting(arr, p + 1, r);
}

/**
 * 快速排序
 * @tparam T
 * @param arr
 * @param n
 */
template<typename  T>
void SortingAlg<T>::quickSorting(T arr[], int n){

    srand(time(NULL));
    quickSorting(arr, 0, n - 1);
}


#endif //SORTING_ALG_SORTINGALG_H
