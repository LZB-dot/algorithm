//#include <iostream>
//using namespace std;
//
//const int MAXN = 1e5 + 5;
//int nums[MAXN];
//int minSum[MAXN];
//int minEnd[MAXN];
//int n, k;
//
//void Init() {
//    minSum[n - 1] = nums[n - 1];
//    minEnd[n - 1] = n - 1;
//    for (int i = n - 2; i >= 0; --i) {
//        if (minSum[i + 1] < 0) {
//            minSum[i] = minSum[i + 1] + nums[i];
//            minEnd[i] = minEnd[i + 1];
//        }
//        else {
//            minSum[i] = nums[i];
//            minEnd[i] = i;
//        }
//    }
//}
//
//int compute() {
//    Init();
//
//    int ans = 0;
//    for (int i = 0, sum = 0, end = 0; i < n; ++i) {
//        while (end < n && sum + minSum[end] <= k) {
//            sum += minSum[end];
//            end = minEnd[end] + 1;
//        }
//
//        if (end > i) {
//            ans = max(ans, end - i);
//            sum -= nums[i];
//        }
//        else {
//            end = i + 1;
//        }
//    }
//    return ans;
//}
//
//int main() {
//    cin >> n >> k;
//    for (int i = 0; i < n; ++i) {
//        cin >> nums[i];
//    }
//    cout << compute() << endl;
//    return 0;
//}