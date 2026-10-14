//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//class Solution {
//private:
//    int bindarySearch(const vector<int>& ends, int len, int num) {
//        int l = 0, r = len - 1;
//        int pos = -1;
//        while (l <= r) {
//            int mid = l + ((r - l) >> 1);
//            if (ends[mid] >= num) {
//                pos = mid;
//                r = mid - 1;
//            }
//            else {
//                l = mid + 1;
//            }
//        }
//
//        return pos;
//    }
//public:
//    int maxEnvelopes(vector<vector<int>>& envelopes) {
//        int n = envelopes.size(), m = envelopes[0].size();
//
//        sort(envelopes.begin(), envelopes.end(),
//            [](const vector<int>& a, const vector<int>& b) {
//                if (a[0] == b[0]) {
//                    return a[1] > b[1];
//                }
//                else {
//                    return a[0] < b[0];
//                }
//            });
//
//        vector<int> ends(n + 1, 1);
//        int len = 0;
//        for (int i = 0; i < n; ++i) {
//            int pos = bindarySearch(ends, len, envelopes[i][1]);
//            if (pos == -1) {
//                ends[len++] = envelopes[i][1];
//            }
//            else {
//                ends[pos] = envelopes[i][1];
//            }
//        }
//        return len;
//    }
//};