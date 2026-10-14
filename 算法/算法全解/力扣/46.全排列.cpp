//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//private:
//    vector<vector<int> >ans;
//    
//    void work(int i,vector<int>& nums) {
//        if (i == nums.size()) {
//            ans.push_back(nums);
//            return;
//        }
//        else {
//            for (int k = i; k < nums.size(); ++k) {
//                swap(nums[i], nums[k]);
//                work(i + 1, nums);
//                swap(nums[i], nums[k]);
//            }
//        }
//    }
//public:
//    vector<vector<int>> permute(vector<int>& nums) {
//        work(0, nums);
//        return ans;
//    }
//};