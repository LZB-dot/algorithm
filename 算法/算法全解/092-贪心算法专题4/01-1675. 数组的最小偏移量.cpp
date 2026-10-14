//
//#include<iostream>
//#include<vector>
//#include<set>
//using namespace std;
//
//class Solution {
//public:
//    int minimumDeviation(vector<int>& nums) {
//        int res = 0;
//        set<int>s;
//        for (int num : nums) {
//            if (num % 2 == 0)
//                s.insert(num);
//            else
//                s.insert(num << 1);
//        }
//
//        res = *s.rbegin() - *s.begin();
//
//        while (res > 0 && *s.rbegin() % 2 == 0) {
//            int tmp = *s.rbegin();
//            s.erase(prev(s.end()));
//            s.insert(tmp >> 1);
//            res = min(res, *s.rbegin() - *s.begin());
//        }
//
//        return res;
//    }
//};