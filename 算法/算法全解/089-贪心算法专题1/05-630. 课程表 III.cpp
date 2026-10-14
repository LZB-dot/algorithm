//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//    int scheduleCourse(vector<vector<int>>& courses) {
//        sort(courses.begin(), courses.end(),
//            [](const vector<int>& a, const vector<int>& b) {
//                return a[1] < b[1];
//            });
//
//        priority_queue<int>heap;
//        int used = 0;
//        int ans = 0;
//
//        for (const auto& course : courses) {
//            int time = course[0];
//            int ed = course[1];
//
//            if (time + used <= ed) {
//                heap.push(time);
//                used += time;
//            }
//            else if (!heap.empty() && heap.top() > time) {
//                used += time - heap.top();
//                heap.pop();
//                heap.push(time);
//            }
//
//            ans = max(ans, (int)heap.size());
//        }
//
//        return ans;
//    }
//};