//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int longestSubstring(string s, int k) {
//        int n = s.size();
//        int ans = 0;
//        for (int i = 1; i <= 26; ++i) {
//            vector<int>cnts(256, 0);
//            int collect = 0, satisfy = 0;
//            for (int l = 0, r = 0; r < n; ++r) {
//                cnts[s[r]]++;
//
//                //不同字符数增加
//                if (cnts[s[r]] == 1) {
//                    collect++;
//                }
//                //满足条件数增加
//                if (cnts[s[r]] == k) {
//                    satisfy++;
//                }
//
//                while (collect > i) {
//                    if (cnts[s[l]] == 1) {
//                        collect--;
//                    }
//                    if (cnts[s[l]] == k) {
//                        satisfy--;
//                    }
//                    cnts[s[l++]]--;
//                }
//
//                if (collect == i && satisfy == i) {
//                    ans = max(ans, r - l + 1);
//                }
//            }
//        }
//        return ans;
//    }
//};