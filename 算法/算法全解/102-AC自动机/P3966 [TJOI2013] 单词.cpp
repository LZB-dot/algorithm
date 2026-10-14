//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//#include<string>
//using namespace std;
//
//const int MAXN = 1e6 + 5;
//
//int trie[MAXN][26], ed[MAXN];
//int cnt = 0;
//
//int fail[MAXN], times[MAXN];
//
//int head[MAXN], nxt[MAXN], to[MAXN];
//int edge = 0;
//
//void add(int u, int v) {
//    to[edge] = v;
//    nxt[edge] = head[u];
//    head[u] = edge++;
//}
//
//void insert(int idx, const string& s) {
//    int cur = 0;
//    for (char c : s) {
//        int path = c - 'a';
//        if (!trie[cur][path])
//            trie[cur][path] = ++cnt;
//        cur = trie[cur][path];
//    }
//    ed[cur] = idx;
//}
//
//void setFail() {
//    queue<int> q;
//    for (int i = 0; i < 26; ++i) {
//        if (trie[0][i]) {
//            q.push(trie[0][i]);
//            fail[trie[0][i]] = 0;
//        }
//    }
//
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//
//        for (int i = 0; i < 26; ++i) {
//            if (trie[u][i]) {
//                fail[trie[u][i]] = trie[fail[u]][i];
//                q.push(trie[u][i]);
//            }
//            else {
//                trie[u][i] = trie[fail[u]][i];
//            }
//        }
//    }
//}
//
//void dfs(int u) {
//    for (int i = head[u]; ~i; i = nxt[i]) {
//        dfs(to[i]);
//        times[u] += times[to[i]];
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    memset(trie, 0, sizeof(trie));
//    memset(ed, 0, sizeof(ed));
//    memset(fail, 0, sizeof(fail));
//    memset(times, 0, sizeof(times));
//    memset(head, -1, sizeof(head));
//
//    int n;
//    cin >> n;
//    vector<string> words(n + 1);
//
//    for (int i = 1; i <= n; ++i) {
//        cin >> words[i];
//        insert(i, words[i]);
//    }
//
//    setFail();
//
//    for (int i = 1; i <= n; ++i) {
//        int cur = 0;
//        for (char c : words[i]) {
//            cur = trie[cur][c - 'a'];
//            times[cur]++;
//        }
//    }
//
//    for (int i = 1; i <= cnt; ++i) 
//        add(fail[i], i);
//    
//
//    dfs(0);
//
//    for (int i = 1; i <= n; ++i) {
//        int u = 0;
//        for (char c : words[i]) {
//            u = trie[u][c - 'a'];
//        }
//        cout << times[u] << "\n";
//    }
//
//    return 0;
//}