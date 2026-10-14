//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//
//class Solution {
//private:
//    vector<vector<int>>dp;
//    vector<int>num;
//    int target = 0;
//    int n, m;
//
//    int dfs(int idx, int mask) {
//        if (mask == (1 << n) - 1)
//            return 0;
//
//        if (idx == m)
//            return INT_MAX;
//
//        if (dp[idx][mask] != -1)
//            return dp[idx][mask];
//
//        int c1 = dfs(idx + 1, mask);
//        int c2 = dfs(idx + 1, mask | num[idx]);
//        if (c2 != INT_MAX)
//            c2 += 1;
//
//        return dp[idx][mask] = min(c1, c2);
//
//    }
//
//    void print() {
//        dfs(0, 0);
//        vector<int>ans;
//        int status = 0;
//
//        for (int i = 0; i < m; ++i) {
//            if (i == m - 1 || dp[i][status] != dp[i + 1][status]){
//                ans.push_back(i);
//                status |= num[i];
//                if (status == (1 << n) - 1)
//                    break;
//            }
//        }
//
//        for (int i : ans)
//            cout << i;
//
//    }
//public:
//    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
//        n = req_skills.size();
//        m = people.size();
//        num.resize(m);
//        unordered_map<string, int>mp;
//        for (int i = 0; i < n; ++i) {
//            mp[req_skills[i]] = i;
//        }
//
//        for (int i = 0; i < m; ++i) {
//            int tmp = 0;
//            for (auto j : people[i]) {
//                if (mp.count(j)) {
//                    tmp |= (1 << mp[j]);
//                }
//            }
//            num[i] = tmp;
//        }
//
//        dp.assign(m, vector<int>(1 << n, -1));
//
//    }
//};