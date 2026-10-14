//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
//        int n = capital.size();
//        vector<pair<int, int>>projects;
//        for (int i = 0; i < n; ++i)
//            projects.emplace_back(capital[i], profits[i]);
//        sort(projects.begin(), projects.end(),
//            [](const pair<int, int>& a, const pair<int, int>& b) {
//                return a.first < b.first;
//            });
//        priority_queue<int>heap;
//        int tmp = k;
//        int idx = 0;
//        int sum = w;
//        while (tmp > 0) {
//            while (idx < n && projects[idx].first <= sum) {
//                heap.push(projects[idx].second);
//                idx++;
//            }
//
//            if (heap.empty()) {
//                break;
//            }
//
//            sum += heap.top();
//            heap.pop();
//            tmp--;
//        }
//
//        return sum;
//    }
//};