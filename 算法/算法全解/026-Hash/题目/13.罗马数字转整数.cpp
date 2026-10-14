//#include<iostream>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    int romanToInt(string s) {
//        unordered_map<char, int>mp = {
//        {'I', 1},{'V', 5},{'X', 10},{'L', 50},
//        { 'C', 100 }, { 'D', 500 }, { 'M', 1000 }
//        };
//
//        int ans = 0;
//        int n = s.size();
//        for (int i = 0; i < n; ++i) {
//            int cnt = mp[s[i]];
//            if (i<n - 1 && mp[s[i + 1]]>cnt) {
//                ans -= cnt;
//            }
//            else {
//                ans += cnt;
//            }
//        }
//        return ans;
//    }
//};