//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//const int N = 12;          
//const int MOD = 1e8;
//int n, m;                  
//vector<int> mp;            //存储每一行的土地状态（1表示可种植）
//vector<int> valid;         //存储所有合法的单行状态（无相邻1）
//int memo[N][1 << N];       //第row行状态为state时的方案数
//
//// 检查单行状态是否合法（无相邻的1）
//bool check(int s) {
//    return !(s & (s << 1));
//}
//
//int dfs(int row, int pre_state) {
//    if (row == n) {
//        return 1;
//    }
//
//    if (memo[row][pre_state] != -1) {
//        return memo[row][pre_state];
//    }
//
//    int total = 0;
//    //遍历所有合法的单行状态
//    for (int cur_state : valid) {
//        //当前状态不能种植在贫瘠的土地上
//        if ((cur_state & mp[row]) != cur_state)
//            continue;
//       
//        //当前状态和上一行状态无相邻（上下无相邻）
//        if (cur_state & pre_state)
//            continue;
//      
//        // 递归处理下一行，累加方案数
//        total = (total + dfs(row + 1, cur_state)) % MOD;
//    }
//
//    memo[row][pre_state] = total;
//    return total;
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
//    int tmp;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> tmp;
//            if (tmp == 1) {
//                mp[i] |= (1 << j);
//            }
//        }
//    }
//
//    // 预处理所有合法的单行状态
//    for (int i = 0; i < (1 << m); ++i) {
//        if (check(i)) {
//            valid.push_back(i);
//        }
//    }
//
//    cout << dfs(0, 0) << endl;
//    return 0;
//}