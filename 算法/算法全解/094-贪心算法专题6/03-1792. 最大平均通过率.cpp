//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//
//class Solution {
//public:
//    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
//        priority_queue<vector<double>>heap;
//        for (auto& c : classes) {
//            double x = c[0];
//            double y = c[1];
//            double z = (x + 1) / (y + 1) - x / y;
//            heap.push({ z,x,y });
//        }
//        int n = extraStudents;
//        while (!heap.empty() && n > 0) {
//            vector<double>cur = heap.top();
//            heap.pop();
//            double a = cur[1] + 1;
//            double b = cur[2] + 1;
//            double c = (a + 1) / (b + 1) - a / b;
//            heap.push({ c,a,b });
//            --n;
//        }
//
//        double total = 0;
//        while (!heap.empty()) {
//            vector<double>cur = heap.top();
//            heap.pop();
//            total += cur[1] / cur[2];
//        }
//        total /= classes.size();
//        return total;
//    }
//};