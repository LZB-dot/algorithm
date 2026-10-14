//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//typedef unsigned long long ull;
//const int base = 499; 
//const int MAXN = 1e5 + 10; 
//
//class Solution {
//private:
//    vector<ull> power; 
//    vector<ull> hashs;
//
//    void build(int n, const string& s) {
//        power.resize(n);
//        hashs.resize(n);
//
//        power[0] = 1;
//        for (int i = 1; i < n; ++i)
//            power[i] = power[i - 1] * base;
//
//        hashs[0] = s[0] - 'a' + 1;
//        for (int i = 1; i < n; ++i)
//            hashs[i] = hashs[i - 1] * base + s[i] - 'a' + 1;
//    }
//
//    ull getHash(int l, int r) {
//        ull res = hashs[r];
//        if (l > 0)
//            res -= hashs[l - 1] * power[r - l + 1];
//        return res;
//    }
//
//    ull cal(const string& s) {
//        ull res = 0;
//        for (char c : s)
//            res = res * base + (c - 'a' + 1);
//        return res;
//    }
//
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        vector<int> ans;
//
//        unordered_map<ull, int> target;
//        int t = words[0].size(); 
//        int m = words.size();   
//        int total = m * t; 
//        int n = s.size();
//        if (total > n)
//            return ans; 
//
//        for (const string& word : words)
//            target[cal(word)]++; 
//
//        build(n, s);
//
//        for (int i = 0; i < t; ++i) {
//            unordered_map<ull, int> window; 
//            int debt = m; //未匹配的单词数量
//
//            for (int j = i; j < i + total; j += t) {
//                int r = j + t - 1;
//                if (r >= n) 
//                    break; 
//                ull h = getHash(j, r);
//                window[h]++;
//                if (window[h] <= target[h])
//                    debt--;
//            }
//
//            if (debt == 0)
//                ans.push_back(i);
//
//            for (int j = i + total; j + t - 1 < n; j += t) {
//                int rl = j;
//                int rr = j + t - 1;
//                ull h = getHash(rl, rr);
//                window[h]++;
//
//                if (window[h] <= target[h])
//                    debt--;
//
//                int ll = j - total;
//                int lr = ll + t - 1;
//                h = getHash(ll, lr);
//                window[h]--;
//
//                if (window[h] < target[h])
//                    debt++;
//
//                if (debt == 0)
//                    ans.push_back(ll + t); 
//            }
//        }
//
//        return ans;
//    }
//};
//
