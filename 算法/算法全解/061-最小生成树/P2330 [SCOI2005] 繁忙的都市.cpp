//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//struct UnionFind {
//private:
//	vector<int>father;
//	vector<int>rank;
//public:
//	void build(int n) {
//		father.resize(n + 1);
//		rank.resize(n + 1);
//		for (int i = 0; i < n; ++i) {
//			father[i] = i;
//			rank[i] = 1;
//		}
//	}
//
//	int find(int x) {
//		if (x != father[x]) {
//			father[x] = find(father[x]);
//		}
//		return father[x];
//	}
//
//	bool unite(int x, int y) {
//		int fx = find(x);
//		int fy = find(y);
//		if (fx == fy) {
//			return false;
//		}
//		if (rank[fx] < rank[fy]) {
//			father[fx] = fy;
//		}
//		else {
//			father[fy] = fx;
//			if (rank[fx] == rank[fy]) {
//				rank[fx]++;
//			}
//		}
//		return true;
//	}
//};
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>edges(m, vector<int>(3));
//	for (int i = 0; i < m; ++i) {
//		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
//	}
//
//	sort(edges.begin(), edges.end(),
//		[&](const vector<int>& a, const vector<int>& b) {
//			return a[2] < b[2];
//		});
//
//	UnionFind uf;
//	int max_edge = 0;
//	int cnt = 0;
//	uf.build(n);
//	for (auto& edge : edges) {
//		int u = edge[0];
//		int v = edge[1];
//		int w = edge[2];
//		if (uf.unite(u, v)) {
//			cnt++;
//			max_edge = max(max_edge, w);
//		}
//		if (cnt == n - 1) {
//			break;
//		}
//	}
//
//	cout << (n - 1) << " " << max_edge << endl;
//	return 0;
//
//}