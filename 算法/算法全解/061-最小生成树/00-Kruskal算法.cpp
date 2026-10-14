//
////Kruskal算法
////按权值排序，依次选取最小的
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 100005;
//int father[MAXN];
//
//void build(int n) {
//	for (int i = 0; i < n; ++i) {
//		father[i] = i;
//	}
//}
//
//int find(int x) {
//	if (x != father[x]) {
//		father[x] = find(father[x]);
//	}
//	return father[x];
//}
//
//bool unite(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	if (fx != fy) {
//		father[fx] = fy;
//		return true;
//	}
//	return false;
//}
//
//int main() {
//	int n, m;
//	while (cin >> n >> m) {
//		build(n);
//		//起点终点权值
//		vector<vector<int>>edges(m, vector<int>(3));
//		for (int i = 0; i < m; ++i) {
//			cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
//		}
//
//		//按权值升序排列
//		sort(edges.begin(), edges.end(),
//			[&](const vector<int>& a, const vector<int>& b) {
//				return a[2] < b[2];
//			});
//
//		int ans = 0, cnt = 0;
//
//		for (const auto& edge : edges) {
//			int u = edge[0], v = edge[1], w = edge[2];
//			if (unite(u, v)) {
//				ans += w;
//				cnt++;
//				if (cnt == n - 1) {
//					break;
//				}
//			}
//		}
//
//		if (cnt == n - 1) {
//			cout << ans << endl;
//		}
//		else {
//			cout << "orz" << endl;
//		}
//	}
//}