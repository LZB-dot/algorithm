//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//    int flip(int n) {
//        return n ^ 1;//0变1，1变0
//    }
//
//    int sign(int n) {
//        return flip((unsigned int)n >> 31);
//        //改成无符号整型，右移到符号位
//        //非负数为0，负数为1
//        //异或后非负数为1，负数为0
//    }
//
//    int getMax(int a, int b) {
//        int c = a - b;
//        int sa = sign(a);
//        int sb = sign(b);
//        int sc = sign(c);
//        int difAB = sa ^ sb;//符号相同为0，不同为1
//        int sameAB = flip(difAB);
//        int returnA = difAB * sa + sameAB * sc;
//        int returnB = flip(returnA);
//        return a * returnA + b * returnB;
//
//
//    }
//};