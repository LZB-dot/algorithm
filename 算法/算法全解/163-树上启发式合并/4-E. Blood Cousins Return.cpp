////https://codeforces.com/problemset/problem/246/E
//
//
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//#include<unordered_map>
//#include<unordered_set>
//#include<climits>
//#include<bitset>
//
//using namespace std;
//typedef long long ll;
//
//const int MAXN = 1e5 + 10;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//
////边v为深度k 
//int qhead[MAXN], qk[MAXN], qnxt[MAXN];
//int qid[MAXN];//第几个查询
//int kcnt = 1;   
//
//int n;
//string arr[MAXN];
//
//int dep[MAXN], sz[MAXN];
//int son[MAXN];
//
////把姓名转化为数字编号
//unordered_map<string, int> nameid;
//bool root[MAXN];
//int id[MAXN];//节点i对应的数字编号
//
//int ans[MAXN];
//vector<unordered_set<int>> depSet;//记录每一层深度的集合
//
//inline void add(int u, int v) {
//    to[cnt] = v;
//    nxt[cnt] = head[u];
//    head[u] = cnt++;
//}
//
//inline void addQ(int u, int k, int i) {
//    qnxt[kcnt] = qhead[u];
//    qk[kcnt] = k;
//    qid[kcnt] = i;
//    qhead[u] = kcnt++;
//}
//
//int getid(string name) {
//    if (nameid.find(name) != nameid.end())
//        return nameid[name];
//
//    int nid = nameid.size() + 1;
//    nameid[name] = nid;
//    return nid;
//}
//
//void dfs1(int u, int f) {
//
//    sz[u] = 1;
//    dep[u] = dep[f] + 1;
//    son[u] = 0;
//
//    for (int i = head[u]; i; i = nxt[i]) {
//        int v = to[i];
//
//        dfs1(v, u);
//        sz[u] += sz[v];
//
//        if (son[u] == 0 || sz[son[u]] <= sz[v])
//            son[u] = v;
//    }
//}
//
//void effect(int u) {
//    depSet[dep[u]].insert(id[u]);
//
//    for (int i = head[u]; i; i = nxt[i]) {
//        int v = to[i];
//        effect(v);
//    }
//}
//
//void cancel(int u) {
//    depSet[dep[u]].erase(id[u]);
//
//    for (int i = head[u]; i; i = nxt[i]) {
//        int v = to[i];
//        cancel(v);
//    }
//}
//
//void dfs2(int u, int keep) {
//    for (int i = head[u]; i; i = nxt[i]) {
//        int v = to[i];
//        if (v != son[u])
//            dfs2(v, 0);
//    }
//
//    if (son[u] != 0)
//        dfs2(son[u], 1);
//
//    depSet[dep[u]].insert(id[u]);
//
//    for (int i = head[u]; i; i = nxt[i]) {
//        int v = to[i];
//        if (v != son[u])
//            effect(v);
//    }
//
//    // 回答挂在u上的所有查询
//    for (int i = qhead[u]; i; i = qnxt[i]) {
//        int k = qk[i];
//        int nd = dep[u] + k;//实际深度
//
//        int idx = qid[i];//第几条询问
//        if (nd > n) 
//            ans[idx] = 0;
//        else 
//            ans[idx] = depSet[nd].size();
//        
//    }
//
//    if (keep == 0)
//        cancel(u);
//}
//
//void solve() {
//
//    cin >> n;
//
//    for (int i = 1; i <= n; ++i) {
//        string s;
//        int f;
//        cin >> s >> f;
//
//        arr[i] = s;
//        id[i] = getid(s);
//
//        if (f == 0) 
//            root[i] = true;
//        else 
//            add(f, i);
//        
//    }
//
//    depSet.resize(n + 2);
//
//    for (int i = 1; i <= n; i++) 
//        if (root[i]) 
//            dfs1(i, 0);
//        
//    
//
//    int m;
//    cin >> m;
//
//    for (int i = 1; i <= m; i++) {
//        int u, k;
//        cin >> u >> k;
//        addQ(u, k, i);
//    }
//
//    for (int i = 1; i <= n; i++) 
//        if (root[i]) 
//            dfs2(i, 0);
//        
//    
//    for (int i = 1; i <= m; i++)
//        cout << ans[i] << "\n";
//    
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    solve();
//
//    return 0;
//}
