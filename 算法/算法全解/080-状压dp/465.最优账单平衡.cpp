//#include<iostream>
//#include<vector>
//#include<cstring>  
//#include<algorithm> 
//using namespace std;
//
//class Solution {
//private:
//    const int MAXN = 13;
//    vector<int> debt; // 存储非零债务的数组
//    int n; // 非零债务的人数
//    int dp[1 << 12]; // dp[status]：状态status下最多能分成多少个和为0的子集合
//
//    // 计算状态status对应的债务总和
//    int getSum(int status) {
//        int sum = 0;
//        for (int i = 0; i < n; ++i) {
//            if (status & (1 << i)) {
//                sum += debt[i];
//            }
//        }
//        return sum;
//    }
//
//    // dfs：计算状态status下最多能分成多少个和为0的子集合
//    int dfs(int status) {
//        if (status == 0) { // 基准状态：空集，子集合数为0
//            return 0;
//        }
//        if (dp[status] != -1) { // 记忆化：已计算过，直接返回
//            return dp[status];
//        }
//
//        int maxGroups = 0;
//        // 枚举status的所有非空子集（不包括自身，避免重复计算）
//        int sub = (status - 1) & status;
//        while (sub > 0) {
//            // 若子集sub的债务和为0，则可以作为一个独立子集合
//            if (getSum(sub) == 0) {
//                // 剩余状态：status ^ sub（去掉sub的位）
//                maxGroups = max(maxGroups, 1 + dfs(status ^ sub));
//            }
//            sub = (sub - 1) & status;
//        }
//
//        dp[status] = maxGroups;
//        return maxGroups;
//    }
//
//    // 预处理：提取非零债务
//    vector<int> getDebt(const vector<vector<int>>& transactions) {
//        vector<int> help(MAXN, 0);
//        for (auto& it : transactions) {
//            int from = it[0], to = it[1], money = it[2];
//            help[from] -= money; // 转出，债务减少
//            help[to] += money;   // 转入，债务增加
//        }
//        vector<int> ans;
//        for (int num : help) {
//            if (num != 0) { // 只保留非零债务
//                ans.push_back(num);
//            }
//        }
//        return ans;
//    }
//
//public:
//    int minTransfers(vector<vector<int>>& transactions) {
//        debt = getDebt(transactions);
//        n = debt.size();
//        if (n == 0) { // 边界：无债务，无需转账
//            return 0;
//        }
//        if (n == 1) { // 边界：仅1人有债务，无法转账（逻辑上不可能，返回0或按题意处理）
//            return 0;
//        }
//
//        // 初始化dp数组：-1表示未计算
//        memset(dp, -1, sizeof(dp));
//        // 全量状态：(1 << n) - 1（所有位为1，表示所有人）
//        int fullStatus = (1 << n) - 1;
//        int maxGroups = dfs(fullStatus);
//        // 最少转账次数 = 总人数 - 最大子集合数
//        return n - maxGroups;
//    }
//};
