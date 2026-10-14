

//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//
//class Solution {
//private:
//    int head[MAXN];
//    int to[MAXN], nxt[MAXN];
//    int cnt;
//
//    int indegree[MAXN];
//
//    void init() {
//        memset(indegree, -1, sizeof(indegree));
//        memset(head, 0, sizeof(head));
//        cnt = 1;
//    }
//
//    void add(int u, int v) {
//        indegree[v]++;
//        to[cnt] = v;
//        nxt[cnt] = head[u];
//        head[u] = cnt++;
//    }
//public:
//    string alienOrder(vector<string>& words) {
//        init();
//
//        int count = 0;
//        for (const string& w : words) {
//            for (char c : w) {
//                int id = c - 'a' + 1;
//                if (indegree[id] == -1) {
//                    indegree[id] = 0;
//                    ++count;
//                }
//            }
//        }
//
//        for (int i = 0; i < words.size() - 1; ++i) {
//            string s1 = words[i];
//            string s2 = words[i + 1];
//
//            bool f = false;
//            for (int j = 0; j < min(s1.size(), s2.size()); ++j) {
//                if (s1[j] != s2[j]) {
//                    add(s1[j] - 'a' + 1, s2[j] - 'a' + 1);
//                    f = 1;
//                    break;
//                }
//            }
//
//            if (!f && s1.size() > s2.size())
//                return "";
//        }
//
//        queue<int>q;
//        for (int i = 1; i <= 26; ++i) {
//            if (indegree[i] == 0)
//                q.push(i);
//        }
//
//        string ans;
//        while (!q.empty()) {
//            int t = q.front();
//            q.pop();
//
//            ans += (char)(t - 1 + 'a');
//            for (int i = head[t]; i; i = nxt[i]) {
//                int v = to[i];
//
//                if (--indegree[v] == 0)
//                    q.push(v);
//            }
//        }
//
//        return ans.size() == count ? ans : "";
//    }
//};
