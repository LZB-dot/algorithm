//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int minEatingSpeed(vector<int>& piles, int h) {
//        int l = 1;
//        int r = 0;
//        for (int i : piles) {
//            r = max(i, r);
//        }
//        int ans = r;
//        while (l <= r) {
//            int mid = (l + r) / 2;
//            long long time = f(mid, piles);
//            if (time <= h) {
//                r = mid - 1;
//                ans = mid;
//            }
//            else {
//                l = mid + 1;
//            }
//        }
//        return ans;
//    }
//
//    long long f(int mid,const vector<int>& piles) {
//        long long time = 0;
//        for (int i : piles) {
//            //向上取整
//            time += (i - 1) / mid + 1;
//        }
//        return time;
//    }
//};