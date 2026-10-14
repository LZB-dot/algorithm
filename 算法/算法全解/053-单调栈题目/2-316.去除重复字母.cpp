//
//// https://leetcode.cn/problems/remove-duplicate-letters/
//
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//const int MAXN = 1e4 + 10;
//
//class Solution {
//private:
//    int st[MAXN];
//    int r = 0;
//public:
//    string removeDuplicateLetters(string s) {
//        vector<int>last_(27, -1);
//        vector<bool>vis(27, 0);
//
//        int n = s.size();
//
//        for (int i = 0; i < n;++i) {
//            int p = s[i] - 'a';
//            last_[p] = i;
//        }
//
//        for (int i = 0; i < n; ++i) {
//            int p = s[i] - 'a';
//            if (!vis[p]) {
//                while (r > 0 && s[st[r - 1]] > s[i] &&
//                    last_[s[st[r - 1]] - 'a'] > i) {
//                    vis[s[st[r - 1]] - 'a'] = false;
//                    --r;
//                }
//
//                st[r++] = i;
//                vis[p] = true;
//            }
//        }
//
//        string ans = "";
//        for (int j = 0; j < r; ++j) 
//            ans += s[st[j]];
//
//        return ans;
//    }
//};