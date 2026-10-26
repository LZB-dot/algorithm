//
//
////https://leetcode.cn/problems/cracking-the-safe/description/
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
//class Solution {
//public:
//    static const int MAXN = 5010;
//
//    //m节点总数
//    int n, k, m;
//
//    int cur[MAXN];
//    int path[MAXN];
//    int cntp;
//
//    int sta[MAXN][2];
//    int u, e;
//    int top;
//
//    void push(int u, int e) {
//        sta[top][0] = u;
//        sta[top][1] = e;
//        ++top;
//    }
//
//    void pop() {
//        top--;
//        u = sta[top][0];
//        e = sta[top][1];
//    }
//
//    void prepare(int len, int num) {
//        n = len;
//        k = num;
//        m = 1;
//
//        for (int i = 1; i <= n - 1; ++i)
//            m *= k;
//
//        for (int i = 0; i < m; ++i)
//            cur[i] = 0;
//
//        cntp = 0;
//    }
//
//    //pe是上一条边
//    void euler1(int u, int pe) {
//        while (cur[u] < k) {
//            int ce = cur[u]++;
//            int cu = (u * k + ce) % m;
//            euler1(cu, ce);
//        }
//
//        path[++cntp] = pe;
//    }
//
//
//    void euler2(int u, int pe) {
//        top = 0;
//        push(u, pe);
//
//        while (top > 0) {
//
//            u = sta[top - 1][0];
//            e = sta[top - 1][1];
//
//
//            if (cur[u] < k) {
//                int ce = cur[u]++;
//                int cu = (u * k + ce) % m;
//                push(cu, ce);
//            }
//            else {
//                path[++cntp] = e;
//                top--;
//            }
//        }
//    }
//
//    string crackSafe(int n, int k) {
//        prepare(n, k);
//        euler1(0, -1);
//
//        string ans;
//
//        for (int i = 1; i <= n - 1; ++i)
//            ans.push_back('0');
//
//        for (int i = cntp - 1; i >= 1; --i)
//            ans.push_back(char('0' + path[i]));
//
//        return ans;
//    }
//};