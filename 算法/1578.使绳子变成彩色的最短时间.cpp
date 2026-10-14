//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//    int minCost(string colors, vector<int>& neededTime) {
//        int n = colors.size();
//        if (n <= 1) 
//            return 0;
//
//        int total = 0;       
//        int mx = 0; 
//        int sum = 0;   
//
//        for (int i = 0; i < n; ++i) {
//            // 若与前一个气球颜色相同，累加当前组的时间
//            if (i > 0 && colors[i] == colors[i - 1]) {
//                sum += neededTime[i];
//                mx = max(mx, neededTime[i]);
//            }
//            else {
//                total += sum - mx;
//                // 重置当前组的总和和最大时间（新组从当前气球开始）
//                sum = neededTime[i];
//                mx = neededTime[i];
//            }
//        }
//        total += sum - mx;
//
//        return total;
//    }
//};