//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 2005;
//
//class Solution {
//private:
//    int n;
//    int m;
//    int treeLen[MAXN], treeCnt[MAXN];
//    vector<int>tmp;
//    int maxLen = 0, maxCnt = 0;
//
//    inline int getRank(int i) {
//        return lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin() + 1;
//    }
//
//    inline int lowbit(int i) {
//        return i & -i;
//    }
//    
//        
//    //已知以p这个数字结尾的 LIS,最长长度是 len,一共有 cnt 条
//    inline void add(int p, int len, int cnt) {
//        while (p <= m) {
//            if (treeLen[p] == len) {
//                treeCnt[p] += cnt;
//            }
//            else if (treeLen[p] < len) {
//                treeLen[p] = len;
//                treeCnt[p] = cnt;
//            }
//            p += lowbit(p);
//        }
//    }
//    
//     //所有 ≤ i 的数里,最长的递增子序列长度是多少？有多少条这样最长的？ 
//    inline void query(int p) {
//        maxLen = 0;
//        maxCnt = 0;
//        while (p > 0) {
//            if (treeLen[p] > maxLen) {
//                maxLen = treeLen[p];
//                maxCnt = treeCnt[p];
//            }
//            else if (treeLen[p] == maxLen) {
//                maxCnt += treeCnt[p];
//            }
//            p -= lowbit(p);
//        }
//    }
//
//public:
//    int findNumberOfLIS(vector<int>& nums) {
//        tmp = nums;
//        sort(tmp.begin(), tmp.end());
//        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
//        n = nums.size();
//        m = tmp.size();
//
//        for (int i = 0; i < n; ++i) {
//            int rk = getRank(nums[i]);
//            query(rk - 1);
//            if (maxLen == 0)
//                add(rk, 1, 1);
//            else
//                add(rk, maxLen + 1, maxCnt);
//        }
//
//        query(m);
//        return maxCnt;
//    }
//};