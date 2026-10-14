//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//private:
//    int bindarySearch(const vector<int>& ends, int len, int num) {
//        int l = 0, r = len - 1;
//        int pos = -1;
//        while (l <= r) {
//            int mid = l + ((r - l) >> 1);
//            if (ends[mid] > num) {
//                pos = mid;
//                r = mid - 1;
//            }
//            else {
//                l = mid + 1;
//            }
//        }
//        return pos;
//    }
//
//    int lengthOfLIS(const vector<int>& nums) {
//        int n = nums.size();
//        vector<int>ends(n + 1);
//        int len = 0;
//        for (int i = 0; i < n; ++i) {
//            int pos = bindarySearch(ends, len, nums[i]);
//            if (pos == -1) {
//                ends[len++] = nums[i];
//            }
//            else {
//                ends[pos] = nums[i];
//            }
//        }
//        return len;
//    }
//public:
//    int kIncreasing(vector<int>& arr, int k) {
//        int n = arr.size();
//        int ans = 0;
//        for (int i = 0; i < k; ++i) {
//            vector<int>nums;
//            for (int j = i; j < n; j += k) {
//                nums.push_back(arr[j]);
//            }
//            ans += nums.size() - lengthOfLIS(nums);
//        }
//        return ans;
//    }
//};