////#include<iostream>
////#include<vector>
////using namespace std;
////
////
////class Solution {
////private:
////    const int MOD = 1e9 + 7;
////    int n, m;
////    vector<int>hat;
////    int dp[41][1 << 10];
////    //status是分配状态，i是处理到的帽子
////    int dfs(int status, int i) {
////        if (status == (1 << n) - 1) {
////            return 1;
////        }
////        if (i > m) {
////            return 0;
////        }
////        if (dp[i][status] != -1) {
////            return dp[i][status];
////        }
////
////        int case1 = dfs(status, i + 1) % MOD;
////        int can = hat[i];
////        int case2 = 0;
////        for (int p = 0; p < n; ++p) {
////            if (((can & (1 << p)) != 0) && ((status & (1 << p)) == 0)) {
////                case2 = (case2 + dfs(status | (1 << p), i + 1)) % MOD;
////            }
////        }
////
////        int ans = (case1 + case2) % MOD;
////        dp[i][status] = ans;
////        return ans;
////    }
////    
////public:
////
////    int numberWays(vector<vector<int>>& hats) {
////        n = hats.size();//人数
////        m = 0;//求帽子最大序号
////        for (auto& i : hats) {
////            for (int j : i) {
////                if (j > m) {
////                    m = j;
////                }
////            }
////        }
////        hat.resize(m + 1, 0);
////        for (int p = 0; p < n; ++p) {//遍历人编号
////            for (int i : hats[p]) {//遍历帽子序号
////                hat[i] |= (1 << p);//帽子对应二进制人编号
////            }
////        }
////        memset(dp, -1, sizeof(dp));
////        return dfs(0, 1);
////
////    }
////};
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//class Solution {
//private:
//    const int MOD = 1e9 + 7;
//    int n, m;
//    vector<int>hat;
//    int dp[41][1 << 10];
//    //status是分配状态，i是处理到的帽子
//    int dfs(int status, int i) {
//        if (status == (1 << n) - 1) {
//            return 1;
//        }
//        if (i > m) {
//            return 0;
//        }
//        if (dp[i][status] != -1) {
//            return dp[i][status];
//        }
//
//        int case1 = dfs(status, i + 1) % MOD;
//        int can = hat[i];
//        int case2 = 0;
//        int rightOne;
//        while (can != 0) {
//            rightOne = can & -can;
//            if ((status & rightOne) == 0) {
//                case2 = (case2 + dfs(status | rightOne, i + 1)) % MOD;
//            }
//        }
//
//        int ans = (case1 + case2) % MOD;
//        dp[i][status] = ans;
//        return ans;
//    }
//
//public:
//
//    int numberWays(vector<vector<int>>& hats) {
//        n = hats.size();//人数
//        m = 0;//求帽子最大序号
//        for (auto& i : hats) {
//            for (int j : i) {
//                if (j > m) {
//                    m = j;
//                }
//            }
//        }
//        hat.resize(m + 1, 0);
//        for (int p = 0; p < n; ++p) {//遍历人编号
//            for (int i : hats[p]) {//遍历帽子序号
//                hat[i] |= (1 << p);//帽子对应二进制人编号
//            }
//        }
//        memset(dp, -1, sizeof(dp));
//        return dfs(0, 1);
//
//    }
//};