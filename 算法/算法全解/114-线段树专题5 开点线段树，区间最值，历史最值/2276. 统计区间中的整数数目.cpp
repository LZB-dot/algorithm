//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 30 * 2 * 1e5 + 1000;
//const int n = 1e9;
//
//class CountIntervals {
//private:
//    int cnt;
//    bool update[MAXN];
//    int sum[MAXN], left_[MAXN], right_[MAXN];
//
//    void up(int i, int l, int r) {
//        sum[i] = sum[l] + sum[r];
//    }
//
//    void lazy(int i,int n) {
//        update[i] = true;
//        sum[i] = n;
//    }
//
//    void down(int i, int ln, int rn) {
//        if (update[i]) {
//            if (left_[i] == 0)
//                left_[i] = ++cnt;
//            if (right_[i] == 0)
//                right_[i] = ++cnt;
//
//            lazy(left_[i], ln);
//            lazy(right_[i], rn);
//
//            update[i] = false;
//        }
//    }
//
//    void updateRange(int jobl, int jobr, int l, int r, int i) {
//        if (update[i] == true)
//            return;
//        
//        if (jobl <= l && r <= jobr)
//            lazy(i, r - l + 1);
//        else {
//            int mid = l + ((r - l) >> 1);
//            down(i, mid - l + 1, r - mid);
//
//            if (jobl <= mid) {
//                if (left_[i] == 0)
//                    left_[i] = ++cnt;
//                updateRange(jobl, jobr, l, mid, left_[i]);
//            }
//
//            if (jobr > mid) {
//                if (right_[i] == 0)
//                    right_[i] = ++cnt;
//                updateRange(jobl, jobr, mid + 1, r, right_[i]);
//            }
//
//            up(i, left_[i], right_[i]);
//          
//        }
//    }
//public:
//    CountIntervals() {
//        cnt = 1;
//        memset(sum, 0, sizeof(sum));
//        memset(left_, 0, sizeof(left_));
//        memset(right_, 0, sizeof(right_));
//
//        fill(update, update + MAXN, false);
//    }
//
//    void add(int left, int right) {
//        updateRange(left, right, 1, n, 1);
//    }
//
//    int count() {
//        return sum[1];
//    }
//};
//
///**
// * Your CountIntervals object will be instantiated and called as such:
// * CountIntervals* obj = new CountIntervals();
// * obj->add(left,right);
// * int param_2 = obj->count();
// */