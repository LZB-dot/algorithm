

//https://www.luogu.com.cn/problem/P4926



#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring> 
#include<queue>
#include<unordered_map>
#include<climits>

using namespace std;

const int MAXN = 1010;
const int MAXM = 1e6 + 10;

int head[MAXN], to[MAXM], nxt[MAXM], weight[MAXM];
int cnt = 1;

inline void add(int u, int v, int w) {
	to[cnt] = v;
	nxt[cnt] = head[u];
	weight[cnt] = w;
	head[u] = cnt++;
}

void solve() {
	int n, s, t;
	cin >> n >> s >> t;


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}