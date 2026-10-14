//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//const int MAXT = 1005;
//int dp[MAXT];
//vector<int> w, v, c;
//int n, m;
//string start_time, end_time;
//
//int getM() {
//    size_t colon_pos = start_time.find(':');
//    int h1 = stoi(start_time.substr(0, colon_pos));
//    int m1 = stoi(start_time.substr(colon_pos + 1));
//
//    colon_pos = end_time.find(':');
//    int h2 = stoi(end_time.substr(0, colon_pos));
//    int m2 = stoi(end_time.substr(colon_pos + 1));
//
//    return (h2 * 60 + m2) - (h1 * 60 + m1);
//}
//
//int compute() {
//    memset(dp, 0, sizeof(dp));
//
//    for (int i = 0; i < w.size(); ++i) {
//        if (c[i] == -1) {
//            // 完全背包：从小到大遍历
//            for (int j = w[i]; j <= m; ++j) {
//                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//            }
//        }
//        else {
//            // 0-1背包：从大到小遍历
//            for (int j = m; j >= w[i]; --j) {
//                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//            }
//        }
//    }
//
//    // 最大美学值是dp[0...m]中的最大值
//    int max_beauty = 0;
//    for (int j = 0; j <= m; ++j) {
//        max_beauty = max(max_beauty, dp[j]);
//    }
//    return max_beauty;
//}
//
//int main() {
//    cin >> start_time >> end_time >> n;
//    m = getM();
//
//    for (int i = 1; i <= n; ++i) {
//        int cost, val, cnt;
//        cin >> cost >> val >> cnt;
//        if (cnt == 0) {
//            // 完全背包物品
//            w.push_back(cost);
//            v.push_back(val);
//            c.push_back(-1); // 正确地添加标记
//        }
//        else {
//            // 多重背包物品，进行二进制优化
//            for (int k = 1; k <= cnt; k <<= 1) {
//                w.push_back(k * cost);
//                v.push_back(k * val);
//                c.push_back(1); // 标记为0-1背包物品 (值可以是任意非-1值)
//                cnt -= k;
//            }
//            if (cnt > 0) {
//                w.push_back(cnt * cost);
//                v.push_back(cnt * val);
//                c.push_back(1); // 同样标记为0-1背包物品
//            }
//        }
//    }
//
//    cout << compute() << endl;
//    return 0;
//}