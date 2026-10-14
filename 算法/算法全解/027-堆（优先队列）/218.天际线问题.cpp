//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//        vector<vector<int>> res;
//        if (buildings.empty())
//            return res;
//
//        // 拆分事件点：左边界用负高度标记，右边界用正高度标记
//        vector<pair<int, int>> events;
//        for (auto& b : buildings) {
//            int left = b[0], right = b[1], height = b[2];
//            events.emplace_back(left, -height);  // 左边界事件（开始）
//            events.emplace_back(right, height);   // 右边界事件（结束）
//        }
//
//        // 排序事件点：按x升序，x相同则左边界事件优先
//        sort(events.begin(), events.end(),
//            [](const pair<int, int>& a, const pair<int, int>& b) {
//                if (a.first != b.first) {
//                    return a.first < b.first;
//                }
//                else {
//                    return a.second < b.second;  // 负高度（左）排在正高度（右）前
//                }
//            });
//
//        // 最大堆存储当前有效高度，初始加入地面高度0
//        priority_queue<int> mxh;
//        mxh.push(0);
//        int pre = 0;  // 上一个转折点的高度
//        unordered_map<int, int> removeCount;  // 延迟删除的高度计数
//
//        for (auto& e : events) {
//            int x = e.first;
//            int h = e.second;
//
//            if (h < 0) {
//                // 左边界事件：加入建筑高度（恢复为正）
//                mxh.push(-h);
//            }
//            else {
//                // 右边界事件：标记高度待删除
//                removeCount[h]++;
//            }
//
//            // 延迟删除：清理堆中已失效的高度
//            while (!mxh.empty()) {
//                int currentMax = mxh.top();
//                if (removeCount.count(currentMax) && removeCount[currentMax] > 0) {
//                    // 减少计数，若计数为0则从哈希表中删除
//                    if (--removeCount[currentMax] == 0) {
//                        removeCount.erase(currentMax);
//                    }
//                    mxh.pop();
//                }
//                else {
//                    break;  // 堆顶有效，停止清理
//                }
//            }
//
//            // 检查当前最高高度是否变化，若变化则记录转折点
//            int cur = mxh.top();
//            if (cur != pre) {
//                res.emplace_back(x, cur);
//                pre = cur;
//            }
//        }
//
//        return res;
//    }
//};