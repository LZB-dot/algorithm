//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 4e5 + 10;  
//
//vector<vector<int>> lines(MAXN);
//int stjump[MAXN][20];
//int power = 0;
//int n, m;
//int ans[MAXN];
//
//int jump(int i) {
//    int tar = lines[i][0] + m;
//    int cur = i;
//    int res = 0;    
//    int nxt;
//
//    for (int p = power; p >= 0; --p) {
//        nxt = stjump[cur][p];
//        if (nxt != 0 && lines[nxt][1] < tar) {
//            res += (1 << p);
//            cur = nxt;
//        }
//    }
//
//    return res + 2; // +1自己 +1最后一步
//}
//
//int mylog2(int n) {
//    int ans = 0;
//    while ((1 << ans) <= (n >> 1))
//        ++ans;
//    return ans;
//}
//
//void compute() {
//    power = mylog2(n);  
//    for (int i = 1; i <= n; ++i)
//        ans[lines[i][2]] = jump(i);
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> m;
//
//    for (int i = 1; i <= n; ++i) {
//        int l, r;
//        cin >> l >> r;
//        if (r < l) r += m;
//        lines[i] = { l, r, i };
//    }
//
//    sort(lines.begin() + 1, lines.begin() + 1 + n, [](const vector<int>& a, const vector<int>& b) {
//        return a[0] < b[0];
//        });
//
//    for (int i = 1; i <= n; ++i) {
//        int l = lines[i][0] + m;
//        int r = lines[i][1] + m;
//        lines[i + n] = { l, r, lines[i][2] };
//    }
//
//    int total = n << 1;
//    int arrive = 1;
//
//    for (int i = 1; i <= total; ++i) {
//        while (arrive + 1 <= total && lines[arrive + 1][0] <= lines[i][1])
//            arrive++;
//        stjump[i][0] = arrive;
//    }
//
//    for (int j = 1; j < 20; ++j)
//        for (int i = 1; i <= total; ++i)
//            stjump[i][j] = stjump[stjump[i][j - 1]][j - 1];
//
//    compute();
//
//    for (int i = 1; i <= n; ++i)
//        cout << ans[i] << " ";
//    cout << "\n";
//
//    return 0;
//}