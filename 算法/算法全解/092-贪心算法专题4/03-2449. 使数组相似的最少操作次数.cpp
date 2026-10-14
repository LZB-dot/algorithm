//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//private:
//    int spilt(vector<int>& nums) {
//        int cnts = 0;
//        int n = nums.size();
//        for (int i = 0; i < n; ++i) {
//            if (nums[i] % 2 == 1) {
//                swap(nums[i], nums[cnts]);
//                cnts++;
//            }
//        }
//        return cnts;
//    }
//public:
//    long long makeSimilar(vector<int>& nums, vector<int>& target) {
//        int s = spilt(nums);
//        sort(nums.begin(), nums.begin() + s);
//        sort(nums.begin() + s, nums.end());
//        spilt(target);
//        sort(target.begin(), target.begin() + s);
//        sort(target.begin() + s, target.end());
//
//        int n = nums.size();
//        long long sum = 0;
//        for (int i = 0; i < n; ++i) {
//            if (nums[i] != target[i]) {
//                sum += abs(nums[i] - target[i]);
//            }
//        }
//
//        return sum / 4;
//
//    }
//};