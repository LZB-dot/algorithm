//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class UnionFind {
//private:
//    vector<int>father;
//    vector<bool>secret;
//    int n;
//public:
//    UnionFind(int size, int first) {
//        n = size;
//        father.resize(n);
//        secret.resize(n, false);
//        for (int i = 0; i < n; ++i) {
//            father[i] = i;
//        }
//        father[first] = 0;
//        secret[0] = true;
//    }
//
//    int find(int i) {
//        if (i != father[i]) {
//            father[i] = find(father[i]);
//        }
//        return father[i];
//    }
//
//    void unionSet(int x, int y) {
//        int fx = find(x);
//        int fy = find(y);
//        if (fx != fy) {
//            father[fx] = fy;
//            secret[fy] = secret[fy] || secret[fx];
//        }
//    }
//
//    void reset(int x) {
//        int fx = find(x);
//        if (!secret[fx]) {
//            father[x] = x;
//        }
//    }
//
//    vector<int>getSecret() {
//        vector<int>res;
//        for (int i = 0; i < n; ++i) {
//            if (secret[find(i)]) {
//                res.push_back(i);
//            }
//        }
//        return res;
//    }
//};
//
//class Solution {
//public:
//    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
//        sort(meetings.begin(), meetings.end(), 
//            [](const vector<int>& a, const vector<int>& b) 
//            {return a[2] < b[2];});
//
//        UnionFind uf(n, firstPerson);
//        int m = meetings.size();
//        for (int l = 0, r; l < m; ) {
//            r = l;
//            while (r + 1 < m && meetings[r + 1][2] == meetings[l][2]) {
//                r++;
//            }
//            for (int i = l; i <= r; ++i) {
//                uf.unionSet(meetings[i][0], meetings[i][1]);
//            }
//            for (int i = l; i <= r; ++i) {
//                uf.reset(meetings[i][0]);
//                uf.reset(meetings[i][1]);
//            }
//            l = r + 1;
//        }
//
//        return uf.getSecret();
//    }
//};