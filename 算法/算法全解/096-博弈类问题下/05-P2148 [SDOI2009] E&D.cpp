//#include<iostream>
//#include<cstring>
//#include<vector>
//using namespace std;
//
//const int MAXN = 1001;
//int dp[MAXN][MAXN];
//
//// 计算二进制数num中最低位0的位置（从0开始）
//int lowZero(int num) {
//    int cnt = 0;
//    while (num > 0) {
//        if ((num & 1) == 0) {
//            break;
//        }
//        num >>= 1;
//        cnt++;
//    }
//    return cnt;
//}
//
//// 记忆化搜索计算SG(a,b)
//int sg(int a, int b) {
//    // 必败态：两堆都是1时无法操作
//    if (a == 1 && b == 1) {
//        return 0;
//    }
//    // 记忆化：已经计算过的状态直接返回
//    if (dp[a][b] != -1) {
//        return dp[a][b];
//    }
//
//    // 计算后继状态的SG值出现情况
//    int max_val = max(a, b);
//    vector<bool>appear(max_val + 1);
//    fill(appear.begin(), appear.end(), false);
//
//    // 分割a堆（a>1时，分割成l和r，l + r = a）
//    if (a > 1) {
//        for (int l = 1, r = a - 1; l < a; l++, r--) {
//            appear[sg(l, r)] = true;
//        }
//    }
//
//    // 分割b堆（b>1时，分割成l和r，l + r = b）
//    if (b > 1) {
//        for (int l = 1, r = b - 1; l < b; l++, r--) {
//            appear[sg(l, r)] = true;
//        }
//    }
//
//    // 计算mex：最小的未出现的非负整数
//    int mex = 0;
//    while (mex <= max_val && appear[mex]) {
//        mex++;
//    }
//
//    dp[a][b] = mex;
//    return mex;
//}
//
//// 打印石子数9以内所有组合的SG值表
//void printSGTable() {
//    cout << "石子数9以内所有组合的sg值：" << endl << endl;
//    cout << "   ";
//    for (int i = 1; i <= 9; i++) {
//        cout << i << " ";
//    }
//    cout << endl << endl;
//
//    for (int a = 1; a <= 9; a++) {
//        cout << a << "  ";
//        // 上三角部分打印X，只计算b >= a的情况
//        for (int b = 1; b < a; b++) {
//            cout << "X ";
//        }
//        for (int b = a; b <= 9; b++) {
//            cout << sg(a, b) << " ";
//        }
//        cout << endl;
//    }
//}
//
//// 验证SG值规律是否正确
//void verifyRule() {
//    cout << endl << "验证SG值规律：" << endl;
//    bool correct = true;
//    for (int a = 1; a < MAXN; a++) {
//        for (int b = 1; b < MAXN; b++) {
//            int sg_val = sg(a, b);
//            int rule_val = lowZero((a - 1) | (b - 1));
//            if (sg_val != rule_val) {
//                cout << "错误：sg(" << a << "," << b << ") = " << sg_val
//                    << "，但按规律计算应为 " << rule_val << endl;
//                correct = false;
//                break;
//            }
//        }
//        if (!correct) break;
//    }
//    if (correct) {
//        cout << "所有状态验证通过！规律 sg(a,b) = lowZero( (a-1)|(b-1) ) 成立。" << endl;
//    }
//}
//
//// 处理多组输入的主逻辑
//void solve() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    // 初始化记忆化数组
//    memset(dp, -1, sizeof(dp));
//
//    // 可选：打印SG表和验证规律
//    // printSGTable();
//    // verifyRule();
//
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        int xor_sum = 0;
//
//        // 每两堆为一组
//        for (int i = 0; i < n / 2; i++) {
//            int a, b;
//            cin >> a >> b;
//            int sg_val = lowZero((a - 1) | (b - 1));
//            xor_sum ^= sg_val;
//        }
//
//        if (xor_sum != 0) {
//            cout << "YES" << endl;
//        }
//        else {
//            cout << "NO" << endl;
//        }
//    }
//}
//
//int main() {
//    solve();
//    return 0;
//}