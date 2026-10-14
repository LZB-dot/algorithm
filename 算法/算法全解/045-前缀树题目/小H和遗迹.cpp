//#include <iostream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//
//const int MAXN = 1000000;
//int trie[MAXN][27];  // 26个字母 + 1个#的索引
//int total = 1;       // 根节点从1开始
//unordered_map<int, unordered_map<string, int>> counts;  // 存储前缀节点对应的后缀计数
//
//// 将字符转换为索引
//int path(char c) {
//    if (c == '#')
//        return 26;
//    return c - 'a';
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N;
//    cin >> N;
//    string s;
//
//    for (int i = 0; i < N; ++i) {
//        cin >> s;
//
//        //find找到的是#的索引
//
//        // 提取第一个#之前的前缀（不包含#）
//        size_t first_hash = s.find('#');
//        int pre_len;
//
//        // 特殊处理：如果字符串中存在#，且第一个#就是字符串的第一个字符
//        // 则前缀长度为0（空前缀）
//        bool x = 0;
//        if (first_hash == 0){
//            pre_len = 0;
//            x = 1;
//        }
//        else
//            pre_len = (first_hash != string::npos) ? first_hash : s.size();
//
//        // 提取最后一个#之后的后缀
//        size_t last_hash = s.rfind('#');
//        string suffix;
//
//        bool y = 0;
//        // 特殊处理：如果字符串全是#，则后缀为空
//        if (last_hash == s.size() - 1){
//            suffix = "";
//            y = 1;
//        }
//        else
//            suffix = (last_hash != string::npos) ? s.substr(last_hash + 1) : "";
//
//        int cur = 1;
//        for (int j = 0; j < pre_len; ++j) {  // 不包含#
//            int p = path(s[j]);
//            if (trie[cur][p] == 0) {
//                trie[cur][p] = ++total;
//            }
//            cur = trie[cur][p];
//        }
//        // 在当前前缀节点记录后缀
//        counts[cur][suffix]++;
//        if (x)
//            counts[cur][suffix]++;
//    }
//
//    // 计算总对数
//    long long res = 0;
//    for (auto& node_entry : counts) {
//        for (auto& suffix_entry : node_entry.second) {
//            long long cnt = suffix_entry.second;
//            res += cnt * (cnt - 1) / 2;
//        }
//    }
//
//    cout << res << endl;
//
//    return 0;
//}
