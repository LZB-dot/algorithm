//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//private:
//    vector<vector<vector<int>>> dp;
//
//    // 在 l 左边有 k 个与它相同的盒子
//    int f(const vector<int>& boxes, int l, int r, int k) {
//        if (l > r)
//            return 0;
//        if (dp[l][r][k] > 0) {
//            return dp[l][r][k];
//        }
//
//        if (l == r) {
//            dp[l][r][k] = (k + 1) * (k + 1);
//            return dp[l][r][k];
//        }
//
//        int s = l;
//        while (s + 1 <= r && boxes[s + 1] == boxes[l]) {
//            ++s;
//        }
//        int cnt = k + (s - l + 1);
//        int ans = (cnt * cnt) + f(boxes, s + 1, r, 0);
//
//        for (int m = s + 2; m <= r; ++m) {
//            if (boxes[m] == boxes[l] && boxes[m - 1] != boxes[l]) {
//                ans = max(ans, f(boxes, s + 1, m - 1, 0) + f(boxes, m, r, cnt));
//            }
//        }
//
//        dp[l][r][k] = ans;
//        return ans;
//    }
//
//public:
//    int removeBoxes(vector<int>& boxes) {
//        int n = boxes.size();
//        dp.resize(n, vector<vector<int>>(n, vector<int>(n, 0)));
//        return f(boxes, 0, n - 1, 0);
//    }
//};
