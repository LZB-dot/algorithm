//
////https://www.luogu.com.cn/problem/P8435
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring> 
//#include<queue>
//#include<unordered_map>
//#include<climits>
//#include<bitset>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 5e5 + 10;
//const int MAXM = 2e6 + 10;
//
//int n, m;
//
//int head[MAXN], to[MAXM << 1], nxt[MAXM << 1];
//int cnt = 1;
//
//int dfn[MAXN], low[MAXN];
//int cntd = 0;
//
//int sta[MAXN];
//int top = 0;
//
//int vbccSize[MAXN];
//int vbccArr[MAXN << 1];
//int vbccl[MAXN], vbccr[MAXN];
//int idx = 0;
//int vbccCnt = 0;
//
//inline void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void tarjan(int u) {
//	dfn[u] = low[u] = ++cntd;
//	sta[top++] = u;
//
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (dfn[v] == 0) {
//			tarjan(v);
//
//			low[u] = min(low[u], low[v]);
//
//			if (low[v] >= dfn[u]) {
//				vbccCnt++;
//				vbccSize[vbccCnt] = 1;
//				vbccArr[++idx] = u;
//				vbccl[vbccCnt] = idx;
//
//				int pop;
//				do {
//					pop = sta[--top];
//					vbccSize[vbccCnt]++;
//					vbccArr[++idx] = pop;
//				} while (pop != v);
//
//				vbccr[vbccCnt] = idx;
//			}
//		}
//		else
//			low[u] = min(low[u], dfn[v]);
//	}
//}
//
//void solve() {
//	cin >> n >> m;
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//
//		if (u != v) {
//			add(u, v);
//			add(v, u);
//		}
//
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		if (dfn[i] == 0) {
//			if (head[i] == 0) {
//				vbccCnt++;
//				vbccSize[vbccCnt] = 1;
//				vbccArr[++idx] = i;
//				vbccl[vbccCnt] = vbccr[vbccCnt] = idx;
//			}
//			else
//				tarjan(i);
//		}
//
//	}
//
//	cout << vbccCnt << "\n";
//	for (int i = 1; i <= vbccCnt; i++) {
//
//		cout << vbccSize[i] << " ";
//
//		for (int j = vbccl[i]; j <= vbccr[i]; j++) 
//			cout << vbccArr[j] << " ";
//		
//		cout << "\n";
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	solve();
//
//	return 0;
//}