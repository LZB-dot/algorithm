//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int findSubstringInWraproundString(string s) {
//        int n = s.size();
//        //转化为数字便于计算
//        vector<int>arr(n);
//        for (int i = 0; i < n; ++i) {
//            arr[i] = s[i] - 'a';
//        }
//
//        //以i结尾的最长符合要求的字符串长度，
//        //也是以i结尾的子串个数
//        vector<int>dp(26, 0);
//        dp[arr[0]] = 1;
//        for (int i = 1, len = 1; i < n; ++i) {
//            int cur = arr[i];
//            int pre = arr[i - 1];
//
//            if ((pre + 1 == cur) || (pre == 25 && cur == 0)) {
//                len++;
//            }
//            else {
//                len = 1;
//            }
//            dp[cur] = max(dp[cur], len);
//        }
//        int ans = 0;
//        for (int i : dp) {
//            ans += i;
//        }
//
//        return ans;
//    }
//};