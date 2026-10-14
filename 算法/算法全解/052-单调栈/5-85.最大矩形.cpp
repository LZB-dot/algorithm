//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 1e5;
//
//class Solution {
//private:
//    int st[MAXN];
//    int r = 0;
//
//public:
//    int maximalRectangle(vector<vector<char>>& matrix) {
//        int n = matrix.size();
//        int m = matrix[0].size();
//
//        vector<int>a(m, 0);
//        int ans = 0;
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                int t = matrix[i][j] - '0';
//
//                if (t == 0)
//                    a[j] = 0;
//                else
//                    a[j]++;
//            }
//
//            int sum = 0;
//            for (int k = 0; k < m; ++k) {
//                while (r > 0 && a[st[r - 1]] >= a[k]) {
//                    int top = st[--r];
//                    int l = r != 0 ? st[r - 1] : -1;
//                    int h = a[top];
//                    int len = k - l - 1;
//                    sum = max(sum, h * len);
//                }
//
//                st[r++] = k;
//            }
//
//            while (r > 0) {
//                int top = st[--r];
//                int l = r != 0 ? st[r - 1] : -1;
//                int h = a[top];
//                int len = m - l - 1;
//                sum = max(sum, h * len);
//            }
//
//            ans = max(sum, ans);
//        }
//
//        return ans;
//    }
//};
//
//
//
