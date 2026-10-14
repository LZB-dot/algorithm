//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int findMinMoves(vector<int>& machines) {
//        int sum = 0;
//        for (int m : machines)
//            sum += m;
//
//        int n = machines.size();
//        if (sum % n != 0)
//            return -1;
//
//        int target = sum / n;
//        int left = 0;
//        int ans = 0;
//        for (int i = 0; i < n; ++i) {
//            int lneed = i * target - left;
//            int rneed = (n - i - 1) * target - (sum - left - machines[i]);
//
//            int tmp;
//            if (lneed > 0 && rneed > 0) {
//                tmp = lneed + rneed;
//            }
//            else {
//                tmp = max(abs(lneed), abs(rneed));
//            }
//
//            ans = max(tmp, ans);
//            
//            left += machines[i];
//
//        }
//        return ans;
//    }
//};