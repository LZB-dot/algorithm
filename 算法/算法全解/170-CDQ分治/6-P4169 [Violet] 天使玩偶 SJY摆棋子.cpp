//
//
//
////https://www.luogu.com.cn/problem/P4169
//
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 6e5 + 10;
//const int MAXM = 1e6 + 10;
//const int INF = 1e9;
//
//struct Node {
//    int x, y;
//    int op;
//    int pos;
//};
//
//Node tim[MAXN];   
//Node arr[MAXN];
//int ans[MAXN];
//int tree[MAXM];
//int cnt = 1;
//int v = 0;    
//
//inline int lowbit(int i) {
//    return i & -i;
//}
//
//inline void update(int i, int val) {
//    while (i < MAXM) {
//        if (val > tree[i])
//            tree[i] = val;
//        i += lowbit(i);
//    }
//}
//
//inline int query(int i) {
//    int res = -INF;
//    while (i >= 1) {
//        if (tree[i] > res)
//            res = tree[i];
//        i -= lowbit(i);
//    }
//    return res;
//}
//
//inline void clear(int i) {
//    while (i < MAXM) {
//        tree[i] = -INF;
//        i += lowbit(i);
//    }
//}
//
//void merge(int l, int mid, int r) {
//    int i = l, j = mid + 1;
//
//    for (; j <= r; ++j) {
//        while (i <= mid && arr[i].x <= arr[j].x) {
//            if (arr[i].op == 1) {
//                update(arr[i].y, arr[i].x + arr[i].y);
//            }
//            ++i;
//        }
//
//        if (arr[j].op == 2) {
//            int mx = query(arr[j].y);
//            if (mx != -INF) {
//                ans[arr[j].pos] = min(ans[arr[j].pos], arr[j].x + arr[j].y - mx);
//            }
//        }
//
//    }
//
//    for (int k = l; k < i; ++k) {
//        if (arr[k].op == 1) 
//            clear(arr[k].y);
//    }
//
//
//    inplace_merge(arr + l, arr + mid + 1, arr + r + 1, [](const Node& a, const Node& b) {
//        return a.x < b.x;
//     });
//}
//
//void cdq(int l, int r) {
//    if (l == r)
//        return;
//    int mid = l + ((r - l) >> 1);
//    cdq(l, mid);
//    cdq(mid + 1, r);
//    merge(l, mid, r);
//}
//
//void to1() {
//    for (int i = 1; i < cnt; i++)
//        arr[i] = tim[i];
//    cdq(1, cnt - 1);
//}
//
//void to2() {
//    for (int i = 1; i < cnt; i++) {
//        arr[i] = tim[i];
//        arr[i].x = v - arr[i].x;
//    }
//    cdq(1, cnt - 1);
//}
//
//void to3() {
//    for (int i = 1; i < cnt; i++) {
//        arr[i] = tim[i];
//        arr[i].x = v - arr[i].x;
//        arr[i].y = v - arr[i].y;
//    }
//    cdq(1, cnt - 1);
//}
//
//void to4() {
//    for (int i = 1; i < cnt; i++) {
//        arr[i] = tim[i];
//        arr[i].y = v - arr[i].y;
//    }
//    cdq(1, cnt - 1);
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    int n, m;
//    cin >> n >> m;
//
//    int qid = 1;
//    for (int i = 1; i <= n; ++i) {
//        int x, y;
//        cin >> x >> y;
//
//        x++; y++; 
//
//        tim[cnt].x = x;
//        tim[cnt].y = y;
//        tim[cnt].op = 1;
//        tim[cnt].pos = 0;
//
//        v = max(v, max(x, y));
//        cnt++;
//    }
//
//    for (int i = 1; i <= m; ++i) {
//        int op, x, y;
//        cin >> op >> x >> y;
//
//        x++; y++;
//
//        tim[cnt].x = x;
//        tim[cnt].y = y;
//        tim[cnt].op = op;
//
//        if (op == 2) 
//            tim[cnt].pos = qid++;
//        else 
//            tim[cnt].pos = 0;
//
//        v = max(v, max(x, y));
//        cnt++;
//    }
//    v++;
//
//    for (int i = 0; i < qid; i++)
//        ans[i] = INF;
//
//    for (int i = 0; i < MAXM; i++)
//        tree[i] = -INF;
//
//    to1();
//    to2();
//    to3();
//    to4();
//
//    for (int i = 1; i < qid; i++) 
//        cout << ans[i] << '\n';
//    
//    return 0;
//}
