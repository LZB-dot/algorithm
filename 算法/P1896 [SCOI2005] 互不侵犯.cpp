//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//int n, k;
//vector<int> valid;
//long long memo[10][90][1 << 10];
//
//
//bool check(int s) {
//    return !(s & (s << 1));
//}
//
//int count_king(int s) {
//    int ans = 0;
//    while (s) {
//        ans += s & 1;
//        s >>= 1;
//    }
//    return ans;
//}
//
//long long dfs(int row, int pre, int cnt) {
//    if (memo[row][cnt][pre] != -1) {
//        return memo[row][cnt][pre];
//    }
//
//    if (row == n) {
//        return (cnt == k) ? 1 : 0; 
//    }
//
//    long long total = 0;
//    for (int i : valid) {
//        if ((pre & i) || (pre & (i << 1)) || (pre & (i >> 1))) {
//            continue;
//        }
//        int cur_cnt = cnt + count_king(i);
//        if (cur_cnt > k) {
//            continue;
//        }
//        total += dfs(row + 1, i, cur_cnt);
//    }
//
//    memo[row][cnt][pre] = total;
//    return total;
//}
//
//int main() {
//    cin >> n >> k;
//
//    for (int i = 0; i < (1 << n); ++i) {
//        if (check(i)) {
//            valid.push_back(i);
//        }
//    }
//
//    for (int i = 0; i < 10; ++i) {
//        for (int j = 0; j < 90; ++j) {
//            for (int l = 0; l < (1 << 10); ++l) {
//                memo[i][j][l] = -1;
//            }
//        }
//    }
//
//    cout << dfs(0, 0, 0) << endl;
//    return 0;
//}