//
////https://www.luogu.com.cn/problem/P3372
//
//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 100005;
//
//ll arr[MAXN];
//ll sum[MAXN << 2];// 线段树维护的区间和数组，4倍空间是线段树标配
//ll increase[MAXN << 2];// 懒标记数组，存储区间待更新的增量
//
//// 向上更新：用左右孩子的sum更新当前节点的sum
//void up(int rt) {
//    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
//}
//
//// 作用：给 rt 节点打上懒标记（区间加）
//// rt: 节点编号   v: 要加的值   n: 节点代表的区间长度
//void lazy(int rt, ll v, int n) {
//    sum[rt] += v * n;    // 更新当前节点的区间和
//    increase[rt] += v;       // 累加懒标记
//}
//
//// 向下传递懒标记
//// rt:当前节点编号  ln:左孩子区间长度  rn:右孩子区间长度
//void down(int rt, int ln, int rn) {
//    // 如果父节点有懒标记，需要下传给孩子节点
//    if (increase[rt] != 0) {
//        // 调用统一的 lazy 函数给左右孩子打标记
//        lazy(rt << 1, increase[rt], ln);
//        lazy(rt << 1 | 1, increase[rt], rn);
//
//        // 清空当前节点的懒标记
//        increase[rt] = 0;
//    }
//}
//
//// 建树函数
//// l:当前节点代表区间左边界 r:右边界 rt:当前节点编号
//void build(int l, int r, int rt) {
//    // 叶子节点：直接赋值为原数组值
//    if (l == r) 
//        sum[rt] = arr[l];
//    else {
//        int mid = l + ((r - l) >> 1);
//        // 递归建左子树
//        build(l, mid, rt << 1);
//        // 递归建右子树
//        build(mid + 1, r, rt << 1 | 1);
//        // 向上合并子节点信息
//        up(rt);
//    }
//    // 初始化懒标记为0
//    increase[rt] = 0;
//}
//
//// 区间加操作
//// jobl,jobr:要加的目标区间 jobv:要加的值
//// l,r,rt:当前节点的区间和编号
//void add(int jobl, int jobr, ll jobv, int l, int r, int rt) {
//    // 当前节点区间 完全包含 在目标区间内：直接更新，打懒标记，不用下发
//    if (jobl <= l && r <= jobr) 
//        lazy(rt, jobv, r - l + 1);
//    else {
//        // 否则需要拆分区间，先下传懒标记
//        int mid = l + ((r - l) >> 1);
//        down(rt, mid - l + 1, r - mid);
//        // 左子区间有交集，递归更新左子树
//        if (jobl <= mid)
//            add(jobl, jobr, jobv, l, mid, rt << 1);
//
//        // 右子区间有交集，递归更新右子树
//        if (jobr > mid)
//            add(jobl, jobr, jobv, mid + 1, r, rt << 1 | 1);
//
//        // 更新完成后向上合并
//        up(rt);
//    }
//}
//
//// 区间查询和函数
//ll query(int jobl, int jobr, int l, int r, int rt) {
//    // 当前节点区间完全包含在目标区间：直接返回sum
//    if (jobl <= l && r <= jobr)
//        return sum[rt];
//
//    // 拆分区间，先下传懒标记
//    int mid = l + ((r - l) >> 1);
//    down(rt, mid - l + 1, r - mid);
//    ll ans = 0;
//    // 左子区间有交集，累加左子树结果
//    if (jobl <= mid)
//        ans += query(jobl, jobr, l, mid, rt << 1);
//
//    // 右子区间有交集，累加右子树结果
//    if (jobr > mid)
//        ans += query(jobl, jobr, mid + 1, r, rt << 1 | 1);
//
//    return ans;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= n; ++i) {
//        cin >> arr[i];
//    }
//    build(1, n, 1);
//
//    int op, jobl, jobr;
//    ll jobv;
//    while (m--) {
//        cin >> op;
//        if (op == 1) {
//            cin >> jobl >> jobr >> jobv;
//            add(jobl, jobr, jobv, 1, n, 1);
//        }
//        else {
//            cin >> jobl >> jobr;
//            cout << query(jobl, jobr, 1, n, 1) << '\n';
//        }
//    }
//    return 0;
//}