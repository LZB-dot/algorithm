//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//using namespace std;
//
//const int MOD = 1e9 + 7;
//const int MAXN = 1505;
//const int MAXM = 1205;
//
//int cnt = 0;
//int tree[MAXN][10];
//bool danger[MAXN];
//
//int fail[MAXN];
//string n;
//int dp[MAXM][MAXN][2][2];
//
//void insert(const string& s) {
//    int u = 0;
//    for (char c : s) {
//        int path = c - '0';
//        if (!tree[u][path])
//            tree[u][path] = ++cnt;
//        u = tree[u][path];
//    }
//    danger[u] = true;
//}
//
//void setFail() {
//    queue<int> q;
//
//    for (int i = 0; i < 10; ++i) {
//        if (tree[0][i]) {
//            q.push(tree[0][i]);
//            fail[tree[0][i]] = 0;
//        }
//    }
//
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//
//        danger[u] |= danger[fail[u]];
//
//        for (int i = 0; i < 10; ++i) {
//            if (tree[u][i]) {
//                fail[tree[u][i]] = tree[fail[u]][i];
//                q.push(tree[u][i]);
//            }
//            else {
//                tree[u][i] = tree[fail[u]][i];
//            }
//        }
//    }
//}
//
//int dfs(int i, int j, bool free, bool has) {
//    if (danger[j])
//        return 0;
//
//    if (i == n.size())
//        return has ? 1 : 0;
//
//    if (dp[i][j][free][has] != -1)
//        return dp[i][j][free][has];
//
//    int cur = n[i] - '0';
//    int res = 0;
//
//    if (has == 0) {
//        if (free == false) {
//            res = (res + dfs(i + 1, 0, true, false)) % MOD;
//            for (int pick = 1; pick < cur; ++pick)
//                res = (res + dfs(i + 1, tree[j][pick], true, true)) % MOD;
//            res = (res + dfs(i + 1, tree[j][cur], false, true)) % MOD;
//        }
//        else {
//            res = (res + dfs(i + 1, 0, true, false)) % MOD;
//            for (int pick = 1; pick <= 9; ++pick)
//                res = (res + dfs(i + 1, tree[j][pick], true, true)) % MOD;
//        }
//    }
//    else {
//        if (free == false) {
//            for (int pick = 0; pick < cur; ++pick)
//                res = (res + dfs(i + 1, tree[j][pick], true, true)) % MOD;
//            res = (res + dfs(i + 1, tree[j][cur], false, true)) % MOD;
//        }
//        else {
//            for (int pick = 0; pick <= 9; ++pick)
//                res = (res + dfs(i + 1, tree[j][pick], true, true)) % MOD;
//        }
//    }
//
//    dp[i][j][free][has] = res;
//    return res;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n;
//    int m;
//    cin >> m;
//
//    for (int i = 0; i < m; ++i) {
//        string s;
//        cin >> s;
//        insert(s);
//    }
//
//    setFail();
//
//    memset(dp, -1, sizeof(dp));
//    cout << dfs(0, 0, false, false) << "\n";
//
//    return 0;
//}