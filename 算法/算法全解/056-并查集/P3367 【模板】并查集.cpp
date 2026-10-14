//#include<iostream>
//using namespace std;
//
//const int MAXN = 1e6 + 1;
//int father[MAXN];
//int size_[MAXN];
//int stack[MAXN];
//int n, m;
//
//void build() {
//	for (int i = 0; i < n; ++i) {
//		father[i] = i;
//		size_[i] = 1;
//	}
//}
//
//int find(int i) {
//	int sz = 0;
//	while (i != father[i]) {
//		stack[sz++] = i;
//		i = father[i];
//	}
//
//	while (sz) {
//		father[stack[--sz]] = i;
//	}
//
//	return i;
//}
//
//bool isSameSet(int x, int y) {
//	return find(x) == find(y);
//}
//
//void unionSet(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	if (fx != fy) {
//		if (size_[fx] >= size_[fy]) {
//			size_[fx] += size_[fy];
//			father[fy] = fx;
//		}
//		else {
//			size_[fy] += size_[fx];
//			father[fx] = fy;
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	cin >> n >> m;
//	build();
//	while (m--) {
//		int opt, x, y;
//		cin >> opt >> x >> y;
//		if (opt == 2) {
//			cout << (isSameSet(x, y) ? "Y" : "N") << endl;
//		}
//		else if (opt == 1) {
//			unionSet(x, y);
//		}
//	}
//	return 0;
//}