//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//    vector<long long> findXSum(vector<int>& nums, int k, int x) {
//        int n = nums.size();
//        vector<long long>ans;
//        unordered_map<int, int>count;
//        for (int i = 0; i < k; ++i) {
//            count[nums[i]]++;
//        }
//
//        vector<pair<int, int>>freq;
//        for (int l = 0, r = 0; l <= n - k; ++l) {
//            freq.clear();
//            for (auto& it : count) {
//                if (it.second != 0) {
//                    freq.emplace_back(it.first, it.second);
//                }
//            }
//
//            sort(freq.begin(), freq.end(),
//                [&](const pair<int, int>& a, const pair<int, int>& b) {
//                    if (a.second != b.second)
//                        return a.second > b.second;
//                    else
//                        return a.first > b.first;
//                });
//
//            long long sum = 0;
//            int take = min((int)freq.size(), x);
//
//            for (int i = 0; i < take; ++i) {
//                sum += (long long)freq[i].first * (long long)freq[i].second;
//            }
//            ans.push_back(sum);
//
//            if (l < n - k) {
//                int left = nums[l];
//                int right = nums[l + k];
//                if (--count[left] == 0) {
//                    count.erase(left);
//                }
//                count[right]++;
//            }
//        }
//        return ans;
//    }
//};