//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> findXSum(vector<int>& nums, int k, int x) {
//        int n = nums.size();
//        vector<int>res;
//        if (n == 0 || k == 0)
//            return res;
//        unordered_map<int, int>count;
//        vector<pair<int, int>>freq;
//
//        for (int i = 0; i < k; ++i) {
//            count[nums[i]]++;
//        }
//
//        for (int l = 0, r; l <= n - k; ++l) {
//            freq.clear();
//            for (auto& x : count) {
//                if (x.second > 0) {
//                    freq.emplace_back(x.first, x.second);
//                }
//            }
//            
//            sort(freq.begin(), freq.end(),
//                [](const pair<int, int>& a, const pair<int, int>& b) {
//                    if (a.second != b.second) {
//                        return a.second > b.second;
//                    }
//                    else {
//                        return a.first > b.first;
//                    }
//                });
//
//            int xSum = 0;
//            int take = min(x, (int)freq.size());
//            for (int i = 0; i < take; ++i) {
//                xSum += freq[i].first * freq[i].second;
//            }
//            res.push_back(xSum);
//            if (l < n - k) {
//                int left = nums[l];
//                int right = nums[l + k];
//                if (--count[left] == 0) {
//                    count.erase(left);
//                }
//                count[right]++;
//            }
//            
//        }
//        return res;
//    }
//};