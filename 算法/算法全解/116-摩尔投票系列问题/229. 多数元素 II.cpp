//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> majorityElement(vector<int>& nums) {
//        int k = 3;
//        int n = nums.size();
//        vector<pair<int, int>>tar(k - 1);
//
//        for (int i : nums) {
//            bool f1 = 0;
//            for (auto& j : tar) {
//                if (j.first == i) {
//                    ++j.second;
//                    f1 = true;
//                    break;
//                }
//            }
//
//            if (f1)
//                continue;
//
//            f1 = 0;
//            for (auto& j : tar) {
//                if (j.second == 0) {
//                    j.first = i;
//                    j.second = 1;
//                    f1 = 1;
//                    break;
//                }
//            }
//
//            if (f1)
//                continue;
//
//            for (auto& j : tar)
//                j.second--;
//        }
//
//        vector<int>ans;
//        vector<int>cnt(k - 1);
//        for (int i : nums) {
//            for (int j = 0; j < k - 1; ++j) {
//                if (i == tar[j].first)
//                    cnt[j]++;
//            }
//        }
//
//        for (int j = 0; j < k - 1; ++j) {
//            if (cnt[j] > n / k && (ans.empty() || ans.back() != tar[j].first))
//                ans.push_back(tar[j].first);
//        }
//
//        return ans;
//    }
//};