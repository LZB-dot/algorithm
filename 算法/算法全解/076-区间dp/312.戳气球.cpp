//#include<iostream>
//#include<vector>
//using namespace std;
//
////class Solution {
////private:
////    vector<vector<int>>dp;
////
////    int f(const vector<int>& arr, int l, int r) {
////        if (dp[l][r] != -1) {
////            return dp[l][r];
////        }
////
////        if (l == r) {
////            dp[l][r] = arr[l - 1] * arr[r + 1] * arr[l];
////            return dp[l][r];
////        }
////
////        int ans = 0;
////        for (int k = l; k <= r; ++k) {
////            int left = f(arr, l, k - 1);
////            int right = f(arr, k + 1, r);
////            ans = max(ans, left + right + arr[k] * arr[l - 1] * arr[r + 1]);
////        }
////      
////        dp[l][r] = ans;
////        return ans;
////    }
////public:
////    int maxCoins(vector<int>& nums) {
////        int n = nums.size();
////        vector<int>arr(n + 2);
////        arr[0] = 1;
////        arr[n + 1] = 1;
////        for (int i = 0; i < n; ++i) {
////            arr[i + 1] = nums[i];
////        }
////        dp.resize(n + 2, vector<int>(n + 2, -1));
////        //确保l-1，r+1的气球未被打爆
////        return f(arr, 1, n);
////    }
////};
//
//
//
//class Solution {
//public:
//    int maxCoins(vector<int>& nums) {
//        int n = nums.size();
//        vector<int>arr(n + 2);
//        arr[0] = 1;
//        arr[n + 1] = 1;
//        for (int i = 0; i < n; ++i) {
//            arr[i + 1] = nums[i];
//        }
//        vector<vector<int>>dp(n + 2, vector<int>(n + 2, 0));
//        //确保l-1，r+1的气球未被打爆
//        
//        for (int i = 1; i <= n; ++i) {
//            dp[i][i] = arr[i - 1] * arr[i + 1] * arr[i];
//        }
//
//        for (int i = n - 1; i >= 1; --i) {
//            for (int j = i + 1; j <= n; ++j) {
//                for (int k = i; k <= j; ++k) {
//                    dp[i][j] = max(dp[i][j], 
//                        dp[i][k - 1] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j + 1]);
//                }
//            }
//        }
//
//        return dp[1][n];
//    }
//};