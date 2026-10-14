//////#include<iostream>
//////#include<vector>
//////#include<climits>
//////
//////using namespace std;
//////
//////class Solution {
//////private:
//////    vector<int> dp;
//////
//////    int f(const vector<int>& prices, int i, int n) {
//////        if (dp[i] != -1) {
//////            return dp[i];
//////        }
//////
//////        int ans = prices[i];
//////
//////        if (2 * i + 2 >= n) {
//////            dp[i] = ans;
//////            return ans;
//////        }
//////
//////        int cost = INT_MAX;
//////
//////        for (int k = i + 1; k <= 2 * i + 2; ++k) {
//////            cost = min(cost, f(prices, k, n));
//////        }
//////
//////        if (cost != INT_MAX) {
//////            ans += cost;
//////        }
//////
//////        dp[i] = ans;
//////        return ans;
//////    }
//////
//////public:
//////    int minimumCoins(vector<int>& prices) {
//////        int n = prices.size();
//////        dp.resize(n, -1);
//////        return f(prices, 0, n);
//////    }
//////};
////
////
////#include<iostream>
////#include<vector>
////#include<climits>
////
////using namespace std;
////
////class Solution {
////public:
////    int minimumCoins(vector<int>& prices) {
////        int n = prices.size();
////        vector<int> dp(n + 1, INT_MAX);
////
////        for (int i = n - 1; i >= 0; --i) {
////            dp[i] = prices[i];
////
////            int left = i + 1;
////            int right = i * 2 + 2;
////
////            if (right >= n) {
////                continue;
////            }
////
////            int cost = INT_MAX;
////            for (int k = left; k <= right; ++k) {
////                cost = min(cost, dp[k]);
////            }
////
////            dp[i] += cost;
////            
////        }
////        return dp[0];
////    }
////};
//
//
//#include<iostream>
//#include<vector>
//#include<climits>
//#include<deque>
//using namespace std;
//
//class Solution {
//public:
//    int minimumCoins(vector<int>& prices) {
//        int n = prices.size();
//        deque<pair<int, int>>q;
//        q.push_back({ n,0 });
//        for (int i = n - 1; i >= 0; --i) {
//            
//            while (!q.empty() && q.back().first <= 2 * i + 2) {
//                q.pop_back();
//            }
//
//            int cost = prices[i] + q.back().second;
//
//            while (!q.empty() && q.front().second >= cost) {
//                q.pop_front();
//            }
//            q.push_front({ i,cost });
//
//        }
//        return q.front().second;
//    }
//};
