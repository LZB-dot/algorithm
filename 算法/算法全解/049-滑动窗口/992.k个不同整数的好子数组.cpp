//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    int subarraysWithKDistinct(vector<int>& nums, int k) {
//        // 计算最多包含 m 个不同元素的子数组数量
//        auto atMostK = [&](int m) {
//            unordered_map<int, int> cnts;
//            int l = 0, res = 0;
//            for (int r = 0; r < nums.size(); ++r) {
//                cnts[nums[r]]++;
//                // 窗口内元素种类超过 m 时，左指针右移
//                while (cnts.size() > m) {
//                    cnts[nums[l]]--;
//                    if (cnts[nums[l]] == 0) {
//                        cnts.erase(nums[l]);
//                    }
//                    l++;
//                }
//                // 累加以 r 为结尾的有效子数组数量
//                res += r - l + 1;
//            }
//            return res;
//            };
//
//        // 恰好 k 个 = 最多 k 个 - 最多 k-1 个
//        return atMostK(k) - atMostK(k - 1);
//    }
//};