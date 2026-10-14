//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//
//class Solution {
//private:
//    int path[10];
//    vector<vector<string>>ans;
//
//    bool check(int i, int j) {
//        for (int k = 0; k < i; ++k) {
//            if (path[k] == j || abs(i - k) == abs(j - path[k]))
//                return false;
//        }
//        return true;
//    }
//
//    void digui(int n, int i) {
//        if (i == n) {
//            vector<string>tmp;
//            for (int j = 0; j < n; ++j) {
//                string line(n, '.');
//                line[path[j]] = 'Q';
//                tmp.push_back(line);
//            }
//            ans.push_back(tmp);
//            return;
//        }
//
//        for (int j = 0; j < n; ++j) {
//            if (check(i, j)) {
//                path[i] = j;
//                digui(n, i + 1);
//            }
//        }
//    }
//public:
//    vector<vector<string>> solveNQueens(int n) {
//        if (n <= 0)
//            return ans;
//        digui(n, 0);
//        return ans;
//    }
//};