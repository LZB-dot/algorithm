//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
//        int n = nums.size();
//
//        //以i为起点，长度为k的子数组和
//        vector<int>sums(n);
//        int sum = 0;    
//        for (int l = 0, r = 0; r < n; ++r) {
//            sum += nums[r];
//            if (r - l + 1 == k) {
//                sums[l] = sum;
//                sum -= nums[l];
//                l++;
//            }
//        }
//
//        //0-r范围内长为k子数组和最大的起始坐标
//        vector<int>prefix(n, 0);
//        for (int l = 1, r = k; r < n; ++r) {
//            if (sums[l] > sums[prefix[r - 1]]) {
//                prefix[r] = l;
//            }
//            else {
//                prefix[r] = prefix[r - 1];
//            }
//        }
//
//        //l-n-1范围内长为k子数组和最大的起始坐标
//        vector<int>suffix(n, 0);
//        for (int l = n - k - 1; l >= 0; --l) {
//            if (sums[l] >= sums[suffix[l + 1]]) {
//                suffix[l] = l;
//            }
//            else {
//                suffix[l] = suffix[l + 1];
//            }
//        }
//
//        int maxTotal = INT_MIN;
//        vector<int>res(3, 0);
//        for (int mid = k; mid <= n - 2 * k; ++mid) {
//            int left = prefix[mid - 1];
//            int right = suffix[mid + k];
//            int total = sums[left] + sums[right] + sums[mid];
//            if (maxTotal < total) {
//                maxTotal = total;
//                res[0] = left;
//                res[1] = mid;
//                res[2] = right;
//            }
//        }
//        return res;
//    }
//};