//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int balancedString(string s){
//        int n = s.size();
//        int target = n / 4;
//        vector<int>cnts(4, 0);
//        for (char c : s) {
//            if (c == 'Q')
//                cnts[0]++;
//            else if (c == 'W')
//                cnts[1]++;
//            else if (c == 'E')
//                cnts[2]++;
//            else
//                cnts[3]++;
//        }
//
//        int debt = 0;
//        for (int i = 0; i < 4; ++i) {
//            if (cnts[i] > target) {
//                cnts[i] -= target;
//                debt += cnts[i];
//            }
//            else {
//                cnts[i] = 0;
//            }
//        }
//
//        if (debt == 0) {
//            return 0;
//        }
//
//        int ans = INT_MAX;
//        vector<int>cur(4, 0);
//
//        for (int l = 0, r = 0; r < s.size(); ++r) {
//            int idx = s[r] == 'Q' ? 0 : (s[r] == 'W' ? 1 : (s[r] == 'E' ? 2 : 3));
//            cur[idx]++;
//            while (l <= r) {
//                bool flag = 1;
//                for (int i = 0; i < 4; ++i) {
//                    if (cur[i] < cnts[i]) {
//                        flag = 0;
//                        break;
//                    }
//                }
//                if (!flag) {
//                    break;
//                }
//
//                ans = min(ans, r - l + 1);
//                int leftIdx = s[l] == 'Q' ? 0 : (s[l] == 'W' ? 1 : (s[l] == 'E' ? 2 : 3));
//                cur[leftIdx]--;
//                l++;
//            }
//        }
//        return ans;
//    }
//};