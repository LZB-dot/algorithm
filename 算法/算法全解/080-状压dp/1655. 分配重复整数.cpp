//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//private:
//    vector<int> cnt;    //存储nums中每个数字的出现次数
//    int n, m;           
//    vector<vector<int>> dp;
//    vector<int> sum; 
//
//    bool dfs(int status, int idx) {
//       
//        if (status == (1 << m) - 1) {
//            return true;
//        }
//      
//        if (idx == n) {
//            return false;
//        }
//
//        if (dp[status][idx] != -1) {
//            return dp[status][idx] == 1;
//        }
//
//        //不使用第idx个数字
//        if (dfs(status, idx + 1)) {
//            dp[status][idx] = 1;
//            return true;
//        }
//
//        //使用第idx个数字，尝试满足status的补集中的某个子集
//        int cur = cnt[idx];         
//        int remain_status = ((1 << m) - 1) ^ status;
//        for (int sub = remain_status; sub != 0; sub = (sub - 1) & remain_status) {
//            
//            if (sum[sub] <= cur && dfs(status | sub, idx + 1)) {
//                dp[status][idx] = 1;
//                return true;
//            }
//        }
//
//        dp[status][idx] = 0;
//        return false;
//    }
//
//public:
//    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
//        //统计nums中每个数字的出现次数
//        sort(nums.begin(), nums.end());
//        int s = nums.size();
//        for (int i = 0; i < s;) {
//            int j = i;
//            while (j < s && nums[j] == nums[i])
//                j++;
//            cnt.push_back(j - i);
//            i = j;
//        }
//
//        n = cnt.size();
//        m = quantity.size();
//        sum.resize(1 << m, 0);
//        //遍历每个quantity元素，更新对应子集的和
//        for (int i = 0; i < m; ++i) {
//            int val = quantity[i];
//            int mask = 1 << i;
//            //遍历所有不包含第i位的状态，更新包含第i位的状态的和
//            for (int j = 0; j < (1 << m); ++j) {
//                if ((j & mask) == 0) {
//                    sum[j | mask] = sum[j] + val;
//                }
//            }
//        }
//
//        dp.resize(1 << m, vector<int>(n, -1));
//        return dfs(0, 0);
//    }
//};
