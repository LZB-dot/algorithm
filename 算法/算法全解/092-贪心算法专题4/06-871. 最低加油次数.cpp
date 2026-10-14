//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//class Solution {
//public:
//    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//        if (startFuel > target)
//            return 0;
//        
//        priority_queue<int>heap;
//        int cur = startFuel;
//        int ans = 0;
//        for (const auto& s : stations) {
//
//            while (!heap.empty() && cur < s[0]) {
//                cur += heap.top();
//                heap.pop();
//                ans++;
//                if (cur >= target)
//                    return ans;
//            }
//
//            if (cur < s[0])
//                return -1;
//
//            heap.push(s[1]);
//        }
//
//        while (!heap.empty()) {
//            cur += heap.top();
//            heap.pop();
//            ans++;
//            if (cur >= target) {
//                return ans;
//            }
//        }
//
//        return -1;
//    }
//};