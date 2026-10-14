//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    long long maxRunTime(int n, vector<int>& batteries) {
//        long long r = 0;
//        for (long long num : batteries) {
//            r += num;
//        }
//        r /= n;
//        long long l = 0;
//
//        auto f = [&](long long mid) {
//            long long ans = 0;
//            int cnts = n;
//            long long sum = 0;
//            for (int i : batteries) {
//                if (i >= mid) {
//                    --cnts;
//                }
//                else {
//                    sum += i;
//                }
//                if (sum >= cnts * mid) {
//                    return true;
//                }
//            }
//            return false;
//        };
//        long long ans = 0;
//        while (l <= r) {
//            long long mid = l + ((r - l) >> 1);
//            if (f(mid)) {
//                ans = mid;
//                l = mid + 1;
//            }
//            else {
//                r = mid - 1;
//            }
//        }
//        return ans;
//    }
//};