////
//////我的错误贪心算法
////
//////#include<iostream>
//////#include<deque>
//////#include<vector>
//////using namespace std;
//////
//////
//////int main() {
//////	ios::sync_with_stdio(false);
//////	cin.tie(nullptr);
//////
//////	int n, m;
//////	cin >> n >> m;
//////	vector<deque<int> >v(n);
//////	int tmp;
//////	for (int i = 0; i < n; ++i) {
//////		for (int j = 0; j < m; ++j) {
//////			cin >> tmp;
//////			v[i].push_back(tmp);
//////		}
//////	}
//////	long long ans = 0;
//////
//////	for (int i = 1; i <= m; ++i) {
//////		for (int j = 0; j < n; ++j) {
//////			int x = 0;
//////			if (v[j].front() > v[j].back()) {
//////				x = v[j].back();
//////				v[j].pop_back();
//////			}
//////			else {
//////				x = v[j].front();
//////				v[j].pop_front();
//////			}
//////			ans += ((1LL << i) * x);
//////		}
//////		cout << ans << endl;
//////	}
//////	cout << ans << endl;
//////	return 0;
//////}
////
////
////#include<iostream>
////#include<vector>
////#include<algorithm>
////
////using namespace std;
////
////typedef long long ll;
////int main() {
////	ios::sync_with_stdio(false);
////	cin.tie(nullptr);
////
////	int n, m;
////	cin >> n >> m;
////	vector<vector<int> >v(n, vector<int>(m));
////
////	for (int i = 0; i < n; ++i) {
////		for (int j = 0; j < m; ++j) {
////			cin >> v[i][j];
////		}
////	}
////
////	ll total = 0;
////
////	for (int row = 0; row < n; ++row) {
////		vector<vector<ll> >dp(m, vector<ll>(m, 0));
////
////		for (int len = 1; len <= m; ++len) {
////			for (int st = 0; st <= m - len; ++st) {
////				int ed = st + len - 1;
////				int step = m - len + 1;
////				ll w = 1LL << step;
////
////				if (len == 1) {
////					dp[st][ed] = v[row][st] * w;
////				}
////				else {
////					ll left = v[row][st] * w + dp[st + 1][ed];
////					ll right = v[row][ed] * w + dp[st][ed - 1];
////					dp[st][ed] = max(left, right);
////				}
////			}
////		}
////		total += dp[0][m - 1];
////	}
////	cout << total << endl;
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//// 大整数类型：vector<int>存储，高位在前（如123存储为[1,2,3]）
//typedef vector<int> BigInt;
//
//void print_bigint(const BigInt& num) {
//    for (int i : num) {
//        cout << i;
//    }
//    cout << endl;
//}
//
//BigInt create(long long x) {
//    BigInt res;
//    if (x == 0) {
//        res.push_back(0);
//        return res;
//    }
//    while (x > 0) {
//        res.push_back(x % 10);
//        x /= 10;
//    }
//    reverse(res.begin(), res.end());
//    return res;
//}
//
//BigInt create_two(int step) {
//    BigInt res = { 1 };
//    for (int i = 0; i < step; ++i) {
//        int carry = 0;
//        for (int j = res.size() - 1; j >= 0; --j) {
//            int val = res[j] * 2 + carry;
//            res[j] = val % 10;
//            carry = val / 10;
//        }
//        if (carry > 0) {
//            res.insert(res.begin(), carry);
//        }
//    }
//    return res;
//}
//
//BigInt multiply_small(const BigInt& num, int x) {
//    BigInt res;
//    int carry = 0;
//    for (int i = num.size() - 1; i >= 0; --i) {
//        int val = num[i] * x + carry;
//        res.push_back(val % 10);
//        carry = val / 10;
//    }
//    while (carry > 0) {
//        res.push_back(carry % 10);
//        carry /= 10;
//    }
//    reverse(res.begin(), res.end());
//    return res;
//}
//
//BigInt add(const BigInt& a, const BigInt& b) {
//    BigInt res;
//    int i = a.size() - 1;
//    int j = b.size() - 1;
//    int carry = 0;
//    while (i >= 0 || j >= 0 || carry > 0) {
//        int val_a = (i >= 0) ? a[i--] : 0;
//        int val_b = (j >= 0) ? b[j--] : 0;
//        int sum = val_a + val_b + carry;
//        res.push_back(sum % 10);
//        carry = sum / 10;
//    }
//    reverse(res.begin(), res.end());
//    return res;
//}
//
//bool compare(const BigInt& a, BigInt& b) {
//    if (a.size() != b.size()) {
//        return a.size() < b.size();
//    }
//    for (int i = 0; i < a.size(); ++i) {
//        if (a[i] != b[i]) {
//            return a[i] < b[i];
//        }
//    }
//    return false;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> matrix(n, vector<int>(m));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> matrix[i][j];
//        }
//    }
//
//    BigInt total = create(0);  // 总得分初始化为0
//
//    for (int row = 0; row < n; ++row) {
//        // dp[i][j]存储区间[i,j]的最大得分（大整数类型）
//        vector<vector<BigInt>> dp(m, vector<BigInt>(m));
//
//        for (int len = 1; len <= m; ++len) {
//            for (int i = 0; i <= m - len; ++i) {
//                int j = i + len - 1;
//                int step = m - len + 1;
//
//                // 计算权重2^step
//                BigInt weight = create_two(step);
//
//                // 计算元素×权重
//                BigInt left_val = multiply_small(weight, matrix[row][i]);
//                BigInt right_val = multiply_small(weight, matrix[row][j]);
//
//                if (len == 1) {
//                    dp[i][j] = left_val;
//                }
//                else {
//                    // 取左元素+剩余右区间得分
//                    BigInt take_left = add(left_val, dp[i + 1][j]);
//                    // 取右元素+剩余左区间得分
//                    BigInt take_right = add(right_val, dp[i][j - 1]);
//                    // 选择更大的得分
//                    dp[i][j] = compare(take_left, take_right) ? take_right : take_left;
//                }
//            }
//        }
//
//        // 累加当前行的最大得分
//        total = add(total, dp[0][m - 1]);
//    }
//
//    print_bigint(total);
//    return 0;
//}