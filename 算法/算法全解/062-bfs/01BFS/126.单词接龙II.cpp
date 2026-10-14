//#include<iostream>
//#include<vector>
//#include<queue>
//#include<unordered_map>
//#include<unordered_set>
//#include<list>
//using namespace std;
//
//class Solution {
//private:
//    unordered_map<string, vector<string>> graph;  // 反向图：key的前驱列表
//    unordered_set<string> in;                     // 词典集合
//    vector<vector<string>> ans;                   // 结果集
//    list<string> path;                            // 回溯路径
//
//    bool bfs(const string& begin, const string& end) {
//        queue<string> q;
//        unordered_set<string> vis;
//        q.push(begin);
//        vis.insert(begin);
//        bool find = false;
//
//        while (!q.empty() && !find) {
//            int levelSize = q.size();
//            unordered_set<string> currentLevel;   // 当前层新发现的节点
//
//            for (int idx = 0; idx < levelSize; ++idx) {
//                string cur = q.front();
//                q.pop();
//                int n = cur.size();
//
//                for (int i = 0; i < n; ++i) {
//                    string tmp = cur;
//                    for (char c = 'a'; c <= 'z'; ++c) {
//                        tmp[i] = c;
//                        if (tmp == cur) continue;  // 跳过自身
//                        if (!in.count(tmp)) continue;  // 不在词典中
//
//                        if (!vis.count(tmp)) {
//                            // 去重：避免同一前驱重复加入
//                            bool alreadyAdded = false;
//                            for (const string& prev : graph[tmp]) {
//                                if (prev == cur) {
//                                    alreadyAdded = true;
//                                    break;
//                                }
//                            }
//                            if (!alreadyAdded) {
//                                graph[tmp].push_back(cur);
//                            }
//
//                            currentLevel.insert(tmp);  // 记录当前层新节点
//                            if (tmp == end) {
//                                find = true;  // 找到终点但不终止，处理完当前层
//                            }
//                        }
//                    }
//                }
//            }
//
//            // 关键修正：将当前层新节点加入队列，供下一层处理
//            for (const string& word : currentLevel) {
//                q.push(word);        // 必须加入队列，否则BFS无法继续
//                vis.insert(word);    // 标记为已访问，避免重复处理
//            }
//        }
//
//        return find;
//    }
//
//    void dfs(const string& begin, const string& current) {
//        path.push_back(current);
//
//        if (current == begin) {
//            // 反转路径得到 [begin, ..., end]
//            vector<string> tmp(path.rbegin(), path.rend());
//            ans.push_back(tmp);
//        }
//        else {
//            for (const string& prev : graph[current]) {
//                dfs(begin, prev);
//            }
//        }
//
//        path.pop_back();  // 回溯
//    }
//
//public:
//    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//        in = unordered_set<string>(wordList.begin(), wordList.end());
//
//        if (!in.count(endWord)) {
//            return ans;
//        }
//
//        if (bfs(beginWord, endWord)) {
//            dfs(beginWord, endWord);
//        }
//
//        return ans;
//    }
//};