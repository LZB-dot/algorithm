//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//    int twoCitySchedCost(vector<vector<int>>& costs) {
//        int n = costs.size();
//        int sum = 0;
//        vector<int>tmp;
//        for (const auto& c : costs) {
//            sum += c[0];
//            tmp.push_back(c[1] - c[0]);
//        }
//        sort(tmp.begin(), tmp.end());
//    
//        int m = n >> 1;
//        for (int i = 0; i < m; ++i) {
//            sum += tmp[i];
//        }
//
//        return sum;
//    }
//};