//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
////开静态数组内存太大
////开map是动态存储实际少很多
//
//class Solution {
//public:
//    unordered_map<int, int>mp;
//
//    int f(int n) {
//        if (n <= 1)
//            return n;
//        if (mp.count(n) != 0) {
//            return mp[n];
//        }
//        int p1 = n % 2 + 1 + f(n >> 1);
//        int p2 = n % 3 + 1 + f(n / 3);
//        mp[n] = min(p1, p2);
//        return mp[n];
//    }
//    int minDays(int n) {
//        return f(n);
//    }
//};
//
//
