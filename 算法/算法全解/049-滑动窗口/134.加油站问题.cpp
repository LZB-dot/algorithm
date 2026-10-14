//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//
//        int n = gas.size();
//        for (int l = 0, r = 0; l < n; l = r + 1, r = l) {
//            int cur = 0;
//            //[l,r]
//            while (1) {
//                int remain = gas[r % n] - cost[r % n];
//                if (cur + remain < 0) {
//                    break;
//                }
//                cur += remain;
//                if (r - l + 1 == n) {
//                    return l;
//                }
//                r++;
//            }
//        }
//        return -1;
//    }
//};