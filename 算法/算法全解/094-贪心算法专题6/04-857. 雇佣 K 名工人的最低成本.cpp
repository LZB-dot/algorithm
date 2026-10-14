//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <climits>
//using namespace std;
//
//class Solution {
//public:
//    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
//        int n = quality.size();
//        vector<pair<double, int>> people;
//        for (int i = 0; i < n; ++i) {
//            people.emplace_back(static_cast<double>(wage[i]) / quality[i], quality[i]);
//        }
//
//        sort(people.begin(), people.end());
//
//        priority_queue<int> heap;
//        double sum = 0.0;
//        double ans = 1e18;   
//
//        for (auto& p : people) {
//            double ratio = p.first; 
//            int q = p.second;    
//
//            heap.push(q);
//            sum += q;
//
//            if (heap.size() > k) {
//                sum -= heap.top();
//                heap.pop();
//            }
//
//            if (heap.size() == k) {
//                ans = min(ans, sum * ratio);
//            }
//        }
//
//        return ans;
//    }
//};
