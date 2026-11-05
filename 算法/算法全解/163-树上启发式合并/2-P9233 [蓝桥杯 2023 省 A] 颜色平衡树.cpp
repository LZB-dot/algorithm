
//https://www.luogu.com.cn/problem/P9233

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring> 
#include<queue>
#include<unordered_map>
#include<climits>
#include<bitset>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
int cnt = 1;

int n;
int arr[MAXN];

int fa[MAXN], sz[MAXN];
int son[MAXN];

int ans = 0;

int colorCnt[MAXN];
int colorNum[MAXN];

inline void add(int u, int v) {
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt++;
}

void dfs1(int u) {

	sz[u] = 1;

	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];

		dfs1(v);
		sz[u] += sz[v];

		if (son[u] == 0 || sz[son[u]] < sz[v])
			son[u] = v;

	}
}

void effect(int u) {
	colorNum[colorCnt[arr[u]]]--;
	colorCnt[arr[u]]++;
	colorNum[colorCnt[arr[u]]]++;

	for (int i = head[u]; i; i = nxt[i])
		effect(to[i]);
}

void cancel(int u) {
	colorNum[colorCnt[arr[u]]]--;
	colorCnt[arr[u]]--;
	colorNum[colorCnt[arr[u]]]++;

	for (int i = head[u]; i; i = nxt[i])
		cancel(to[i]);
}

void dfs2(int u, int keep) {

	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];

		if (v != son[u])
			dfs2(v, 0);
	}

	if (son[u] != 0)
		dfs2(son[u], 1);

	colorNum[colorCnt[arr[u]]]--;
	colorCnt[arr[u]]++;
	colorNum[colorCnt[arr[u]]]++;

	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];

		if (v != son[u])
			effect(v);
	}

	if (colorCnt[arr[u]] * colorNum[colorCnt[arr[u]]] == sz[u])
		++ans;

	if (keep == 0)
		cancel(u);
}

void solve() {
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		int f;
		cin >> f;

		if (i != 1)
			add(f, i);
	}

	dfs1(1);
	dfs2(1, 1);

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}