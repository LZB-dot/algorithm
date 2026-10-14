////堆（heap）是一棵完全二叉树
//
////大根堆：任意节点均>=它的左右孩子节点
////小根堆：任意节点均<=它的左右孩子节点
//
// //i的父亲节点(i-1)/2
// //i的左孩子2*i+1
// //i的右孩子2*i+2
//
////大根堆
//
//#include<iostream>
//using namespace std;
//
//#pragma GCC optimize(3)
//
//class Solution {
//public:
//    // 向大根堆中插入元素，并向上调整以维持堆性质
//    void heapInsert(int arr[], int i)
//    {
//        // 当当前元素大于其父节点时，交换并继续向上比较
//        while (arr[i] > arr[(i - 1) / 2])
//        {
//            swap(arr[i], arr[(i - 1) / 2]);
//            i = (i - 1) / 2;  // 移动到父节点位置
//        }
//    }
//
//    // 当i位置的元素值变小时，向下调整以维持大根堆性质
//    void heapify(int arr[], int i, int size)
//    {
//        int l = 2 * i + 1;  // 左孩子索引
//        int r = 2 * i + 2;  // 右孩子索引
//
//        while (l < size)  // 当左孩子存在时
//        {
//            // 找到左右孩子中的最大值索引
//            int largest = (r < size && arr[r] > arr[l]) ? r : l;
//
//            // 如果父节点大于等于最大值，则无需继续调整
//            if (arr[i] >= arr[largest])
//                break;
//
//            // 否则交换父节点和最大值节点
//            swap(arr[i], arr[largest]);
//
//            // 继续向下调整
//            i = largest;
//            l = 2 * i + 1;
//            r = 2 * i + 2;
//        }
//    }
//};