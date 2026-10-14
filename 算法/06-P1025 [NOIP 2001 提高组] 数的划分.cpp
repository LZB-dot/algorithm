//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//const int N = 205;
//const int M = 7;
//int n, k;
//int dp[N][N][M];
//
//int dfs(int remain, int pre, int cnt) {
//    if (cnt == k) {
//        return remain == 0 ? 1 : 0;
//    }
//    if (remain == 0) {
//        return 0;
//    }
//
//    if (dp[remain][pre][cnt] != -1) {
//        return dp[remain][pre][cnt];
//    }
//
//    int ans = 0;
//    for (int i = pre; i <= remain; ++i) {
//        // 确保剩下的数还能继续分（至少每个都是i）
//        if (i * (k - cnt) > remain) 
//            break;
//        ans += dfs(remain - i, i, cnt + 1);
//    }
//
//    dp[remain][pre][cnt] = ans;
//    return ans;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> k;
//    memset(dp, -1, sizeof(dp));
//    cout << dfs(n, 1, 0) << "\n";
//
//    return 0;
//}