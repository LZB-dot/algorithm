//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<climits>
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 2005;
//
//class Solution {
//private:
//    ll mx[MAXN << 2];
//    ll change[MAXN << 2];
//    bool update[MAXN << 2];
//    vector<int>tmp;
//    int m;
//
//    void up(int i) {
//        mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
//    }
//
//    void lazy(int i,int v) {
//        mx[i] = v;
//        change[i] = v;
//        update[i] = true;
//    }
//
//    void down(int i) {
//        if (update[i]) {
//            lazy(i << 1, change[i]);
//            lazy(i << 1 | 1, change[i]);
//            update[i] = 0;
//        }
//    }
//
//    void build(int l, int r, int i) {
//        if (l == r) {
//            mx[i] = 0;
//            change[i] = 0;
//            update[i] = false;
//            return;
//        }
//        int mid = l + ((r - l) >> 1);
//        build(l, mid, i << 1);
//        build(mid + 1, r, i << 1 | 1);
//        up(i);
//    }
//
//    void updateRange(int jobl, int jobr, int jobv, int l, int r, int i) {
//        if (jobl <= l && r <= jobr)
//            lazy(i, jobv);
//        else {
//            down(i);
//            int mid = l + ((r - l) >> 1);
//            if (jobl <= mid)
//                updateRange(jobl, jobr, jobv, l, mid, i << 1);
//            if (jobr > mid)
//                updateRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//
//            up(i);
//        }
//    }
//
//    ll query(int jobl, int jobr, int l, int r, int i) {
//        if (jobl <= l && r <= jobr)
//            return mx[i];
//
//        ll ans = LLONG_MIN;
//
//        down(i);
//        int mid = l + ((r - l) >> 1);
//
//        if (jobl <= mid)
//            ans = max(ans, query(jobl, jobr, l, mid, i << 1));
//        if (jobr > mid)
//            ans = max(ans, query(jobl, jobr, mid + 1, r, i << 1 | 1));
//
//        return ans;
//    }
//
//    int getRank(int i) {
//        return lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin() + 1;
//    }
//    
//public:
//    vector<int> fallingSquares(vector<vector<int>>& positions) {
//        for (auto& it : positions) {
//            tmp.push_back(it[0]);
//            tmp.push_back(it[0] + it[1] - 1);
//        }
//        vector<int>ans;
//
//        sort(tmp.begin(), tmp.end());
//        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
//
//        m = tmp.size();
//        build(1, m, 1);
//
//        int l, r;
//        int res = INT_MIN;
//        for (auto& it : positions) {
//            int L = it[0];                
//            int R = it[0] + it[1] - 1;  
//            int len = it[1];            
//
//            l = getRank(L);
//            r = getRank(R);
//            
//            ll h = query(l, r, 1, m, 1) + len;
//            
//            updateRange(l, r, h, 1, m, 1);
//
//            res = max((ll)res, h);
//            ans.push_back(res);
//        }
//        return ans;
//
//    }
//};