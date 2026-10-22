//
//
//// https://www.luogu.com.cn/problem/B3609
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1e4 + 10;
//const int MAXM = 1e5 + 10;
//
//int head[MAXN], to[MAXM], nxt[MAXM];
//int cnt; 
//
//inline void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//int n, m;
//
//int dfn[MAXN];   //时间戳
//int low[MAXN];   //u能回溯到栈内最小dfn
//int cntd;        //dfn计数器
//
//int sta[MAXN]; 
//int top;
//
//int belong[MAXN];//u属于第几个scc
//int sccArr[MAXN];//平铺存储所有scc点
//int sccl[MAXN];  //第i个scc在sccArr左边界
//int sccr[MAXN];  //第i个scc在sccArr右边界
//int idx;         //sccArr写入指针
//int sccCnt;      //scc总个数
//
//bool pri[MAXN];  //标记该scc是否已经输出
//
//void tarjan(int u) {
//	//初次访问 打上时间戳
//	dfn[u] = low[u] = ++cntd;
//	//当前节点压入栈
//	sta[++top] = u;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		//树边
//		if (dfn[v] == 0) {
//			tarjan(v);
//			low[u] = min(low[u], low[v]);
//		}
//		//回边
//		else {
//			// v已经访问且还在栈中，用dfn[v]更新low
//			if (belong[v] == 0)
//				low[u] = min(low[u], dfn[v]);
//		}
//	}
//
//	// 找到scc根节点
//	if (dfn[u] == low[u]) {
//		sccCnt++;
//		sccl[sccCnt] = idx + 1;
//		int pop;
//		do {
//			pop = sta[top--];
//			belong[pop] = sccCnt;
//			sccArr[++idx] = pop;
//		} while (pop != u);
//
//		sccr[sccCnt] = idx;
//	}
//}
//
//void solve() {
//	memset(head, 0, sizeof(head));
//	memset(dfn, 0, sizeof(dfn));
//	memset(low, 0, sizeof(low));
//	memset(belong, 0, sizeof(belong));
//	memset(pri, 0, sizeof(pri));
//	
//	cnt = 1;
//	cntd = 0;
//	top = 0;
//	idx = 0;
//	sccCnt = 0;
//
//	cin >> n >> m;
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		if (dfn[i] == 0)
//			tarjan(i);
//	}
//
//	cout << sccCnt << "\n";
//
//	// 每个scc内部从小到大排序
//	for (int i = 1; i <= sccCnt; ++i)
//		sort(sccArr + sccl[i], sccArr + sccr[i] + 1);
//
//	for (int i = 1; i <= n; ++i) {
//		int scc = belong[i];
//		if (!pri[scc]) {
//			pri[scc] = 1;
//			for (int j = sccl[scc]; j <= sccr[scc]; ++j)
//				cout << sccArr[j] << " ";
//			cout << "\n";
//		}
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