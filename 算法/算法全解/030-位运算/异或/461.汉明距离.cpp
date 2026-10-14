//#include<iostream>
//using namespace std;
//
//
//class Solution {
//public:
//    int hammingDistance(int x, int y) {
//        return cntOnes(x ^ y);
//    }
//
//    int cntOnes(int n) {
//        n = (n & 0x55555555) + (((unsigned int)n >> 1) & 0x55555555);
//        n = (n & 0x33333333) + (((unsigned int)n >> 2) & 0x33333333);
//        n = (n & 0x0f0f0f0f) + (((unsigned int)n >> 4) & 0x0f0f0f0f);
//        n = (n & 0x00ff00ff) + (((unsigned int)n >> 8) & 0x00ff00ff);
//        n = (n & 0x0000ffff) + (((unsigned int)n >> 16) & 0x0000ffff);
//        return n;
//    }
//};