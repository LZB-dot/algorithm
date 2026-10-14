//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//class Solution {
//private:
//    string ss;
//    vector<int>p;
//    int n;
//
//    void getSS(const string& s) {
//        for (char c : s) {
//            ss += '#';
//            ss += c;
//        }
//        ss += '#';
//        n = ss.size();
//        p.resize(n);
//    }
//
//    int find(int l, int k) {
//        int r = l, c = l;
//
//        for (int i = l; i < n; ++i) {
//            int len = r > i ? min(r - i, p[2 * c - i]) : 1;
//
//            while (i + len < n && i - len >= l && ss[i + len] == ss[i - len]) {
//                ++len;
//                if (len > k)
//                    return i + k + (ss[i + k] != '#' ? 1 : 0);
//            }
//
//            if (i + len > r) {
//                r = i + len;
//                c = i;
//            }
//
//            p[i] = len;
//        }
//
//        return -1;
//    }
//public:
//    int maxPalindromes(string s, int k) {
//        getSS(s);
//
//        int ans = 0;
//        int nxt = 0;
//        while (nxt != -1 && nxt < n) {
//            nxt = find(nxt, k);
//            if (nxt != -1)
//                ++ans;
//        }
//
//        return ans;
//    }
//};