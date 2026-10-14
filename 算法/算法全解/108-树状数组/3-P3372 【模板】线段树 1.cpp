////
////// 树状数组范围增加、范围查询模版
////
////#include<iostream>
////#include<vector>
////using namespace std;
////
////typedef long long ll;
////
////const int MAXN = 1e5 + 10;
////ll tree1[MAXN], tree2[MAXN];
//////tree1：正常差分
//////tree2：(i-1)*di
////int n, m;
////
////inline int lowbit(int i) {
////	return i & -i;
////}
////
////inline void add(ll tree[], int i, ll v) {
////	while (i <= n) {
////		tree[i] += v;
////		i += lowbit(i);
////	}
////}
////
////inline ll sum(ll tree[], int i) {
////	ll ans = 0;
////	while (i > 0) {
////		ans += tree[i];
////		i -= lowbit(i);
////	}
////	return ans;
////}
////
////inline void addRange(int l, int r, ll v) {
////	add(tree1, l, v);
////	add(tree1, r + 1, -v);
////
////	add(tree2, l, 1LL * (l - 1) * v);
////	//-(r+1-1)
////	add(tree2, r + 1, -(1LL * r * v));
////}
////
//////[1,k]sum=A1	+	A2	+...+	Ak
//////		  =d1	+d1+d2	+...+d1+d2+...+dk
//////		  =k*(d1+d2+...+dk)-( (1-1)d1+(2-1)d2+...+(k-1)dk )
//////		  =k*sum(tree1,k)-sum(tree2,k)
////inline ll sumRange(int l, int r) {
////	ll p1 = 1LL * sum(tree1, r) * r - sum(tree2, r);
////	ll p2 = 1LL * sum(tree1, l - 1) * (l - 1) - sum(tree2, l - 1);
////	return p1 - p2;
////}
////
////
////int main() {
////	ios::sync_with_stdio(false);
////	cin.tie(nullptr);
////
////	cin >> n >> m;
////	ll t;
////	for (int i = 1; i <= n; ++i) {
////		cin >> t;
////		addRange(i, i, t);
////	}
////
////	ll a, x, y, z;
////	for (int i = 1; i <= m; ++i) {
////		cin >> a;
////		if (a == 1) {
////			cin >> x >> y >> z;
////			addRange(x, y, z);
////		}
////		else {
////			cin >> x >> y;
////			cout << sumRange(x, y) << "\n";
////		}
////	}
////
////	return 0;
////}
////
//
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1e5 + 10;
//int n, m;
//ll t1[MAXN], t2[MAXN];
//
//inline int lowbit(ll x) {
//	return x & -x;
//}
//
//inline void add(ll i, ll x, ll tree[]) {
//	while (i <= n) {
//		tree[i] += x;
//		i += lowbit(i);
//	}
//}
//
//inline ll query(ll i, ll tree[]) {
//	ll ans = 0;
//
//	while (i > 0) {
//		ans += tree[i];
//		i -= lowbit(i);
//	}
//
//	return ans;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m;
//
//	vector<ll>a(n + 1, 0);
//	for (int i = 1; i <= n; ++i)
//		cin >> a[i];
//
//	for (int i = 1; i <= n; ++i) {
//		ll tmp = a[i] - a[i - 1];
//		add(i, tmp, t1);
//		add(i, tmp * (i - 1), t2);
//	}
//
//	while (m--) {
//		int op;
//		cin >> op;
//
//		ll x, y, k;
//		if (op == 1) {
//			cin >> x >> y >> k;
//			add(x, k, t1);
//			add(y + 1, -k, t1);
//
//			add(x, k * (x - 1), t2);
//			add(y + 1, -k * y, t2);
//		}
//		else {
//			cin >> x >> y;
//			ll sum1 = query(y, t1) * y - query(y, t2);
//			ll sum2 = query(x - 1, t1) * (x - 1) - query(x - 1, t2);
//			cout << sum1 - sum2 << "\n";
//		}
//	}
//
//	return 0;
//}