//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//const int MAXN = 1e6 + 10;
//int n, m;
//vector<int>nums;
//vector<vector<int>>ask;
//vector<int>ans;
//
//int tree[MAXN];
//int late[MAXN];
//int appear[MAXN];
//
//inline int read() {
//	int num = 0;
//	char c;
//	while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
//
//	bool flag = 0;
//	if (c == '-')
//		flag = 1;
//	else
//		num = c - '0';
//
//	while (isdigit(c = getchar()))
//		num = num * 10 + c - '0';
//
//	return flag ? -num : num;
//}
//
//inline int lowbit(int i) {
//	return i & -i;
//}
//
//inline void add(int p, int v) {
//	while (p <= n) {
//		tree[p] += v;
//		p += lowbit(p);
//	}
//}
//
//inline int sum(int p) {
//	int ans = 0;
//	while (p > 0) {
//		ans += tree[p];
//		p -= lowbit(p);
//	}
//	return ans;
//}
//
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cout.tie(nullptr);
//
//	n = read();
//	nums.resize(n + 1);
//	for (int i = 1; i <= n; ++i)
//		nums[i] = read();
//	
//	m = read();
//	ans.resize(m);
//	int l, r;
//	for (int i = 0; i < m; ++i) {
//		l = read();
//		r = read();
//		ask.push_back({ l,r ,i });
//	}
//
//	sort(ask.begin(), ask.end(), [](const vector<int>& a, const vector<int>& b) {
//		return a[1] < b[1];
//		});
//
//	int idx;
//	int prer = 1;
//	for (int i = 0; i < m; ++i) {
//		l = ask[i][0];
//		r = ask[i][1];
//		idx = ask[i][2];
//
//		if (prer != r) {
//			for (int j = prer; j <= r; ++j) {
//				if (late[nums[j]] != 0) 
//					add(late[nums[j]], -1);
//
//				add(j, 1);
//				late[nums[j]] = j;
//
//			}
//			ans[idx] = sum(r) - sum(l - 1);
//			prer = r;
//		}
//		else 
//			ans[idx] = sum(r) - sum(l - 1);
//	}
//
//	for (int i : ans)
//		cout << i << "\n";
//
//	return 0;
//}