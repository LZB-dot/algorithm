//#include<iostream>
//#include<vector>
//#include<queue>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//    vector<string> findRelativeRanks(vector<int>& score) {
//        int n = score.size();
//        vector<string>res(n);
//        priority_queue<pair<int, int>>pq;
//        for (int i = 0; i < n; ++i) {
//            pq.emplace(score[i], i);
//        }
//
//        int rank = 1;
//        while (!pq.empty()) {
//            auto top = pq.top();
//            pq.pop();
//            int idx = top.second;
//            if (rank == 1) {
//                res[idx] = "Gold Medal";
//            }
//            else if (rank == 2) {
//                res[idx] = "Silver Medal";
//            }
//            else if (rank == 3) {
//                res[idx] = "Bronze Medal";
//            }
//            else {
//                res[idx] = to_string(rank);
//            }
//            ++rank;
//        }
//        return res;
//    }
//};