////#include<iostream>
////#include<vector>
////using namespace std;
////
////class Solution {
////public:
////    int sumSubarrayMins(vector<int>& arr) {
////        const int N = 1e9 + 7;
////        int n = arr.size();
////        long ans = 0;
////        vector<int>stk;
////        for (int i = 0; i < n; ++i) {
////            //大压小
////            //遇到小于等于栈顶元素则弹出
////            while (!stk.empty() &&
////                arr[stk.back()] >= arr[i]) {
////                //i此时为右边第一个小于等于arr[tmp]的下标
////                int tmp = stk.back();
////                stk.pop_back();
////                //左边第一个小于arr[tmp]的下标
////                int l = stk.empty() ? -1 : stk.back();
////                //左区间*右区间*当前值
////                ans = (ans + (long)(tmp - l) * (i - tmp) * arr[tmp]) % N;
////            }
////            stk.push_back(i);
////        }
////
////        while (!stk.empty()) {
////            int tmp = stk.back();
////            stk.pop_back();
////            int l = stk.empty() ? -1 : stk.back();
////            ans = (ans + (long)(tmp - l) * (n - tmp) * arr[tmp]) % N;
////        }
////
////        return (int)ans;
////    }
////};
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 3e4 + 10;
//const int MOD = 1e9 + 7;
//
//class Solution {
//private:
//    int st[MAXN];
//    int r = 0;
//
//
//public:
//    int sumSubarrayMins(vector<int>& arr) {
//        int n = arr.size();
//
//        vector<int>left_(n, 0), right_(n, 0);
//
//        r = 0;
//        for (int i = 0; i < n; ++i) {
//            while (r != 0 && arr[st[r - 1]] >= arr[i]) {
//                int top = st[--r];
//                right_[top] = i;
//                left_[top] = (r == 0 ? -1 : st[r - 1]);
//            }
//
//            st[r++] = i;
//        }
//
//        while (r != 0) {
//            int top = st[--r];
//            right_[top] = n;
//            left_[top] = (r == 0 ? -1 : st[r - 1]);
//        }
//
//
//        ll ans = 0;
//        for (int i = 0; i < n; ++i) {
//            ll cnt = (ll)(i - left_[i]) * (right_[i] - i) % MOD;
//            ans = (ans + cnt * arr[i]) % MOD;
//        }
//
//        return ans;
//    }
//};