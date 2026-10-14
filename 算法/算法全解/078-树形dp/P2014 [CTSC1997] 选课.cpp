//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<climits>
//using namespace std;
//
//const int MAXN = 310;
//int n, m;
//int nums[MAXN];          
//int head[MAXN], to[MAXN], next_[MAXN];
//int dp[MAXN][MAXN];  
//int val[MAXN], size_[MAXN];
//int edgeCnt;
//int dfnCnt;
//
//void add(int u, int v) {
//    next_[++edgeCnt] = head[u];
//    head[u] = edgeCnt;
//    to[edgeCnt] = v;
//}
//
//int dfs(int u) {
//    int dfn = ++dfnCnt;
//    val[dfn] = nums[u];
//    size_[dfn] = 1;
//
//    for (int e = head[u]; e; e = next_[e]) {
//        int v = to[e];
//        size_[dfn] += dfs(v);
//    }
//    return size_[dfn];
//}
//
//
//int compute() {
//    for (int i = n + 1; i >= 2; --i) {
//        for (int j = 1; j <= m; ++j) {
//            dp[i][j] = max(dp[i + size_[i]][j], val[i] + dp[i + 1][j - 1]);
//        }
//    }
//    return dp[2][m];
//}
//
//int main() {
//    cin >> n >> m;
//    memset(head, 0, sizeof(head));
//    memset(dp, 0, sizeof(dp));
//    edgeCnt = dfnCnt = 0;
//
//    for (int i = 1; i <= n; ++i) {
//        int pre;
//        cin >> pre >> nums[i];
//        add(pre, i);
//    }
//    nums[0] = 0;
//    dfs(0);
//    cout << compute() << endl;
//    return 0;
//}