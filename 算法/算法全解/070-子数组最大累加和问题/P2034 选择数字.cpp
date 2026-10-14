//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//#define ll long long
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    int n, k;
//    cin >> n >> k;
//
//    vector<ll> nums(n + 2);  
//    vector<ll> pre(n + 2);   
//    vector<ll> dp(n + 2);   
//
//    for (int i = 1; i <= n; ++i) {
//        cin >> nums[i];
//        pre[i] = pre[i - 1] + nums[i];
//    }
//
//    for (int i = 1; i <= n + 1; ++i) { 
//        int s = max(0, i - k - 1); 
//        for (int j = s; j < i; ++j) {
//          
//            ll cur = dp[j] + (pre[i - 1] - pre[j]);
//            dp[i] = max(dp[i], cur);
//        }
//    }
//
//    cout << dp[n + 1] << "\n";
//    return 0;
//}
//
////不知道哪里错了
////#include<iostream>
////#include<vector>
////#include<algorithm>
////#include<queue>
////using namespace std;
////
////#define ll long long
////
////int main() {
////    ios::sync_with_stdio(false);
////    cin.tie(nullptr);
////
////    int n, k;
////    cin >> n >> k;
////
////    vector<ll> nums(n + 1, 0);
////    vector<ll> pre(n + 1, 0);
////    //表示前i个数字的最大和，且不超过k个连续的数字
////    vector<ll> dp(n + 1, 0);
////
////    for (int i = 1; i <= n; ++i) {
////        cin >> nums[i];
////        pre[i] = pre[i - 1] + nums[i];
////    }
////
////    deque<int>q;
////    q.push_back(0);
////    
////    for (int i = 1; i <= n; ++i) {
////
////        while (!q.empty() && q.front() < i - k)
////            q.pop_front();
////
////        int idx = q.front();
////        //选当前数
////        ll cur = pre[i] - pre[idx] + dp[idx];
////
////        dp[i] = max(dp[i - 1], cur);
////
////        ll tmp = dp[i] - pre[i];
////
////        while (!q.empty() && (dp[q.back()] - pre[q.back()]) <= tmp)
////            q.pop_back();
////
////        q.push_back(i);
////
////    }
////    
////
////    cout << dp[n] << "\n";
////
////    return 0;
////}