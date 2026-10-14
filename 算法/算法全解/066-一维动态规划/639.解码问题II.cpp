//#include<algorithm>
//#include<vector>
//#include<string>
//using namespace std;
//
//
//class Solution {
//private:
//    const int MOD = 1e9 + 7;
//    vector<int> memory;
//
//    int f1(string s, int i) {
//        if (i == s.size()) {
//            return 1;  // 空字符串视为1种解码
//        }
//        if (memory[i] != -1) {
//            return memory[i];
//        }
//
//        long long ans = 0;  // 用long long避免中间溢出
//
//        // 单字符解码
//        if (s[i] == '0') {
//            // '0' 不能单独解码
//            memory[i] = 0;
//            return 0;
//        }
//        else if (s[i] == '*') {
//            // '*' 单独解码为1-9，共9种
//            ans = (ans + 9LL * f1(s, i + 1)) % MOD;
//        }
//        else {
//            // 数字1-9，1种
//            ans = (ans + f1(s, i + 1)) % MOD;
//        }
//
//        // 双字符解码（i+1需在范围内）
//        if (i + 1 < s.size()) {
//            if (s[i] != '*') {
//                // s[i]是数字，s[i+1]可以是数字或*
//                int digit = s[i] - '0';
//                if (s[i + 1] != '*') {
//                    // 两者都是数字：判断是否在10-26
//                    int num = digit * 10 + (s[i + 1] - '0');
//                    if (num >= 10 && num <= 26) {
//                        ans = (ans + f1(s, i + 2)) % MOD;
//                    }
//                }
//                else {
//                    // s[i]是数字，s[i+1]是*
//                    if (digit == 1) {
//                        // 1* →11-19（9种）
//                        ans = (ans + 9LL * f1(s, i + 2)) % MOD;
//                    }
//                    else if (digit == 2) {
//                        // 2* →21-26（6种）
//                        ans = (ans + 6LL * f1(s, i + 2)) % MOD;
//                    }
//                    // digit > 2时，双字符超过26，不增加
//                }
//            }
//            else {
//                // s[i]是*，s[i+1]可以是数字或*
//                if (s[i + 1] != '*') {
//                    // s[i]是*，s[i+1]是数字
//                    int digit = s[i + 1] - '0';
//                    if (digit <= 6) {
//                        // *0-*6 →1x或2x（2种）
//                        ans = (ans + 2LL * f1(s, i + 2)) % MOD;
//                    }
//                    else {
//                        // *7-*9 →只能1x（1种）
//                        ans = (ans + f1(s, i + 2)) % MOD;
//                    }
//                }
//                else {
//                    // **→11-19（9） + 21-26（6）=15种
//                    ans = (ans + 15LL * f1(s, i + 2)) % MOD;
//                }
//            }
//        }
//
//        memory[i] = ans % MOD;
//        return memory[i];
//    }
//
//    int f2(string s) {
//        int n = s.size();
//        vector<long long> dp(n + 2, 0); 
//        dp[n] = 1;
//        for (int i = n - 1; i >= 0; --i) {
//            if (s[i] == '0') {
//                dp[i] = 0;
//            }
//            else {
//                dp[i] = (dp[i + 1] * (s[i] == '*' ? 9LL : 1LL)) % MOD;
//
//                // 双字符解码
//                if (i + 1 < n) {
//                    if (s[i] != '*') {
//                        int digit = s[i] - '0';
//                        if (s[i + 1] != '*') {
//                            int num = (digit) * 10 + (s[i + 1] - '0');
//                            if (num >= 10 && num <= 26) {
//                                dp[i] = (dp[i] + dp[i + 2]) % MOD;
//                            }
//                        }
//                        else {
//                            if (digit == 1) {
//                                dp[i] = (dp[i] + dp[i + 2] * 9LL) % MOD;
//                            }
//                            else if (digit == 2) {
//                                dp[i] = (dp[i] + dp[i + 2] * 6LL) % MOD;
//                            }
//                        }
//                    }
//                    else {
//                        if (s[i + 1] != '*') {
//                            int digit = s[i + 1] - '0';
//                            if (digit <= 6) {
//                                dp[i] = (dp[i] + dp[i + 2] * 2LL) % MOD;
//                            }
//                            else {
//                                dp[i] = (dp[i] + dp[i + 2]) % MOD;
//                            }
//                        }
//                        else {
//                            dp[i] = (dp[i] + dp[i + 2] * 15LL) % MOD;
//                        }
//                    }
//                }
//            }
//            dp[i] %= MOD; 
//        }
//        return dp[0] % MOD;
//    }
//
//    int f3(string s) {
//        int n = s.size();
//        int next = 1;
//        int nextNext = 0;
//        int ans = 0;
//        for (int i = n - 1; i >= 0; --i) {
//            if (s[i] == '0') {
//                ans = 0;
//            }
//            else {
//                ans = (next * (s[i] == '*' ? 9LL : 1LL)) % MOD;
//
//                // 双字符解码
//                if (i + 1 < n) {
//                    if (s[i] != '*') {
//                        int digit = s[i] - '0';
//                        if (s[i + 1] != '*') {
//                            int num = (digit) * 10 + (s[i + 1] - '0');
//                            if (num >= 10 && num <= 26) {
//                                ans = (ans + nextNext) % MOD;
//                            }
//                        }
//                        else {
//                            if (digit == 1) {
//                                ans = (ans + nextNext * 9LL) % MOD;
//                            }
//                            else if (digit == 2) {
//                                ans = (ans + nextNext * 6LL) % MOD;
//                            }
//                        }
//                    }
//                    else {
//                        if (s[i + 1] != '*') {
//                            int digit = s[i + 1] - '0';
//                            if (digit <= 6) {
//                                ans = (ans + nextNext * 2LL) % MOD;
//                            }
//                            else {
//                                ans = (ans + nextNext) % MOD;
//                            }
//                        }
//                        else {
//                            ans = (ans + nextNext * 15LL) % MOD;
//                        }
//                    }
//                }
//            }
//            ans %= MOD;
//            nextNext = next;
//            next = ans;
//        }
//        return ans % MOD;
//    }
//public:
//    int numDecodings(string s) {
//        memory.resize(s.size(), -1);
//        //return f1(s, 0);
//        //return f2(s);
//        return f3(s);
//    }
//};