//#include<iostream>
//#include<vector>
//#include<algorithm>  
//#include<climits>  
//using namespace std;
//
//class Solution {
//private:
//    vector<vector<int>> mp;  // 存储每个字符出现的所有位置
//    vector<vector<int>> dp;  // dp[i][j]：转盘在i位置，拼key[j..m-1]的最小步数
//    int n, m;                // n:ring长度，m:key长度
//
//    void build(const string& ring, const string& key) {
//        n = ring.size();
//        m = key.size();
//        mp.resize(26); 
//
//        // 记录每个字符在ring中的所有位置
//        for (int i = 0; i < n; ++i) {
//            int ch = ring[i] - 'a';
//            mp[ch].push_back(i);
//        }
//
//        dp.resize(n, vector<int>(m, -1));
//    }
//
//    // 当前转盘位置idx，需要拼key[len...]的最小步数
//    int dfs(const string& ring, const string& key, int idx, int len) {
//        // 终止条件：key全部拼完
//        if (len == m) {
//            return 0;
//        }
//
//        // 已计算过，直接返回
//        if (dp[idx][len] != -1) {
//            return dp[idx][len];
//        }
//
//        int target = key[len] - 'a';
//        // 当前位置已经是目标字符，直接拼下一个
//        if (ring[idx] - 'a' == target) {
//            return dp[idx][len] = 1 + dfs(ring, key, idx, len + 1);
//        }
//
//        int res = INT_MAX;
//        const vector<int>& pos_list = mp[target];  //目标字符的所有位置
//        int size = pos_list.size();
//
//        //顺时针找最近的目标位置
//        //找到第一个大于idx的位置，没有则返回末尾迭代器
//        auto it = upper_bound(pos_list.begin(), pos_list.end(), idx);
//        //找不到说明该位置是末尾的，此时选择开头位置
//        int clock_pos = (it == pos_list.end()) ? pos_list[0] : *it;
//        //顺时针转动的步数
//        int clock_step = (clock_pos - idx + n) % n;
//        res = min(res, clock_step + 1 + dfs(ring, key, clock_pos, len + 1));
//
//        //逆时针找最近的目标位置
//        //找到第一个大于等于idx的位置，一定会找到
//        it = lower_bound(pos_list.begin(), pos_list.end(), idx);
//        int counter_pos;
//        //在开头逆时针就是末尾数
//        if (it == pos_list.begin()) {
//            counter_pos = pos_list.back(); 
//        }
//        //不在开头就是前一个位置
//        else {
//            counter_pos = *(prev(it));      
//        }
//        //逆时针转动的步数
//        int counter_step = (idx - counter_pos + n) % n;
//        res = min(res, counter_step + 1 + dfs(ring, key, counter_pos, len + 1));
//
//        // 记忆化存储结果
//        return dp[idx][len] = res;
//    }
//
//public:
//    int findRotateSteps(string ring, string key) {
//
//        build(ring, key);
//        return dfs(ring, key, 0, 0);
//    }
//};
