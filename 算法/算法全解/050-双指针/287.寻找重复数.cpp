//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int findDuplicate(vector<int>& nums) {
//        if (nums.empty() || nums.size() < 2) {
//            return -1;
//        }
//
//        //Ä£ÄâÁ´±íÕÒ»·
//        int slow = nums[0];
//        int fast = nums[slow];
//        while (slow != fast) {
//            slow = nums[slow];
//            fast = nums[nums[fast]];
//        }
//
//        fast = 0;
//        while (slow != fast) {
//            slow = nums[slow];
//            fast = nums[fast];
//        }
//
//        return slow;
//    }
//};