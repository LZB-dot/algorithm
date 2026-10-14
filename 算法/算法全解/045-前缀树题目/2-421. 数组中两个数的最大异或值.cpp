

//#include <vector>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//
//const int MAXN = 31 * 200000 + 50;
//int trie[MAXN][2];
//int cnt;
//
//class Solution {
//private:
//    void insert(int num) {
//        int cur = 1;
//        for (int i = 30; i >= 0; --i) { 
//            int p = (num >> i) & 1;
//
//            if (!trie[cur][p]) 
//                trie[cur][p] = ++cnt;
//            
//            cur = trie[cur][p];
//        }
//    }
//
//    int maxXor(int x) {
//        int cur = 1;
//        int ans = 0;
//        for (int i = 30; i >= 0; --i) { 
//            int p = (x >> i) & 1;
//
//            ans <<= 1;
//
//            if (trie[cur][p ^ 1]) {
//                ans |= 1;
//                cur = trie[cur][p ^ 1];
//            }
//            else 
//                cur = trie[cur][p];
//            
//        }
//        return ans;
//    }
//
//public:
//    int findMaximumXOR(vector<int>& nums) {
//        for (int i = 0; i <= cnt; ++i) 
//            trie[i][0] = trie[i][1] = 0;
//
//        cnt = 1; 
//
//        for (int num : nums) 
//            insert(num);
//        
//        int res = 0;
//        for (int num : nums) 
//            res = max(res, maxXor(num));
//
//        return res;
//    }
//};
//
//
