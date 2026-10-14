//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 2e4 + 10;
//int cnt[MAXN << 2];
//int tar[MAXN << 2];
//int n;
//vector<int> arr;
//
//class MajorityChecker {
//private:
//
//    void up(int i) {
//        int l = i << 1;
//        int r = i << 1 | 1;
//
//        if (tar[l] == tar[r]) {
//            cnt[i] = cnt[l] + cnt[r];
//            tar[i] = tar[l];
//        }
//        else if (cnt[l] > cnt[r]) {
//            cnt[i] = cnt[l] - cnt[r];
//            tar[i] = tar[l];
//        }
//        else {
//            cnt[i] = cnt[r] - cnt[l];
//            tar[i] = tar[r];
//        }
//    }
//
//    void build(const vector<int>& arr_, int l, int r, int i) {
//        if (l == r) {
//            cnt[i] = 1;
//            tar[i] = arr_[l - 1];
//        }
//        else {
//            int mid = l + ((r - l) >> 1);
//            build(arr_, l, mid, i << 1);
//            build(arr_, mid + 1, r, i << 1 | 1);
//            up(i);
//        }
//    }
//
//    vector<int> queryRange(int jobl, int jobr, int jobv, int l, int r, int i) {
//        if (jobl <= l && r <= jobr)
//            return { tar[i], cnt[i] };
//
//        int mid = l + ((r - l) >> 1);
//
//        if (jobr <= mid)
//            return queryRange(jobl, jobr, jobv, l, mid, i << 1);
//        if (jobl > mid)
//            return queryRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//
//        vector<int> left = queryRange(jobl, jobr, jobv, l, mid, i << 1);
//        vector<int> right = queryRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//
//        int tari, cnti;
//        int tarl = left[0], cntl = left[1];
//        int tarr = right[0], cntr = right[1];
//
//        if (tarl == tarr) {
//            cnti = cntl + cntr;
//            tari = tarl;
//        }
//        else if (cntl > cntr) {
//            cnti = cntl - cntr;
//            tari = tarl;
//        }
//        else {
//            cnti = cntr - cntl;
//            tari = tarr;
//        }
//
//        return { tari, cnti };
//    }
//
//public:
//    MajorityChecker(vector<int>& arr_) {
//        arr = arr_;
//        memset(cnt, 0, sizeof(cnt));
//        memset(tar, 0, sizeof(tar));
//        n = arr.size();
//        build(arr_, 1, n, 1);
//    }
//
//    int query(int left, int right, int threshold) {
//        vector<int> ans = queryRange(left + 1, right + 1, threshold, 1, n, 1);
//        int target = ans[0];
//
//        int real = 0;
//        for (int i = left; i <= right; ++i) {
//            if (arr[i] == target) 
//                real++;
//        }
//
//        if (real >= threshold) 
//            return target;
//        else 
//            return -1;
//    }
//};