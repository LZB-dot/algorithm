//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 1005;
//int pl[MAXN], pr[MAXN];
//vector<int>pos;
//
//int poster[MAXN << 4];
//bool vis[MAXN << 2];
//
//void down(int i) {
//	if (poster[i]) {
//		poster[i << 1] = poster[i];
//		poster[i << 1 | 1] = poster[i];
//		poster[i] = 0;
//	}
//}
//
//void update(int jobl, int jobr, int jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr) {
//		poster[i] = jobv;
//		return;
//	}
//	down(i);
//	int mid = l + ((r - l) >> 1);
//	if (jobl <= mid)
//		update(jobl, jobr, jobv, l, mid, i << 1);
//	if (jobr > mid)
//		update(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//}
//
//int query(int jobl, int jobr, int l, int r, int i) {
//	if (l == r) {
//		if (poster[i] && !vis[poster[i]]) {
//			vis[poster[i]] = true;
//			return 1;
//		}
//		return 0;
//	}
//
//	down(i);
//	int mid = l + ((r - l) >> 1);
//	int ans = 0;
//
//	if (jobl <= mid)
//		ans += query(jobl, jobr, l, mid, i << 1);
//	if (jobr > mid)
//		ans += query(jobl, jobr, mid + 1, r, i << 1 | 1);
//
//	return ans;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, m;
//	cin >> n >> m;
//	pos.clear();
//
//
//	pos.push_back(n);  
//
//	for (int i = 0; i < m; ++i) {
//		cin >> pl[i] >> pr[i];
//		pos.push_back(pl[i]);
//		pos.push_back(pr[i]);
//	}
//
//	sort(pos.begin(), pos.end());
//	pos.erase(unique(pos.begin(), pos.end()), pos.end());
//
//	vector<int>tmp;
//	for (int i = 0; i < pos.size(); ++i) {
//		tmp.push_back(pos[i]);
//		if (i + 1 < pos.size() && pos[i] + 1 < pos[i + 1])
//			tmp.push_back(pos[i] + 1);
//	}
//	pos = tmp;
//	int sz = pos.size();
//
//	memset(poster, 0, sizeof(poster));
//	memset(vis, 0, sizeof(vis));
//
//	for (int i = 0; i < m; ++i) {
//		int l = lower_bound(pos.begin(), pos.end(), pl[i]) - pos.begin() + 1;
//		int r = lower_bound(pos.begin(), pos.end(), pr[i]) - pos.begin() + 1;
//		update(l, r, i + 1, 1, sz, 1);
//	}
//
//	cout << query(1, lower_bound(pos.begin(), pos.end(), n) - pos.begin() + 1, 1, sz, 1) << "\n";
//	return 0;
//}