//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//class Solution {
//public:
//    int maxEvents(vector<vector<int>>& events) {
//        sort(events.begin(), events.end(),
//            [](const vector<int>& a, const vector<int>& b) {
//                return a[0] < b[0];
//            });
//
//        priority_queue<int, vector<int>, greater<int>>min_heap;
//        int n = events.size();
//        int start = -1, end = -1;
//        for (const auto& e : events) {
//            start = min(start, e[0]);
//            end = max(end, e[1]);
//        }
//        int e = 0; 
//        int ans = 0;
//        for (int i = start; i <= end; ++i) {
//            while (e < n && events[e][0] == i) {
//                min_heap.push(events[e][1]);
//                e++;
//            }
//
//            while (!min_heap.empty()&&min_heap.top()<i) {
//                min_heap.pop();
//            }
//
//            if (!min_heap.empty()) {
//                ans++;
//                min_heap.pop();
//            }
//
//        }
//        return ans;
//    }
//};