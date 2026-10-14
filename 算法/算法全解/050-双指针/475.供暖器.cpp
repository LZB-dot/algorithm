//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//    int findRadius(vector<int>& houses, vector<int>& heaters) {
//        sort(houses.begin(), houses.end());
//        sort(heaters.begin(), heaters.end());
//        
//        int ans = 0;
//        int l = 0, r = 0;
//        for (int i = 0; i < houses.size(); ++i) {
//            int j = 0;
//            while (j < heaters.size() && heaters[j] < houses[i]) {
//                ++j;
//            }
//            int dis1 = j == 0 ? INT_MAX : abs(heaters[j - 1] - houses[i]);
//            int dis2 = j == houses.size() ? INT_MAX : abs(heaters[j] - houses[i]);
//            ans = max(ans, min(dis2, dis1));
//        }
//        return ans;
//    }
//};