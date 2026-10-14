//#include<iostream>
//#include<cstring> 
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 2050;
////1:d[i][j]
////2:d[i][j]*i
////3:d[i][j]*j
////4:d[i][j]*i*j
//ll tree1[MAXN][MAXN], tree2[MAXN][MAXN], tree3[MAXN][MAXN], tree4[MAXN][MAXN];
//int n, m;
//char x;
//
//inline int lowbit(int i) {
//    return i & -i;
//}
//
//inline void add(int x, int y, ll v) {
//    ll v1 = v;
//    ll v2 = 1LL * v * x; 
//    ll v3 = 1LL * v * y;
//    ll v4 = 1LL * v * x * y;
//    for (int i = x; i <= n; i += lowbit(i)) {
//        for (int j = y; j <= m; j += lowbit(j)) {
//            tree1[i][j] += v1;
//            tree2[i][j] += v2;
//            tree3[i][j] += v3;
//            tree4[i][j] += v4;
//        }
//    }
//}
//
//
////sum(a,b--c,d)
////==sum(1,1--c,d)-sum(1,1--c,b-1)-sum(1,1--a-1,d)+sum(1,1--a-1,b-1)
////sum(1,1--n,m)
////i:1-n  j:1-m  sum(a[i][j])
////差分从i,j从1,1加到该位即为该位的值
////a[x][y]=sum(i:1-x,j:1-y,d[i][j])
////化为每个差分的次数对于该点
////sum(1,1--n,m)==sum(i:1-n,j:1-m,d[i][j]*(n-i+1)*(m-j+1))
////			   ==sum(i:1-n,j:1-m,d[i][j]*[(n+1)(m+1)-(m+1)i-(n+1)j+ij]
//
//inline ll sum(int x, int y) {
//    ll ans = 0;
//    for (int i = x; i > 0; i -= lowbit(i)) {
//        for (int j = y; j > 0; j -= lowbit(j)) {
//            ans += 1LL * (x + 1) * (y + 1) * tree1[i][j];
//            ans -= 1LL * (y + 1) * tree2[i][j];
//            ans -= 1LL * (x + 1) * tree3[i][j];
//            ans += tree4[i][j];
//        }
//    }
//    return ans;
//}
//
//inline void addRange(int a, int b, int c, int d, ll v) {
//    add(a, b, v);
//    add(c + 1, b, -v);
//    add(a, d + 1, -v);
//    add(c + 1, d + 1, v);
//}
//
//inline ll sumRange(int a, int b, int c, int d) {
//    return sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a - 1, b - 1);
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    char t;
//    int a, b, c, d;
//    ll val;
//
//    cin >> x >> n >> m;
//
//    while (cin >> t) {
//        if (t == 'X') {
//            cin >> n >> m;
//            memset(tree1, 0, sizeof(tree1));
//            memset(tree2, 0, sizeof(tree2));
//            memset(tree3, 0, sizeof(tree3));
//            memset(tree4, 0, sizeof(tree4));
//        }
//        else if (t == 'L') {
//            cin >> a >> b >> c >> d >> val;
//            addRange(a, b, c, d, val);
//        }
//        else {
//            cin >> a >> b >> c >> d;
//            cout << sumRange(a, b, c, d) << "\n";
//        }
//    }
//
//    return 0;
//}
