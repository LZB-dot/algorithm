//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//#include<cstring>
//
//using namespace std;
//
//const int MAXN = 10010;
//typedef long long ll;
//
//int n, m;
//int rec[MAXN][4];
//
//struct Line {
//    int pos, l, r, val;
//} line[MAXN];
//
//vector<int> v;
//
//int len[MAXN << 2];
//int cover[MAXN << 2];
//int times[MAXN << 2];
//
//bool cmp(const Line& a, const Line& b) {
//    if (a.pos != b.pos) return a.pos < b.pos;
//    return a.val > b.val;
//}
//
//void up(int l, int r, int i) {
//    if (times[i])
//        cover[i] = len[i];
//    else if (l == r)
//        cover[i] = 0;
//    else
//        cover[i] = cover[i << 1] + cover[i << 1 | 1];
//}
//
//void build(int l, int r, int i) {
//    if (l == r) {
//        len[i] = v[l] - v[l - 1];
//        cover[i] = times[i] = 0;
//    }
//    else {
//        int mid = l + ((r - l) >> 1);
//        build(l, mid, i << 1);
//        build(mid + 1, r, i << 1 | 1);
//        len[i] = len[i << 1] + len[i << 1 | 1];
//    }
//}
//
//void add(int jobl, int jobr, int jobv, int l, int r, int i) {
//    if (jobl <= l && r <= jobr) {
//        times[i] += jobv;
//        up(l, r, i);
//    }
//    else {
//        int mid = l + ((r - l) >> 1);
//        if (jobl <= mid)
//            add(jobl, jobr, jobv, l, mid, i << 1);
//        if (jobr > mid)
//            add(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//        up(l, r, i);
//    }
//}
//
//int id(int x) {
//    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
//}
//
//void scanY() {
//    int x1, y1, x2, y2;
//    for (int i = 1, j = n + 1; i <= n; ++i, ++j) {
//        x1 = rec[i][0]; y1 = rec[i][1];
//        x2 = rec[i][2]; y2 = rec[i][3];
//
//        line[i] = { x1, y1, y2, 1 };
//        line[j] = { x2, y1, y2, -1 };
//
//        v.push_back(y1);
//        v.push_back(y2);
//    }
//}
//
//ll calc() {
//    sort(v.begin(), v.end());
//    v.erase(unique(v.begin(), v.end()), v.end());
//    m = v.size();
//
//    sort(line + 1, line + 2 * n + 1, cmp);
//
//    build(1, m - 1, 1);
//
//    ll ans = 0;
//    int pre = 0;
//    for (int i = 1; i <= 2 * n; ++i) {
//        pre = cover[1];
//        int L = id(line[i].l);
//        int R = id(line[i].r) - 1;
//        add(L, R, line[i].val, 1, m - 1, 1);
//        ans += abs(cover[1] - pre);
//    }
//    return ans;
//}
//
//void init() {
//    v.clear();
//    memset(times, 0, sizeof(times));
//    memset(cover, 0, sizeof(cover));
//}
//
//void scanX() {
//    int x1, y1, x2, y2;
//    for (int i = 1, j = n + 1; i <= n; ++i, ++j) {
//        x1 = rec[i][0]; y1 = rec[i][1];
//        x2 = rec[i][2]; y2 = rec[i][3];
//
//        line[i] = { y1, x1, x2, 1 };
//        line[j] = { y2, x1, x2, -1 };
//
//        v.push_back(x1);
//        v.push_back(x2);
//    }
//}
//
//ll solve() {
//    scanY();
//    ll ansY = calc();
//
//    init();
//    scanX();
//    ll ansX = calc();
//
//    return ansX + ansY;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n;
//    for (int i = 1; i <= n; ++i)
//        cin >> rec[i][0] >> rec[i][1] >> rec[i][2] >> rec[i][3];
//
//    cout << solve() << endl;
//    return 0;
//}