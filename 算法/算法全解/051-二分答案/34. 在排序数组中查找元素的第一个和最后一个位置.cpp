//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//
//
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int l = 0, r = nums.size() - 1;
//        int tmp = -1;
//        while (l <= r) {
//            int mid = l + ((r - l) >> 1);
//            if (nums[mid] > target) {
//                r = mid - 1;
//            }
//            else if (nums[mid] < target) {
//                l = mid + 1;
//            }
//            else {
//                tmp = mid;
//                break;
//            }
//        }
//
//        vector<int>ans(2, -1);
//        if (tmp == -1) {
//            return ans;
//        }
//        int t1 = tmp;
//        while (t1 >= 0 && nums[t1] == target) {
//            ans[0] = t1;
//            t1--;
//        }
//
//        int t2 = tmp;
//        while (t2 < nums.size() && nums[t2] == target) {
//            ans[1] = t2;
//            t2++;
//        }
//        return ans;
//    }
//};