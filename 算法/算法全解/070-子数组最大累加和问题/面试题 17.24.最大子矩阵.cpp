//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
//        int n = matrix.size(), m = matrix[0].size();
//        int ans = INT_MIN;
//        vector<int>res(4, 0);
//        if (n == 1 && m == 1) {
//            return res;
//        }
//
//        vector<int>nums(m, 0);
//
//        for (int up = 0; up < n; ++up) {
//            fill(nums.begin(), nums.end(), 0);
//            for (int down = up; down < n; ++down) {
//
//                for (int col = 0; col < m; ++col) {
//                    nums[col] += matrix[down][col];
//                }
//
//                int pre = INT_MIN;
//                int left = 0;
//                for (int i = 0; i < m; ++i) {
//                    if (pre >= 0) {
//                        pre += nums[i];
//                    }
//                    else {
//                        pre = nums[i];
//                        left = i;
//                    }
//
//                    if (pre > ans) {
//                        ans = pre;
//                        res[0] = up;
//                        res[1] = left;
//                        res[2] = down;
//                        res[3] = i;
//                    }
//                }
//                
//            }
//        }
//
//        return res;
//    }
//};