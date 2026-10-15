//
//
////https://www.luogu.com.cn/problem/P1127
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//const int MAXM = 2e5 + 10;
//const int MAXN = 30;
//
//int n = 26;
//int m;
//string s[MAXM];
//
//int a[MAXM], b[MAXM];
//
//int head[MAXN], nxt[MAXM], to[MAXM];
//int eid[MAXM];
//string weight[MAXM];
//int cnt;
//
//int cur[MAXN], out[MAXN], in[MAXN];
//
//string path[MAXM];
//int cntp;
//
//bool cmp(int i, int j) {
//	if (a[i] != a[j])
//		return a[i] < a[j];
//
//	return s[i] < s[j];
//}
//
//void add(int u, int v, string w) {
//	to[cnt] = v;
//	weight[cnt] = w;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void connect() {
//	sort(eid + 1, eid + m + 1, cmp);
//	cnt = 1;
//
//	for (int i = 1; i <= m; ) {
//		int j = i + 1;
//		while (j <= m && a[eid[i]] == a[eid[j]])
//			++j;
//
//		for (int k = j - 1; k >= i; --k) {
//			int u = a[eid[k]];
//			int v = b[eid[k]];
//
//			out[u]++;
//			in[v]++;
//
//			add(u, v, s[eid[k]]);
//		}
//
//		i = j;
//	}
//
//	for (int i = 1; i <= n; ++i)
//		cur[i] = head[i];
//}
//
//int getS() {
//	int st = -1, ed = -1;
//
//	for (int i = 1; i <= n; ++i) {
//		int v = out[i] - in[i];
//
//		if (v < -1 || v>1 || (v == 1 && st != -1) || (v == -1 && ed != -1))
//			return -1;
//
//		if (v == 1)
//			st = i;
//
//		if (v == -1)
//			ed = i;
//
//	}
//
//	if ((st == -1) ^ (ed == -1))
//		return -1;
//
//	if (st != -1)
//		return st;
//
//	for (int i = 1; i <= n; ++i)
//		if (out[i] > 0)
//			return i;
//
//	return -1;
//}
//
//void euler(int u, string w) {
//
//	for (int i = cur[u]; i; i = cur[u]) {
//		cur[u] = nxt[i];
//		euler(to[i], weight[i]);
//	}
//
//	path[++cntp] = w;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> m;
//
//	for (int i = 1; i <= m; ++i) {
//		cin >> s[i];
//		a[i] = s[i][0] - 'a' + 1;
//		b[i] = s[i].back() - 'a' + 1;
//
//		eid[i] = i;
//	}
//
//	connect();
//
//	int start = getS();
//
//	if (start == -1)
//		cout << "***\n";
//	else {
//		euler(start, "");
//
//		if (cntp != m + 1)
//			cout << "***\n";
//		else {
//			cout << path[cntp - 1];
//			for (int i = cntp - 2; i >= 1; --i)
//				cout << "." << path[i];
//
//			cout << "\n";
//		}
//
//	}
//
//	return 0;
//}
