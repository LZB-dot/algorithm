//#include<iostream>
//#include<vector>
//#include<queue>
//#include<unordered_set>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//private:
//    queue<string>q;
//    unordered_set<string>vis;
//    vector<vector<string>>graph;
//
//    // π”√Ã˘÷Ωs
//    string nextStr(string t, string s) {
//        int i = 0, j = 0;
//        string ans;
//        int x = t.size(), y = s.size();
//        while (i < x && j < y) {
//            if (t[i] == s[j]) {
//                ++i; ++j;
//            }
//            else if (t[i] < s[j]) {
//                ans.push_back(t[i]);
//                ++i;
//            }
//            else {
//                ++j;
//            }
//        }
//        while (i < x) {
//            ans.push_back(t[i]);
//            ++i;
//        }
//        return ans;
//    }
//public:
//    int minStickers(vector<string>& stickers, string target) {
//        graph.resize(26);
//
//        for (string& s : stickers) {
//            string tmp = s;
//            sort(tmp.begin(), tmp.end());
//            int n = tmp.size();
//            for (int i = 0; i < n; ++i) {
//                if (i == 0 || tmp[i] != tmp[i - 1]) {
//                    graph[tmp[i] - 'a'].push_back(tmp);
//                }
//            }
//        }
//
//        sort(target.begin(), target.end());
//        string tar = target;
//        int level = 0;
//        q.push(tar);
//        vis.insert(tar);
//        while (!q.empty()) {
//            int n = q.size();
//            for (int i = 0; i < n; ++i) {
//                string cur = q.front();
//                q.pop();
//                if (cur.empty()) {
//                    return level;
//                }
//
//                char fir = cur[0];
//                for (string& s : graph[fir - 'a']) {
//                    string next = nextStr(cur, s);
//                    if (vis.find(next) != vis.end()) {
//                        vis.insert(next);
//                        q.push(next);
//                    }
//                }
//            }
//            level++;
//        }
//        return -1;
//    }
//};