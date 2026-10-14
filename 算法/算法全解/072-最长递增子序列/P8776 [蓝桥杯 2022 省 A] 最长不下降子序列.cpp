////#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//const int N = 1e5 + 10;
//int arr[N];
//int rightArr[N];
//int n, k;
//
//// 二分函数现在需要接收数组指针
//int bs1(int len, int num, int ends[]) {
//    int l = 0, r = len - 1, m, ans = -1;
//    while (l <= r) {
//        m = (l + r) / 2;
//        if (ends[m] < num) {
//            ans = m;
//            r = m - 1;
//        }
//        else {
//            l = m + 1;
//        }
//    }
//    return ans;
//}
//
//void generateRight() {
//    int ends[N]; // 局部数组
//    int len = 0;
//    for (int i = n - 1; i >= 0; i--) {
//        int find = bs1(len, arr[i], ends); // 传递给二分函数
//        if (find == -1) {
//            ends[len++] = arr[i];
//            rightArr[i] = len;
//        }
//        else {
//            ends[find] = arr[i];
//            rightArr[i] = find + 1;
//        }
//    }
//}
//
//// 二分函数现在需要接收数组指针
//int bs2(int len, int num, int ends[]) {
//    int l = 0, r = len - 1, m, ans = -1;
//    while (l <= r) {
//        m = (l + r) / 2;
//        if (ends[m] > num) {
//            ans = m;
//            r = m - 1;
//        }
//        else {
//            l = m + 1;
//        }
//    }
//    return ans;
//}
//
//int compute() {
//    generateRight();
//    int ends[N]; // 局部数组
//    int len = 0;
//    int ans = 0;
//    for (int i = 0, j = k; j < n; i++, j++) {
//        int find = bs2(len, arr[j], ends); // 传递给二分函数
//        int left = (find == -1) ? len : find;
//        ans = max(ans, left + k + rightArr[j]);
//
//        find = bs2(len, arr[i], ends); // 传递给二分函数
//        if (find == -1) {
//            ends[len++] = arr[i];
//        }
//        else {
//            ends[find] = arr[i];
//        }
//    }
//    ans = max(ans, len + k);
//    return ans;
//}
//
//int main() {
//    cin >> n >> k;
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//    cout << compute() << endl;
//    return 0;
//}