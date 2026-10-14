//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//int trie[MAXN][26];
//int end_[MAXN];
//int total;
//
//void InitTrie() {
//    total = 1;
//    for (int i = 0; i < MAXN; ++i) {
//        for (int j = 0; j < 26; ++j) {
//            trie[i][j] = 0;
//        }
//        end_[i] = 0;
//    }
//}
//
//void Insert(const string& word) {
//    int cur = 1;
//    for (char c : word) {
//        int path = c - 'a';
//        if (trie[cur][path] == 0) {
//            trie[cur][path] = ++total;
//        }
//        cur = trie[cur][path];
//    }
//    end_[cur] = 1;
//}
//
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        InitTrie();
//
//        vector<bool>check(26, false);
//        for (const string& word : wordDict) {
//            for (char c : word) {
//                check[c - 'a'] = 1;
//            }
//            Insert(word);
//        }
//        for (char c : s) {
//            if (!check[c - 'a']) {
//                return false;
//            }
//        }
//
//
//        int n = s.size();
//        vector<bool>dp(n + 1, false);
//        dp[0] = true;
//
//        for (int i = 0; i <= n; ++i) {
//            if (!dp[i]) {
//                continue;
//            }
//            int cur = 1;
//            for (int j = i; j < n; ++j) {
//                int path = s[j] - 'a';
//                if (trie[cur][path] == 0)
//                    break;
//                cur = trie[cur][path];
//                if (end_[cur] == 1) {
//                    dp[j + 1] = true;
//                    if (j + 1 == n) {
//                        return true;
//                    }
//                }
//            }
//        }
//
//        return dp[n];
//    }
//};