//#include<iostream>
//#include<vector>
//using namespace std;
//
//class NumMatrix {
//private:
//    vector<vector<int> >sum;
//public:
//    NumMatrix(vector<vector<int>>& matrix) {
//        if (matrix.empty() || matrix[0].empty()) {
//            return;
//        }
//
//        int n = matrix.size();
//        int m = matrix[0].size();
//
//        sum.resize(n + 1, vector<int>(m + 1, 0));
//
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= m; ++j) {
//                sum[i][j] = matrix[i - 1][j - 1];
//            }
//        }
//
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= m; ++j) {
//                sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
//            }
//        }
//    }
//
//    int sumRegion(int row1, int col1, int row2, int col2) {
//        int i1 = row1 + 1;
//        int i2 = row2 + 1;
//        int j1 = col1 + 1;
//        int j2 = col2 + 1;
//        return sum[i2][j2] - sum[i2][j2 - 1] - sum[i2 - 1][j2] + sum[i1 - 1][j1 - 1];
//    }
//};
//
