//
////https://leetcode.cn/problems/valid-arrangement-of-pairs/description/
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1e5 + 10;
//
//
//class Solution {
//private:
//    vector<int>a;
//    int n, m;
//
//    int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//    int cnt;
//
//    int out[MAXN], in[MAXN];
//    int cur[MAXN ];
//    int path[MAXN << 1];
//    int cntp;
//
//    void init() {
//        cnt = 1;
//        memset(head, 0, sizeof(head));
//
//        cntp = 0;
//        memset(out, 0, sizeof(out));
//        memset(in, 0, sizeof(in));
//
//    }
//
//    void add(int u, int v) {
//        to[cnt] = v;
//        nxt[cnt] = head[u];
//        head[u] = cnt++;
//    }
//
//    int get(int i) {
//        return lower_bound(a.begin(), a.end(), i) - a.begin() + 1;
//    }
//
//    void connect(vector<vector<int>>& pairs) {
//        init();
//
//        int tn = pairs.size();
//
//        sort(pairs.begin(), pairs.end(), [](const vector<int>& x, const vector<int>& y) {
//            if (x[0] != y[0])
//                return x[0] < y[0];
//
//            return x[1] < y[1];
//            });
//
//        for (int l = 0; l < tn;) {
//            int r = l + 1;
//
//            while (r < tn && pairs[l][0] == pairs[r][0])
//                ++r;
//
//            for (int i = r - 1; i >= l; --i) {
//                int u = get(pairs[i][0]);
//                int v = get(pairs[i][1]);
//
//                out[u]++;
//                in[v]++;
//                add(u, v);
//            }
//
//            l = r;
//        }
//
//        for (int i = 1; i <= n; ++i)
//            cur[i] = head[i];
//    }
//
//    int getStart() {
//
//        int st = -1, ed = -1;
//
//        for (int i = 1; i <= n; ++i) {
//            int t = out[i] - in[i];
//
//            if (t > 1 || t < -1)
//                return -1;
//
//            if ((t == 1 && st != -1) || (t == -1 && ed != -1))
//                return -1;
//
//            if (t == 1)
//                st = i;
//
//            if (t == -1)
//                ed = i;
//
//        }
//
//        if ((st != -1) ^ (ed != -1))
//            return -1;
//
//        if (st != -1)
//            return st;
//
//        for (int i = 1; i <= n; ++i) {
//            if (out[i] > 0)
//                return i;
//        }
//
//        return -1;
//    }
//
//
//    void euler(int u) {
//
//        for (int i = cur[u]; i; i = cur[u]) {
//            cur[u] = nxt[i];
//            int v = to[i];
//            euler(v);
//        }
//
//        path[++cntp] = u;
//    }
//
//public:
//    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
//        for (auto& it : pairs) {
//            a.push_back(it[0]);
//            a.push_back(it[1]);
//        }
//
//        sort(a.begin(), a.end());
//        a.erase(unique(a.begin(), a.end()), a.end());
//
//        n = a.size();
//
//        init();
//        connect(pairs);
//
//        int start = getStart();
//
//        if (start == -1)
//            return {};
//        else {
//            euler(start);
//            vector<vector<int>>ans(pairs.size(), vector<int>(2));
//            int k = 0;
//
//            for (int i = cntp; i>1; --i) {
//                ans[k][0] = a[path[i] - 1];
//                ans[k][1] = a[path[i - 1] - 1];
//                ++k;
//            }
//
//            return ans;
//        }
//    }
//};