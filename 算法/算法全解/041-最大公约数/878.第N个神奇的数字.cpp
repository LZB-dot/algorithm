//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//private:
//    int gcd(int a, int b) {
//        if (b == 0)
//            return a;
//        else
//            return gcd(b, a % b);  
//    }
//
//    int lcm(int a, int b) {
//        return a / gcd(a, b) * b; 
//    }
//
//public:
//    int nthMagicalNumber(int n, int a, int b) {
//        const long long MOD = 1e9 + 7;
//        long long l = 1;
//        long long r = (long long)n * min(a, b); 
//
//        while (l < r) {
//            long long mid = l + (r - l) / 2;  
//            long long count = mid / a + mid / b - mid / lcm(a, b);
//
//            if (count < n)
//                l = mid + 1;
//            else 
//                r = mid;
//        }
//
//        return (int)(l % MOD);
//    }
//};