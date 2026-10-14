//#include<iostream>
//#include<vector>
//#include<deque>
//#include<algorithm>
//using namespace std;
//
//#include <vector>
//#include <algorithm>
//#include <deque>
//using namespace std;
//
//class Solution {
//public:
//    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
//        sort(tasks.begin(), tasks.end());    // 任务从小到大排序
//        sort(workers.begin(), workers.end());// 工人能力从小到大排序
//        int st = tasks.size(), sw = workers.size();
//
//        int l = 0, r = min(sw, st);
//        int ans = 0;
//
//        // 检查是否能完成m个任务：使用最小的m个任务和最大的m个工人
//        auto check = [&](int m)->bool {
//            if (m == 0) 
//                return true;
//            int tl = 0, tr = m - 1;  
//            int wl = sw - m, wr = sw - 1; 
//            int cnt_pills = 0;
//            deque<int> dq; 
//
//            for (int i = wl, j = tl; i <= wr; ++i) {
//
//                while (j <= tr && tasks[j] <= workers[i]) {
//                    dq.push_back(j);
//                    ++j;
//                }
//
//                if (!dq.empty() && tasks[dq.front()] <= workers[i]) {
//                    dq.pop_front();
//                }
//                else {
//                    while (j <= tr && tasks[j] <= workers[i] + strength) {
//                        dq.push_back(j);
//                        ++j;
//                    }
//                    // 用吃药的工人处理任务
//                    if (!dq.empty()) {
//                        ++cnt_pills;
//                        dq.pop_front();
//                    }
//                    else {
//                        return false; //无法处理当前工人对应的任务
//                    }
//                }
//                if (cnt_pills > pills) {
//                    return false; // 药片不够
//                }
//            }
//            return true;
//            };
//
//        // 二分查找最大可完成的任务数
//        while (l <= r) {
//            int mid = l + (r - l) / 2;
//            if (check(mid)) {
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