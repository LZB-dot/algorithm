//
//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//const int N = 105;
//const int M = 12;
//
//int n, m;
//vector<int> mp;          //mp[i]表示第i行的地形（1=山地H，0=平原P）
//int memo[N][N][N];       // memo[行号][上一行状态索引][上两行状态索引]
//vector<int> cnt;         // cnt[i] = valid[i]状态的炮兵数量
//vector<int> valid;       // 存储所有单行合法的状态（二进制数）
//int num = 0;             // 合法状态的总数
//
//// 检查单行状态是否合法（无相邻/间隔1列的炮兵）
//bool check(int s) {
//    if (s & (s << 1)) 
//        return false;
//    if (s & (s << 2)) 
//        return false;
//    return true;
//}
//
//// 统计状态中1的个数（炮兵数量）
//int count_(int s) {
//    int ans = 0;
//    while (s) {
//        if (s & 1) ans++;
//        s >>= 1;
//    }
//    return ans;
//}
//
////cur=当前行号，pre1_idx=上一行状态索引，pre2_idx=上两行状态索引
//int dfs(int cur, int pre1_idx, int pre2_idx) {
//    //所有行处理完毕
//    if (cur == n) {
//        return 0;
//    }
//
//    //记忆化
//    if (memo[cur][pre1_idx][pre2_idx] != -1) {
//        return memo[cur][pre1_idx][pre2_idx];
//    }
//
//    int max_ans = 0;
//    int pre1_state = valid[pre1_idx]; //上一行的状态值
//    int pre2_state = valid[pre2_idx]; //上两行的状态值
//
//    // 枚举当前行的所有合法状态
//    for (int i = 0; i < num; ++i) {
//        int cur_state = valid[i]; // 当前行的状态值
//
//        //两者都有1则代表冲突
//        //当前状态是否与地形冲突（炮兵不在山地）
//        if (cur_state & mp[cur]) 
//            continue;
//        //当前状态与上一行无冲突
//        if (cur_state & pre1_state)
//            continue;
//        //当前状态与上两行无冲突
//        if (cur_state & pre2_state) 
//			  continue;
//
//        // 递归处理下一行
//        int total = cnt[i] + dfs(cur + 1, i, pre1_idx);
//        max_ans = max(max_ans, total);
//    }
//
//    // 记录记忆化结果
//    memo[cur][pre1_idx][pre2_idx] = max_ans;
//    return max_ans;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> m;
//    mp.resize(n, 0);
//    memset(memo, -1, sizeof(memo));
//
//    for (int i = 0; i < n; ++i) {
//        string s;
//        cin >> s;
//        for (int j = 0; j < m; ++j) {
//            if (s[j] == 'H') { // 山地设为1，平原默认0
//                mp[i] |= (1 << j);
//            }
//        }
//    }
//
//    // 预处理合法状态
//    for (int state = 0; state < (1 << m); ++state) {
//        if (check(state)) {
//            valid.push_back(state);
//            cnt.push_back(count_(state));
//        }
//    }
//    num = valid.size(); 
//
//    // 找到状态0的索引（虚拟前两行）
//    int zero_idx = 0;
//    for (int i = 0; i < num; ++i) {
//        if (valid[i] == 0) {
//            zero_idx = i;
//            break;
//        }
//    }
//
//    cout << dfs(0, zero_idx, zero_idx) << endl;
//
//    return 0;
//}