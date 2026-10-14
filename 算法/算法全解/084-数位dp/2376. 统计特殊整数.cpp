//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//private:
//    int cnt[10];
//    int digit = 0;
//    int dp[10][1 << 10][2];
//    vector<int>num;
//
//    void Init(int n) {
//        while (n) {
//            num.push_back(n % 10);
//            n /= 10;
//        }
//        reverse(num.begin(), num.end());
//        digit = num.size();
//        cnt[1] = 9;
//        for (int i = 2, k = 9; i < digit; ++i, --k) {
//            cnt[i] = cnt[i - 1] * k;
//        }
//        memset(dp, -1, sizeof(dp));
//    }
//
//    int dfs(int pos, int mask, int free) {
//        if (pos == digit)
//            return mask != 0;
//
//        if (dp[pos][mask][free] != -1) {
//            return dp[pos][mask][free];
//        }
//        int res = 0;
//        if (free) {
//            //ÊÇÊ×Î»
//            if (mask == 0) {
//                for (int i = 1; i < num[pos]; ++i)
//                    res += dfs(pos + 1, mask | (1 << i), 1);
//                res += dfs(pos + 1, mask | (1 << num[pos]), 0);
//            }
//            else {
//                for (int i = 0; i <= 9; ++i)
//                    if (!(mask & (1 << i)))
//                        res += dfs(pos + 1, mask | (1 << i), 1);
//            }
//        }
//        else {
//            for (int i = 0; i < num[pos]; ++i)
//                if (!(mask & (1 << i)))
//                    res += dfs(pos + 1, mask | (1 << i), 1);
//            if (!(mask & (1 << num[pos])))
//                res += dfs(pos + 1, mask | (1 << num[pos]), 0);
//        }
//
//        return dp[pos][mask][free] = res;
//    }
//    
//public:
//    int countSpecialNumbers(int n) {
//        int res = 0;
//        Init(n);
//        for (int i = 1; i < digit; ++i)
//            res += cnt[i];
//
//        res += dfs(0, 0, 1);
//        return res;
//    }
//};