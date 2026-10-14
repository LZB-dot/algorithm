//#include<iostream>
//#include<vector>
//#include<queue>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//private:
//    vector<int> head, to_, next_, indegree;
//    int cnt;
//
//    void Init(int n, int m) {
//        head.resize(n, 0);
//        to_.resize(m + 1, -1);
//        next_.resize(m + 1, -1);
//        cnt = 0;
//        indegree.resize(n, 0); // 入度初始化为0
//    }
//
//    void Add(int u, int v) {
//        cnt++;
//        to_[cnt] = v;
//        next_[cnt] = head[u];
//        head[u] = cnt;
//        indegree[v]++; // v的入度+1（u是v的前置依赖）
//    }
//
//public:
//    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
//        unordered_map<string, int> mp; // 字符串→唯一整数
//        int global_idx = 0; // 全局索引，避免和局部变量冲突
//
//        //映射所有字符串（菜谱、供应品、食材）到整数
//        for (const string& s : recipes) {
//            if (!mp.count(s)) {
//                mp[s] = global_idx++;
//            }
//        }
//        for (const string& s : supplies) {
//            if (!mp.count(s)) {
//                mp[s] = global_idx++;
//            }
//        }
//        for (auto& it : ingredients) {
//            for (const string& s : it) {
//                if (!mp.count(s)) {
//                    mp[s] = global_idx++;
//                }
//            }
//        }
//
//        //计算总边数，初始化邻接表
//        int total_edges = 0;
//        for (auto& ing_list : ingredients) {
//            total_edges += ing_list.size();
//        }
//        Init(global_idx, total_edges); 
//
//        //建立反向映射（仅记录菜谱的整数→字符串），并添加正确方向的边
//        unordered_map<int, string> revmp;
//        for (int i = 0; i < recipes.size(); ++i) {
//            const string& recipe = recipes[i];
//            int recipe_idx = mp[recipe]; 
//            revmp[recipe_idx] = recipe; 
//
//            // 食材→菜谱（菜谱依赖食材）
//            for (const string& ing : ingredients[i]) {
//                int ing_idx = mp[ing];
//                Add(ing_idx, recipe_idx); // 食材指向菜谱
//            }
//        }
//
//        queue<int> q;
//        for (const string& s : supplies) {
//            int supply_idx = mp[s];
//            if (indegree[supply_idx] == 0) { // 供应品无前置依赖，入度为0
//                q.push(supply_idx);
//            }
//        }
//
//        vector<string> res;
//        while (!q.empty()) {
//            int u = q.front();
//            q.pop();
//
//            if (revmp.count(u)) {
//                res.push_back(revmp[u]);
//            }
//
//            for (int i = head[u]; i != 0; i = next_[i]) {
//                int v = to_[i];
//                indegree[v]--; 
//                if (indegree[v] == 0) { 
//                    q.push(v);
//                }
//            }
//        }
//
//        return res;
//    }
//};
//=