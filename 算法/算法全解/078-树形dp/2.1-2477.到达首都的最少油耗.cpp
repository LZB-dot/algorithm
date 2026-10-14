//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//private:
//    long long cost;
//
//    int dfs(int u, int seats, int p, const vector<vector<int>>& graph) {
//        int size = 1;
//        for (int v : graph[u]) {
//            if (v != p) {
//                size += dfs(v, seats, u, graph);
//            }
//        }
//
//        if (u != 0) {
//            cost += (size + seats - 1) / seats;
//        }
//
//        return size;
//    }
//public:
//    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
//        int n = roads.size() + 1;
//
//        vector<vector<int>>graph(n);
//
//        for (auto& road : roads) {
//            int u = road[0], v = road[1];
//            graph[u].push_back(v);
//            graph[v].push_back(u);
//        }
//        cost = 0;
//        dfs(0, seats, 0, graph);
//        return cost;
//    }
//};