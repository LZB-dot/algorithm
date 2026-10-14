//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//private:
//    vector<vector<int>> ans; 
//    vector<int> path;      
//
//    void backtrack(int i, const vector<int>& nums) {
//
//        if (i == nums.size()) {
//            ans.push_back(path);
//            return;
//        }
//
//        int j = i;
//        while (j < nums.size() && nums[j] == nums[i]) {
//            j++;
//        }
//
//        backtrack(j, nums);
//
//        for (int k = i; k < j; ++k) {
//            path.push_back(nums[k]); 
//            backtrack(j, nums);     
//        }
//
//    }
//
//public:
//    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        ans.clear();
//        path.clear();
//        backtrack(0, nums);
//        return ans;
//    }
//};
