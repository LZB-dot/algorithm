//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//typedef long long ll;
//
//int rec[MAXN][4];
//// 扫描线：x, y1, y2, 标记(+1入边/-1出边)
//struct Line {
//    int x, y1, y2, val;
//} line[MAXN << 1];
//
//vector<int> ysort;     // 离散化y坐标
//
//int len[MAXN << 3];    // 区间总长度
//int times[MAXN << 3];  // 覆盖次数
//int cover[MAXN << 3];  // 有效覆盖长度
//
//int id(int x) {
//    return lower_bound(ysort.begin(), ysort.end(), x) - ysort.begin() + 1;
//}
//
////l和r是左右边界
//void up(int l, int r, int i) {
//    //如果已经有覆盖次数了，那么有效覆盖长度等于原全部长度
//    if (times[i] > 0)
//        cover[i] = len[i];
//    //如果到达叶子节点，且没被覆盖，那么有效覆盖长度为0
//    else if (l == r)
//        cover[i] = 0;
//    //如果都不是，那就等于左右孩子的有效覆盖长度之和
//    else
//        cover[i] = cover[i << 1] + cover[i << 1 | 1];
//}
//
//void build(int l, int r, int i) {
//    if (l == r) 
//        //ysort从0开始
//        //如第一段0-1就是 ysort[1] - ysort[0]
//        len[i] = ysort[l] - ysort[l - 1];
//    else {
//        int mid = l + ((r - l) >> 1);
//        build(l, mid, i << 1);
//        build(mid + 1, r, i << 1 | 1);
//        up(l, r, i);
//    }
//    times[i] = cover[i] = 0;
//}
//
//void add(int jobl, int jobr, int jobv, int l, int r, int i) {
//    if (jobl <= l && r <= jobr) {
//        //+1入边  -1出边
//        times[i] += jobv;
//        up(l, r, i);
//    }
//    else {
//        int mid = l + ((r - l) >> 1);
//        if (jobl <= mid)
//            add(jobl, jobr, jobv, l, mid, i << 1);
//        if (jobr > mid)
//            add(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//
//        up(l, r, i);
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//
//    // 输入矩形
//    for (int i = 1; i <= n; ++i)
//        cin >> rec[i][0] >> rec[i][1] >> rec[i][2] >> rec[i][3];
//
//    int x1, x2, y1, y2;
//    for (int i = 1, j = 1 + n; i <= n; ++i, ++j) {
//        x1 = rec[i][0];
//        y1 = rec[i][1];
//        x2 = rec[i][2];
//        y2 = rec[i][3];
//
//        //把每一根扫描线添加进去，1是开始边，-1是结束边
//        line[i] = { x1, y1, y2, 1 };
//        line[j] = { x2, y1, y2, -1 };
//
//        ysort.push_back(y1);
//        ysort.push_back(y2);
//    }
//  
//    sort(ysort.begin(), ysort.end());
//    ysort.erase(unique(ysort.begin(), ysort.end()), ysort.end());
//    int m = ysort.size();
//
//    sort(line + 1, line + 2 * n + 1, 
// [](const Line& a, const Line& b) {
//        return a.x < b.x;
//        });
//
//    build(1, m, 1);
//
//    ll ans = 0;
//    int prex = 0;
//    for (int i = 1; i <= (n << 1); ++i) {
//        int curx = line[i].x;
//        int y1 = line[i].y1;
//        int y2 = line[i].y2;
//        int jobv = line[i].val;
//
//        //先添加矩形长度
//        if (curx > prex)
//            ans += 1LL * cover[1] * (curx - prex);
//
//        //计算左右离散化边界
//        int jobl = id(y1);
//        //-1化成点，如100 200对应1 2，那么实际只有一个节点这个范围
//        int jobr = id(y2) - 1;
//
//        add(jobl, jobr, jobv, 1, m, 1);
//
//        prex = curx;
//    }
//    
//    cout << ans << endl;
//    return 0;
//}