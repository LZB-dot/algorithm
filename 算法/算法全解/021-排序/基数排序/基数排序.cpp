//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//#pragma GCC optimize(3)
//
//const int BASE = 10; // 十进制基数
//
//// 基数排序核心函数（仅处理非负整数）
//void radixSort(int arr[], int n) {
//    if (n <= 1) return; // 空数组或单元素数组无需排序
//
//    // 步骤1：找到最大值，确定需要处理的位数
//    int maxVal = *max_element(arr, arr + n);
//    int bits = 0;
//    if (maxVal == 0) {
//        bits = 1; // 单独处理最大值为0的情况，确保至少处理1位
//    }
//    else {
//        while (maxVal > 0) {
//            bits++;
//            maxVal /= BASE;
//        }
//    }
//
//    vector<int> cnts(BASE, 0); // 计数数组，统计当前位数字出现次数
//    vector<int> help(n);       // 辅助数组，存储排序结果
//
//    // 按位处理：从个位到最高位
//    for (int offset = 1, bit = 1; bit <= bits; offset *= BASE, bit++) {
//        // 1. 重置计数数组
//        fill(cnts.begin(), cnts.end(), 0);
//
//        // 2. 统计当前位的数字出现次数
//        for (int i = 0; i < n; i++) {
//            int digit = (arr[i] / offset) % BASE;
//            cnts[digit]++;
//        }
//
//        // 3. 计算前缀和，确定每个数字在help中的位置（保证稳定性）
//        for (int i = 1; i < BASE; i++) {
//            cnts[i] += cnts[i - 1];
//        }
//
//        // 4. 倒序遍历原数组，将元素放入help的正确位置（保证稳定性）
//        for (int i = n - 1; i >= 0; i--) {
//            int digit = (arr[i] / offset) % BASE;
//            help[--cnts[digit]] = arr[i];
//        }
//
//        // 5. 将排序结果写回原数组
//        for (int i = 0; i < n; i++) {
//            arr[i] = help[i];
//        }
//    }
//}
//
//int main() {
//    // 测试用例1：常规非负整数
//    int arr1[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
//    int n1 = sizeof(arr1) / sizeof(arr1[0]);
//    radixSort(arr1, n1);
//    cout << "排序结果（常规非负整数）：";
//    for (int i = 0; i < n1; i++) {
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
//
//    // 测试用例2：含0的数组
//    int arr2[] = { 0, 5, 0, 3, 0, 8 };
//    int n2 = sizeof(arr2) / sizeof(arr2[0]);
//    radixSort(arr2, n2);
//    cout << "排序结果（含0）：";
//    for (int i = 0; i < n2; i++) {
//        cout << arr2[i] << " ";
//    }
//    cout << endl;
//
//    // 测试用例3：单元素数组
//    int arr3[] = { 42 };
//    int n3 = sizeof(arr3) / sizeof(arr3[0]);
//    radixSort(arr3, n3);
//    cout << "排序结果（单元素）：";
//    for (int i = 0; i < n3; i++) {
//        cout << arr3[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
