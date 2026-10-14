//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//const int N = 1e3 + 10;
//
//int n, m;
//int father[N];
//int size_[N];
//
//struct Road {
//	int x, y, t;
//	bool operator<(const Road& other) const {
//		return t < other.t;
//	}
//};
//
//void Init() {
//	for (int i = 1; i <= n; ++i) {
//		father[i] = i;
//		size_[i] = 1;
//	}
//}
//
//int Find(int a) {
//	int root = a;
//	while (root != father[root]) {
//		root = father[root];
//	}
//
//	while (a != root) {
//		int tmp = father[a];
//		father[a] = root;
//		a = tmp;
//	}
//
//	return root;
//}
//
//void Union(int a, int b) {
//	int fa = Find(a);
//	int fb = Find(b);
//
//	if (fa != fb) {
//		if (size_[fa] >= size_[fb]) {
//			size_[fa] += size_[fb];
//			father[fb] = fa;
//		}
//		else {
//			size_[fb] += size_[fa];
//			father[fa] = fb;
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m;
//	vector<Road>v(m);
//	Init();
//	for (int i = 0; i < m; ++i) {
//		cin >> v[i].x >> v[i].y >> v[i].t;
//	}
//	sort(v.begin(), v.end());
//
//	int ans = -1;
//	for (const auto& road : v) {
//		Union(road.x, road.y);
//		int root = Find(1);
//		if (size_[root] == n) {
//			ans = road.t;
//			break;
//		}
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}
//

