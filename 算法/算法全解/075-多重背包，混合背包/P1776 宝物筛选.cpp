//////#include<iostream>
//////#include<vector>
//////using namespace std;
//////
//////
//////
//////int main() {
//////	int n, m;
//////	cin >> n >> m;
//////	vector<int>v(n + 1), w(n + 1), c(n + 1);
//////	for (int i = 1; i <= n; ++i) {
//////		cin >> w[i] >> v[i] >> c[i];
//////	}
//////
//////	vector<int>dp(m + 1, 0);
//////	for (int i = 1; i <= n; ++i) {
//////		for (int j = m; j >= 0; --j) {
//////			for (int k = 1; k <= c[i] && k * w[i] <= j; ++k) {
//////				dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
//////			}
//////		}
//////	}
//////
//////	cout << dp[m];
//////	return 0;
//////}
////
////
//////二进制优化
//////核心：将数量为c的物品拆分成二进制组合（5：1 2 2），
//////使这些组合可以覆盖1-c的所有数量
////
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////
////int main() {
////    int n, t;
////    cin >> n >> t;
////
////    vector<int> weights, values;
////
////    for (int i = 0; i < n; ++i) {
////        int wi, vi, ci;
////        cin >> vi >> wi >> ci;
////
////        // 二进制拆分：k = 1, 2, 4, 8, ...
////        int k = 1;
////        while (k <= ci) {
////            weights.push_back(k * wi);
////            values.push_back(k * vi);
////            ci -= k;
////            k <<= 1;   
////        }
////        if (ci > 0) {
////            weights.push_back(ci * wi);
////            values.push_back(ci * vi);
////        }
////    }
////
////    // 0-1 背包
////    vector<int> dp(t + 1, 0);
////    for (int i = 0; i < weights.size(); ++i) {
////        for (int j = t; j >= weights[i]; --j) {
////            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
////        }
////    }
////
////    cout << dp[t] << endl;
////    return 0;
////}
//
//
//#include <iostream>
//#include <vector>
//#include <deque>
//#include <algorithm>
//#include <climits>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, W;
//    cin >> n >> W;
//
//    vector<int> v(n), w(n), c(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> v[i] >> w[i] >> c[i];  // 注意顺序：v, w, c
//    }
//
//    vector<int> dp(W + 1, 0);  // 初始化为 0，不要求恰好装满
//
//    for (int i = 0; i < n; ++i) {
//        if (w[i] == 0) {  // 防止除零（题目通常保证 w>0）
//            int add = c[i] * v[i];
//            for (int j = 0; j <= W; ++j) {
//                dp[j] += add;
//            }
//            continue;
//        }
//
//        vector<int> new_dp = dp;  // 基于上一轮结果更新
//
//        // 按余数分类
//        for (int r = 0; r < w[i]; ++r) {
//            deque<int> dq;  // 存储下标 j
//            for (int j = r, mult = 0; j <= W; j += w[i], ++mult) {
//                // 维护窗口：最多选 c[i] 个，即 j - k*w[i] >= j - c[i]*w[i]
//                while (!dq.empty() && dq.front() < j - c[i] * w[i]) {
//                    dq.pop_front();
//                }
//
//                // 如果队列非空，尝试更新
//                if (!dq.empty()) {
//                    int best_j = dq.front();
//                    int cnt = (j - best_j) / w[i];
//                    new_dp[j] = max(new_dp[j], dp[best_j] + cnt * v[i]);
//                }
//
//                // 将当前 j 加入队列，维护单调递减（按 dp[j] - mult * v[i]）
//                while (!dq.empty()) {
//                    int last_j = dq.back();
//                    int last_mult = (last_j - r) / w[i];
//                    // 比较 dp[last_j] - last_mult * v[i] 和 dp[j] - mult * v[i]
//                    if (dp[last_j] - last_mult * v[i] <= dp[j] - mult * v[i]) {
//                        dq.pop_back();
//                    }
//                    else {
//                        break;
//                    }
//                }
//                dq.push_back(j);
//            }
//        }
//
//        dp = move(new_dp);
//    }
//
//    cout << *max_element(dp.begin(), dp.end()) << '\n';
//    return 0;
//}