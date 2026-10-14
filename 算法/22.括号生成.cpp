//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//// 在 std 命名空间中为 pair<int, int> 提供一个哈希函数
//namespace std {
//    template <>
//    struct hash<pair<int, int>> {
//        size_t operator () (const pair<int, int>& p) const {
//            // 一个简单的哈希组合方法
//            // 将两个 int 合并成一个 size_t
//            // 你也可以使用更复杂的组合方式，比如 boost 的 hash_combine
//            auto h1 = hash<int>{}(p.first);
//            auto h2 = hash<int>{}(p.second);
//            return h1 ^ (h2 << 1); 
//        }
//    };
//}
//
//class Solution {
//private:
//    unordered_map<pair<int, int>, vector<string>>mp;
//
//    vector<string>dfs(int left, int right) {
//        pair<int, int>tmp = { left,right };
//        if (mp.find(tmp) != mp.end()) {
//            return mp[tmp];
//        }
//        vector<string>ans;
//        if (left == 0 && right == 0) {
//            ans.push_back("");
//            mp[tmp] = ans;
//            return ans;
//        }
//
//        if (left > 0) {
//            vector<string>res = dfs(left - 1, right);
//            for (string s : res) {
//                ans.push_back('(' + s);
//            }
//        }
//
//        if (right > left) {
//            vector<string>res = dfs(left, right - 1);
//            for (string s : res) {
//                ans.push_back(')' + s);
//            }
//        }
//
//        mp[tmp] = ans;
//        return ans;
//    }
//public:
//    vector<string> generateParenthesis(int n) {
//        return dfs(n, n);
//    }
//};