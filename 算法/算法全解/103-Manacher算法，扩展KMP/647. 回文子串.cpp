//#include<iostream>
//#include<vector>
//#include<cstring> 
//
//using namespace std;
//
//const int MAXN = 1005;
//int cnt[MAXN];
//
//class Solution {
//private:
//    void manacher(const string& s) {
//        memset(cnt, 0, sizeof(cnt));
//
//        string ss;
//        for (char c : s) {
//            ss += '#';
//            ss += c;
//        }
//        ss += '#';
//
//        int n = ss.size();
//        vector<int> pos(n, 0);
//        int r = 0, c = 0;
//
//        for (int i = 0; i < n; ++i) {
//            int len = r > i ? min(r - i, pos[2 * c - i]) : 1;
//
//            while (i + len < n && i - len >= 0 && ss[i + len] == ss[i - len])
//                ++len;
//
//            if (i + len > r) {
//                r = i + len;
//                c = i;
//            }
//
//            pos[i] = len;
//            int valid = len / 2;
//            for (int j = 1; j <= valid; ++j)
//                cnt[j]++;
//
//        }
//    }
//public:
//    int countSubstrings(string s) {
//        manacher(s);
//        int sum = 0;
//        for (int i = 1; i < MAXN; ++i)
//            if (cnt[i] != 0)
//                sum += cnt[i];
//
//        return sum;
//    }
//};
