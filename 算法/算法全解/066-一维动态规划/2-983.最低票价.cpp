//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 370;
//typedef long long ll;
//
//class Solution {
//private:
//    int memo[MAXN];
//    bool out[MAXN];
//
//    int dfs(int d, const vector<int>& costs) {
//        if (d < 0)
//            return 0;
//
//        if (memo[d] != -1)
//            return memo[d];
//
//        if (!out[d])
//            return memo[d] = dfs(d - 1, costs);
//
//        int res = costs[0] + dfs(d - 1, costs);
//        res = min(res, costs[1] + dfs(d - 7, costs));
//        res = min(res, costs[2] + dfs(d - 30, costs));
//    
//        return memo[d] = res;
//    }
//
//public:
//    int mincostTickets(vector<int>& days, vector<int>& costs) {
//        memset(memo, -1, sizeof(memo));  
//        memset(out, 0, sizeof(out));
//
//        for (int i : days)
//            out[i] = true;
//
//        //dfs(365, costs);
//
//        vector<int>dp(MAXN, 0);
//        dp[0] = 0;
//        for (int i = 1; i <= 365; ++i) {
//            if (!out[i])
//                dp[i] = dp[i - 1];
//            else {
//                int p1 = dp[i - 1] + costs[0];
//                int p2 = dp[max(0, i - 7)] + costs[1];
//                int p3 = dp[max(0, i - 30)] + costs[2];
//                dp[i] = min({ p1,p2,p3 });
//            }
//        }
//
//        return dp[365];
//    }
//};