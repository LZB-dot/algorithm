//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<unordered_set>
//using namespace std;
//
//
//class Solution {
//private:
//    vector<vector<int> >ans;
//    vector<int>used;
//    void work(int i, vector<int>& nums) {
//        if (i == nums.size()) {
//            ans.push_back(nums);
//            return;
//        }
//        else {
//            unordered_set<int>used;
//            for (int k = i; k < nums.size(); ++k) {
//
//                if (used.find(nums[k]) != used.end()) {
//                    continue;
//                }
//                used.insert(nums[k]);
//                swap(nums[i], nums[k]);
//                work(i + 1, nums);
//                swap(nums[i], nums[k]);
//            }
//        }
//    }
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        work(0, nums);
//        return ans;
//    }
//};