//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        int n = nums.size();
//        priority_queue<int>pq;
//
//        for (int i : nums) {
//            pq.push(i);
//        }
//
//        int rank = 0;
//        int ans = 0;
//        while (!pq.empty()) {
//            rank++;
//            ans = pq.top();
//            pq.pop();
//            if (rank == k) {
//                return ans;
//            }
//        }
//
//        return ans;
//    }
//};