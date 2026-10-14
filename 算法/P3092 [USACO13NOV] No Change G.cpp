//
//////内存超限
//
////#include<iostream>
////#include<vector>
////#include<algorithm>
////using namespace std;
////
////typedef long long ll;
////
////ll n, k;
////vector<vector<ll>> memo;
////vector<ll> pre;
////vector<ll> coins;
////const ll INF = 1e18;
////
////ll dfs(ll status, ll idx) {
////    if (memo[status][idx] != -1) {
////        return memo[status][idx];
////    }
////
////    if (idx == n) {
////        return memo[status][idx] = 0;
////    }
////
////    if (status == (1 << k) - 1) {
////        return memo[status][idx] = INF;
////    }
////
////    ll total = INF;
////
////    // 遍历所有未使用的硬币
////    for (int i = 0; i < k; ++i) {
////        if (status & (1 << i))
////            continue;
////
////        ll target = pre[idx] + coins[i];
////        ll best = idx;
////
////        // 二分查找能覆盖到的最远位置
////        int left = idx, right = n;
////        while (left <= right) {
////            int mid = left + ((right - left) >> 1);
////            if (pre[mid] <= target) {
////                best = mid;
////                left = mid + 1;
////            }
////            else {
////                right = mid - 1;
////            }
////        }
////
////        // 递归计算子状态
////        ll sub_cost = dfs(status | (1 << i), best);
////        if (sub_cost != INF) {
////            total = min(total, sub_cost + coins[i]);
////        }
////    }
////
////    memo[status][idx] = total;
////    return total;
////}
////
////int main() {
////    ios::sync_with_stdio(false);
////    cin.tie(nullptr);
////
////    cin >> k >> n;
////
////    memo.resize(1 << k, vector<ll>(n + 1, -1));
////    pre.resize(n + 1, 0);
////    coins.resize(k, 0);
////
////    ll sum = 0;
////    for (ll i = 0; i < k; ++i) {
////        cin >> coins[i];
////        sum += coins[i];
////    }
////    for (ll i = 1; i <= n; ++i) {
////        cin >> pre[i];
////        pre[i] += pre[i - 1];
////    }
////
////    ll ans = dfs(0, 0);
////
////    if (ans == INF || sum < ans) {
////        cout << -1 << endl;
////    }
////    else {
////        cout << sum - ans << endl;
////    }
////    return 0;
////}
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//
//int n, k;
//vector<int> memo;  
//vector<ll> pre;  
//vector<ll> coins;  
//
//int find(int l, int r, ll s) {
//    ll now = pre[l];
//    int ret = l;
//    while (l <= r) {
//        int mid = l + ((r - l) >> 1);  
//        if (pre[mid] - now <= s) {
//            ret = mid;
//            l = mid + 1;
//        }
//        else {
//            r = mid - 1;
//        }
//    }
//    return ret;
//}
//
//ll cal(int s) {
//    ll ans = 0;
//    for (int i = 0; i < k; ++i) {
//        if (!(s & (1 << i)))
//            ans += coins[i];
//    }
//    return ans;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> k >> n;
//
//    memo.resize(1 << k, 0);
//    pre.resize(n + 1, 0);
//    coins.resize(k, 0);
//
//    ll total = 0;
//
//    for (int i = 0; i < k; ++i) {
//        cin >> coins[i];
//        total += coins[i];
//
//    }
//    for (int i = 1; i <= n; ++i) {
//        cin >> pre[i];
//        pre[i] += pre[i - 1];
//    }
//
//    for (int i = 0; i < (1 << k); ++i) {
//        for (int j = 0; j < k; ++j) {
//            if ((i >> j) & 1)
//                continue;
//
//            int new_state = i | (1 << j);
//            memo[new_state] = max(memo[new_state], find(memo[i], n, coins[j]));
//        }
//    }
//
//    bool flag = false;
//    ll ans = -1;
//    for (int i = 0; i < (1 << k); ++i) {
//        if (memo[i] == n) {
//            flag = true;
//            ll tmp = cal(i);
//            ans = max(ans, tmp);
//        }
//    }
//
//    cout << (flag ? ans : -1) << endl;
//    return 0;
//}
