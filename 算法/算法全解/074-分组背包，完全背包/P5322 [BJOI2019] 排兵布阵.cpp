//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cctype>
//#include<cstdio>
//using namespace std;
//
//inline int read() {
//    char c;
//    int num = 0;
//
//    while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
//
//    bool flag = false;
//    if (c == '-') 
//        flag = true;
//    else
//        num = c - '0';
//
//    while (isdigit(c = getchar())) 
//        num = num * 10 + c - '0';
//
//    return flag ? -num : num;
//}
//
//const int MAXN = 105;
//const int MAXM = 20005;
//
//int s, n, m;
////第i个城堡，击败前k个对手需要的最大对手派兵数
//int mxcost[MAXN][MAXN];
////使用j个士兵时的最大得分
//int dp[MAXM];
//
//int main() {
//    s = read();
//    n = read();
//    m = read();
//
//    vector<vector<int>> opp(s, vector<int>(n)); 
//    for (int i = 0; i < s; ++i) 
//        for (int j = 0; j < n; ++j) 
//            opp[i][j] = read();
//
//
//    for (int i = 0; i < n; ++i) { //遍历每个城堡
//        vector<int> tmp;
//        for (int j = 0; j < s; ++j) { 
//            tmp.push_back(opp[j][i]);
//        }
//        sort(tmp.begin(), tmp.end(), greater<int>());
//
//        mxcost[i][0] = 0; // 击败0个对手，无需士兵
//
//        for (int k = 1; k <= s; ++k) { //击败前k个对手，最大派兵数是tmp[k-1]
//            mxcost[i][k] = tmp[k - 1];
//        }
//    }
//
//    fill(dp, dp + m + 1, 0); 
//    for (int i = 0; i < n; ++i) { 
//        int id = i + 1; 
//        for (int j = m; j >= 0; --j) {
//            for (int k = 0; k <= s; ++k) {
//                int cost = 2 * mxcost[i][k] + 1; // 击败k个对手需要的士兵数
//                if (k == 0) 
//                    cost = 0; // 击败0个对手，无需士兵
//                if (cost > j) 
//                    continue; // 士兵数不足，跳过
//                int score = id * k; // 击败k个对手的得分
//                dp[j] = max(dp[j], dp[j - cost] + score);
//            }
//        }
//    }
//
//    cout << dp[m] << endl;
//
//    return 0;
//}