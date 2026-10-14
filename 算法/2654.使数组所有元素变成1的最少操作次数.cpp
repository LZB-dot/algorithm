//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//private:
//    int gcd(int a, int b) {
//        while (b != 0) {
//            int tmp = b;
//            b = a % b;
//            a = tmp;  
//        }
//        return a;
//    }
//public:
//    int minOperations(vector<int>& nums) {
//        int n = nums.size();
//        int count_one = count(nums.begin(), nums.end(), 1);
//
//        // 若已有1，直接返回需要的操作数
//        if (count_one != 0) {
//            return n - count_one;
//        }
//
//        // 检查整个数组的GCD是否为1（若不为1，无法得到1）
//        int total_gcd = nums[0];
//        for (int num : nums) {
//            total_gcd = gcd(num, total_gcd);
//            if (total_gcd == 1) 
//                break;
//        }
//        if (total_gcd != 1) {
//            return -1;
//        }
//
//        // 寻找GCD为1的最短连续子数组
//        int min_len = n;  // 初始化最长可能长度
//        for (int i = 0; i < n; ++i) {
//            int cur_gcd = nums[i];  // 从i开始的子数组
//            for (int j = i; j < n; ++j) {  // j从i开始，确保连续
//                cur_gcd = gcd(cur_gcd, nums[j]);
//                if (cur_gcd == 1) {
//                    min_len = min(min_len, j - i + 1);  // 更新最短长度
//                    break;  // 找到当前i的最短子数组，无需继续
//                }
//            }
//        }
//
//        // 操作数 = 生成第一个1的操作数（min_len-1）+扩散到所有元素的操作数（n-1）
//        return (min_len - 1) + (n - 1);
//    }
//};