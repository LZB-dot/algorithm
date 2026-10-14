//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//
//const int MAX_FACTOR = 100001;  
//const int MAX_NUMS = 20001;  
//
//class Solution {
//private:
//    vector<int> father;  
//    vector<int> sz;     
//    vector<int> vis;   
//    int n;               
//
//    void build() {
//        // 初始化并查集
//        for (int i = 0; i < n; ++i) {
//            father[i] = i;
//            sz[i] = 1;
//        }
//        fill(vis.begin(), vis.end(), -1);
//    }
//
//    // 并查集查找,路径压缩
//    int find(int x) {
//        if (father[x] != x) {
//            father[x] = find(father[x]); 
//        }
//        return father[x];
//    }
//
//    // 小集合合并到大集合
//    void unite(int x, int y) {
//        int fx = find(x);
//        int fy = find(y);
//        if (fx != fy) {
//            if (sz[fx] > sz[fy]) {
//                swap(fx, fy); // 保证fx是小集合的根
//            }
//            father[fx] = fy; // 小集合挂到大集合根节点下
//            sz[fy] += sz[fx]; 
//        }
//    }
//
//    // 统计最大连通分量的大小
//    int maxSize() {
//        int ans = 0;
//        for (int i = 0; i < n; ++i) {
//            ans = max(ans, sz[i]);
//        }
//        return ans;
//    }
//
//public:
//    Solution() {
//        father.resize(MAX_NUMS);
//        sz.resize(MAX_NUMS);
//        vis.resize(MAX_FACTOR);
//    }
//
//    int largestComponentSize(vector<int>& nums) {
//        n = nums.size();
//        build(); 
//
//        for (int i = 0; i < n; ++i) {
//            int x = nums[i]; 
//
//            for (int j = 2; j * j <= x; ++j) {
//                if (x % j == 0) { 
//                    if (vis[j] == -1) {
//                        vis[j] = i; 
//                    }
//                    else {
//                        unite(vis[j], i); 
//                    }
//
//                    while (x % j == 0) {
//                        x /= j;
//                    }
//                }
//            }
//
//            if (x > 1) {
//                if (vis[x] == -1) {
//                    vis[x] = i;
//                }
//                else {
//                    unite(vis[x], i);
//                }
//            }
//        }
//
//        return maxSize();
//    }
//};
