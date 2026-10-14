//#include<iostream>
//#include<vector>
//#include<climits>  // 引入INT_MAX的头文件
//using namespace std;
//
//int n, k;
//vector<int>arr;
//vector<int>dp;
//vector<int>ed;
//vector<int>ans;
//
//int bs(int len, int num) {
//    if (len == 0)
//        return -1;  // 空数组返回-1，而非0
//    int res = -1;
//    int l = 0, r = len - 1;
//    while (l <= r) {
//        int mid = l + ((r - l) >> 1);  
//        if (num >= ed[mid]) {  
//            res = mid;        
//            r = mid - 1;
//        }
//        else {
//            l = mid + 1;
//        }
//    }
//    return res;
//}
//
//int cal() {
//    int len = 0;
//    dp.resize(n);
//    ed.resize(n);
//
//    for (int i = n - 1; i >= 0; --i) {
//        int idx = bs(len, arr[i]);
//        if (idx == -1) {
//            ed[len++] = arr[i];
//            dp[i] = len;
//        }
//        else {
//            ed[idx] = arr[i];
//            dp[i] = idx + 1;
//        }
//    }
//    return len;
//}
//
//void lis() {
//    k = cal();
//    ans.resize(k, INT_MAX); 
//    for (int i = 0; i < n; ++i) {
//        if (dp[i] == k) {
//            ans[0] = arr[i];  
//        }
//        else {
//            int pos = k - dp[i]; 
//            if (pos < k && ans[pos - 1] < arr[i] && arr[i] < ans[pos]) {
//                ans[pos] = arr[i];
//            }
//        }
//    }
//}
//
//int main() {
//    cin >> n;
//    arr.resize(n);
//    for (int i = 0; i < n; ++i)
//        cin >> arr[i];
//    lis();
//    // 输出结果
//    for (int i = 0; i < k - 1; ++i)
//        cout << ans[i] << " ";
//    cout << ans[k - 1] << endl;
//    return 0;
//}