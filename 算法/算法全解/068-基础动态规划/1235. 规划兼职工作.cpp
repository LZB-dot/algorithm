//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//        int n = startTime.size();
//        vector<vector<int>>jobs(n, vector<int>(3, 0));
//        for (int i = 0; i < n; ++i) {
//            jobs[i][0] = startTime[i];
//            jobs[i][1] = endTime[i];
//            jobs[i][2] = profit[i];
//        }
//        //按结束时间升序排序
//        sort(jobs.begin(), jobs.end(), 
//            [](const vector<int>& a, const vector<int>& b) {
//                return a[1] < b[1];
//            });
//
//        //前i+1个工作的最大工资
//        vector<int>dp(n, 0);
//        dp[0] = jobs[0][2];
//        for (int i = 1; i < n; ++i) {
//            //计算要当前工作的最大工资
//            int target = jobs[i][0];//当前工作起始时间
//            dp[i] = jobs[i][2];
//            //二分查找 之前工作结束时间<当前工作开始时间的最大位置
//            int left = 0, right = n - 1;
//            int pre = -1;
//            while (left <= right) {
//                int mid = left + ((right - left) >> 1);
//                if (jobs[mid][1] <= target) {
//                    pre = mid;
//                    left = mid + 1;
//                }
//                else {
//                    right = mid - 1;
//                }
//            }
//            if (pre != -1) {
//                dp[i] += dp[pre];
//            }
//            dp[i] = max(dp[i - 1], dp[i]);
//        }
//
//        return dp[n - 1];
//    }
//};