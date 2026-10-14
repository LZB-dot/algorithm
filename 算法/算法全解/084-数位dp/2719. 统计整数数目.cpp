//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm> 
//using namespace std;
//
//const int MOD = 1e9 + 7;
//
//class Solution {
//private:
//    vector<int> num;
//    int len = 0;
//    vector<vector<vector<int>>> dp;
//    int mi, mx;
//
//    //pos 下标    sum 当前digit和    limit 是否受限（1受限，0自由）
//    int dfs(int pos, int sum, int limit) {
//        //和超过最大值
//        if (sum > mx) {
//            return 0;
//        }
//        //剩余数位全取9也达不到最小值
//        if (sum + (len - pos) * 9 < mi) {
//            return 0;
//        }
//        //所有位处理完毕
//        if (pos == len) {
//            return 1;
//        }
//        if (dp[pos][sum][limit] != -1) {
//            return dp[pos][sum][limit];
//        }
//
//        int res = 0;
//        // 当前位能取的最大值
//        int upper = limit ? num[pos] : 9;
//
//        //枚举当前位的所有可能值
//        for (int i = 0; i <= upper; ++i) {
//            int new_limit = (limit && (i == upper)) ? 1 : 0;
//            res = (res + dfs(pos + 1, sum + i, new_limit)) % MOD;
//        }
//
//        return dp[pos][sum][limit] = res;
//    }
//
//    //计算[0, s]范围内符合条件的数字数目
//    int count(const string& s) {
//        num.clear();
//        for (char c : s) {
//            num.push_back(c - '0');
//        }
//        len = num.size();
//        dp = vector<vector<vector<int>>>(len, vector<vector<int>>(405, vector<int>(2, -1)));
//        return dfs(0, 0, 1);
//    }
//
//    // 检查num1本身是否符合条件
//    bool check(const string& n) {
//        int sum = 0;
//        for (char c : n) {
//            sum += c - '0';
//            if (sum > mx) {
//                return false;
//            }
//        }
//        return sum >= mi && sum <= mx;
//    }
//
//public:
//    int count(string num1, string num2, int min_sum, int max_sum) {
//        mi = min_sum;
//        mx = max_sum;
//        int cnt2 = count(num2);
//        int cnt1 = count(num1);
//        int border = check(num1) ? 1 : 0;
//        int res = (cnt2 - cnt1 + border + MOD) % MOD;
//
//        return res;
//    }
//};
