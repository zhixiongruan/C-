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
    SortingAlg(int x);
    SortingAlg(T arr[], int n);
    ~SortingAlg();
    void selectSorting(T arr[], int n);
    void insertSorting(T arr[], int n);
    void bubbleSorting(T arr[], int n);
    void shellSorting(T arr[], int n);
    void mergeSorting(T arr[], int n);
    void mergeSortingBU(T arr[], int n);
    void quickSorting(T arr[], int n);
    void heapSorting(T arr[], int n);

private:
    T *data;
    int count;
    int container;
    void insertSorting(T arr[], int l, int r);
    void merge(T arr[], int l, int min, int r);
    void mergeSorting(T arr[], int l, int r);
    void quickSorting(T arr[], int l, int r);
    int* partition(T arr[], int l, int r);

    void shiftUp(int x);
    void shiftDown(int x);
    void shiftDown(T arr[], int i, int n);
    void buildHeap(T item);
    T getMaxData();

};
/**
 * 构造函数
 * @tparam T
 */
template<typename T>
SortingAlg<T>::SortingAlg() {}

/**
 * 构造函数
 * @tparam T
 */
template<typename T>
SortingAlg<T>::SortingAlg(int x) {
    data = new T[x];
    count = 0;
    container = x;
}

/**
 * 构造函数, 直接初始化最大堆
 * @tparam T
 */
template<typename T>
SortingAlg<T>::SortingAlg(T arr[], int n) {
    data = new T[n];
    for (int i = 0; i < n; ++i) {
        data[i] = arr[i];
    }
    count = n - 1;
    container = n;
    for (int j = (n - 1)/2; j >= 0; j--){
        shiftDown(j);
    }
}
/**
 * 虚构函数
 * @tparam T
 */
template<typename T>
SortingAlg<T>::~SortingAlg() {
    if (data != NULL){
        delete[] data;
    }
}

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
 * 写法3(三路快排)是处理分割数有较多相同数，可以不相同的数单独组成中间的一段数组
 * @tparam T
 * @param arr
 * @param l
 * @param r
 */
template<typename  T>
int* SortingAlg<T>::partition(T arr[], int l, int r){

    std::swap(arr[l], arr[rand()%(r-l+1)+l]);
    T tem = arr[l];
    int j = l;

    //写法1
    #if 0
    for (int i = l + 1; i <= r; i++){
        if (arr[i] < tem) {
            j++;
            if (j != i)
                std::swap(arr[j], arr[i]);
        }
    }
    #endif
    //写法2
    #if 0
    int i = l+1;
    j = r;
    while( true ){
        while( i <= r && arr[i] < tem )
            i ++;

        while( j >= l+1 && arr[j] > tem )
            j --;

        if( i > j )
            break;

        swap( arr[i] , arr[j] );
        i ++;
        j --;
    }
    #endif

    int gt = j + 1;
//  写法3
    #if 1
    gt = r + 1; // arr[gt...r] > v
    int i = l+1;    // arr[lt+1...i) == v
    while( i < gt ){
        if( arr[i] < tem ){
            std::swap( arr[i], arr[j+1]);
            i ++;
            j ++;
        }
        else if( arr[i] > tem ){
            std::swap( arr[i], arr[gt-1]);
            gt --;
        }
        else{ // arr[i] == v
            i ++;
        }
    }
    #endif


    std::swap(arr[l], arr[j]);
    int *result = new int[2];
    result[0] = j;
    result[1] = gt;
    return result;
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
    int *p = partition(arr, l, r);
    quickSorting(arr, l, p[0] - 1);
    quickSorting(arr, p[1], r);
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

/**
 * 依次将data里的值进行比较，各子节点和其父节点比较，如果子节点大于父节点
 * 则进行交换
 * @tparam T
 * @param x
 */
template <typename T>
void SortingAlg<T>::shiftUp(int x) {
    while (x > 0 && data[x] > data[(x - 1)/2]) {
        std::swap(data[x], data[(x - 1)/2]);
        x = (x - 1)/2;
    }
}

/**
 * 从上往下比较x处父节点和其子节点大小，如果有子节点的值大于父节点
 * 则进行交换
 * @tparam T
 * @param x
 */
template <typename T>
void SortingAlg<T>::shiftDown(int x) {
    while (2 * x + 1 <= count) {
        int j = 2 * x + 1;
        if(j + 1 <= count && data[j] < data[j + 1])
            j++;
        if (data[x] >= data[j])
            break;
        std::swap(data[x], data[j]);
        x = j;
    }
}

/**
 * 从上往下比较x处父节点和其子节点大小，如果有子节点的值大于父节点
 * 则进行交换
 * @tparam T
 * @param x
 */
template <typename T>
void SortingAlg<T>::shiftDown(T arr[], int i, int n) {
    while (2 * i + 1 < n) {
        int j = 2 * i + 1;
        if(j + 1 < n && arr[j] < arr[j + 1])
            j++;
        if (arr[i] >= arr[j])
            break;
        std::swap(arr[i], arr[j]);
        i = j;
    }
}

/**
 * 输入数据
 * @tparam T
 * @param item
 */
template <typename T>
void SortingAlg<T>::buildHeap(T item) {
    if (count + 1 >= container) {
        container = container * 2;
        T *newData = new T[container];
        for (int i = 0; i <= count; i++) {
            newData[i] = data[i];
        }
        data = newData;
    }

    data[count] = item;
    shiftUp(count);
    count++;
}

/**
 * 取出堆中最大值并重构最大堆
 * @tparam T
 * @return
 */
template <typename T>
T SortingAlg<T>::getMaxData() {
    assert( count >= 0 );
    T res = data[0];

    std::swap(data[0], data[count]);
    count--;
    shiftDown(0);

    return res;
}

template <typename T>
void SortingAlg<T>::heapSorting(T arr[], int n) {
#if 0
    for (int i = 0; i < n; ++i) {
        buildHeap(arr[i]);
    }
    count--;
#endif

#if 0
    for (int j = n - 1; j >= 0; j--){
        arr[j] = getMaxData();
    }
#endif
#if 1
    for( int i = (n-1)/2 ; i >= 0 ; i-- )
        shiftDown(arr, i, n);

    for( int i = n-1; i > 0 ; i-- ){
        std::swap( arr[0] , arr[i] );
        shiftDown(arr, 0, i);
    }
#endif
}


#endif //SORTING_ALG_SORTINGALG_H
