//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//
//
//class Solution {
//public:
//    // 二分查找：在ends数组中找到第一个>=num的位置
//    int binarySearch(vector<int>& ends, int len, int num) {
//        int left = 0, right = len - 1;
//        int pos = -1;
//        while (left <= right) {
//            int mid = (left + right) / 2;
//            if (ends[mid] >= num) {
//                pos = mid;
//                right = mid - 1;
//            }
//            else {
//                left = mid + 1;
//            }
//        }
//        return pos;
//    }
//
//    int findLongestChain(vector<vector<int>>& pairs) {
//        int n = pairs.size();
//        if (n == 0) return 0;
//
//        // 按照数对的第一个元素从小到大排序
//        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
//            return a[0] < b[0];
//            });
//
//        vector<int> ends; // 维护最长递增子序列的最小末尾元素
//
//        for (auto& pair : pairs) {
//            int num = pair[0]; // 数对的第一个元素
//            int pos = binarySearch(ends, ends.size(), num);
//            if (pos == -1) {
//                ends.push_back(pair[1]);
//            }
//            else {
//                ends[pos] = min(ends[pos], pair[1]);
//            }
//        }
//
//        return ends.size();
//    }
//};