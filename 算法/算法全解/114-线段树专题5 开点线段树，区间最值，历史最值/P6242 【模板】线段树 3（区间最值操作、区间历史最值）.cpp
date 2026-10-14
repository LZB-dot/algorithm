//#include<iostream>
//#include<climits>
//#include<cctype>
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 5e5 + 10;
//
//inline int read() {
//    int num = 0;
//    char c;
//    while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
//
//    bool flag = 0;
//    if (c == '-') 
//        flag = 1;
//    else 
//        num = c - '0';
//
//    while (isdigit(c = getchar()))
//        num = num * 10 + c - '0';
//
//    return flag ? -num : num;
//}
//
//int arr[MAXN];
//
//ll sum[MAXN << 2], mx[MAXN << 2], sem[MAXN << 2];
//int cnt[MAXN << 2];
//
//ll maxAdd[MAXN << 2], otherAdd[MAXN << 2];
//ll maxHistory[MAXN << 2], maxAddTop[MAXN << 2], otherAddTop[MAXN << 2];
//
//void up(int i) {
//    int l = i << 1;
//    int r = i << 1 | 1;
//
//    //更新累加和，最大值，历史最大值
//    sum[i] = sum[l] + sum[r];
//    mx[i] = max(mx[l], mx[r]);
//    maxHistory[i] = max(maxHistory[l], maxHistory[r]);
//
//    //更新最大值数量和次最大值
//    if (mx[l] > mx[r]) {
//        sem[i] = max(mx[r], sem[l]);
//        cnt[i] = cnt[l];
//    }
//    else if (mx[l] == mx[r]) {
//        sem[i] = max(sem[l], sem[r]);
//        cnt[i] = cnt[l] + cnt[r];
//    }
//    else {
//        sem[i] = max(mx[l], sem[r]);
//        cnt[i] = cnt[r];
//    }
//}
//
//
//void lazy(int i, int n, ll maxAddv, ll otherAddv, ll maxHisAddv, ll otherHisAddv) {
//    //当前历史最大值：最大值+历史最大值的增量
//    maxHistory[i] = max(maxHistory[i], mx[i] + maxHisAddv);
//    //当前历史最大值增量：历史最大值的增量+最大值的增量
//    maxAddTop[i] = max(maxAddTop[i], maxAdd[i] + maxHisAddv);
//    //当前历史其他值增量：历史其他值的增量+其他值的增量
//    otherAddTop[i] = max(otherAddTop[i], otherAdd[i] + otherHisAddv);
//
//    //累加和等于最大值*数量+其他值*数量
//    sum[i] += maxAddv * cnt[i] + otherAddv * (n - cnt[i]);
//    //更新最大值
//    mx[i] += maxAddv;
//
//    //更新次大值
//    if (sem[i] != LLONG_MIN)
//        sem[i] += otherAddv;
//
//    //更新增量
//    maxAdd[i] += maxAddv;
//    otherAdd[i] += otherAddv;
//}
//
//void down(int i, int ln, int rn) {
//    int l = i << 1;
//    int r = i << 1 | 1;
//    ll tmp = max(mx[l], mx[r]);
//
//    //如果左孩子最大值等于父亲最大值，所有消息都下发
//    if (mx[l] == tmp)
//        lazy(l, ln, maxAdd[i], otherAdd[i], maxAddTop[i], otherAddTop[i]);
//    //如果不相等，只下发次大值信息
//    else
//        lazy(l, ln, otherAdd[i], otherAdd[i], otherAddTop[i], otherAddTop[i]);
//
//    //如果右孩子最大值等于父亲最大值，所有消息都下发
//    if (mx[r] == tmp)
//        lazy(r, rn, maxAdd[i], otherAdd[i], maxAddTop[i], otherAddTop[i]);
//    //如果不相等，只下发次大值信息
//    else
//        lazy(r, rn, otherAdd[i], otherAdd[i], otherAddTop[i], otherAddTop[i]);
//
//    maxAdd[i] = otherAdd[i] = maxAddTop[i] = otherAddTop[i] = 0;
//}
//
//void build(int l, int r, int i) {
//    if (l == r) {
//        sum[i] = mx[i] = maxHistory[i] = arr[l];
//        sem[i] = LLONG_MIN;
//        cnt[i] = 1;
//    }
//    else {
//        int mid = l + ((r - l) >> 1);
//        build(l, mid, i << 1);
//        build(mid + 1, r, i << 1 | 1);
//        up(i);
//    }
//    maxAdd[i] = otherAdd[i] = maxAddTop[i] = otherAddTop[i] = 0;
//}
//
//void add(int jobl, int jobr, ll jobv, int l, int r, int i) {
//    if (jobl <= l && r <= jobr)
//        lazy(i, r - l + 1, jobv, jobv, jobv, jobv);
//    else {
//        int mid = l + ((r - l) >> 1);
//        down(i, mid - l + 1, r - mid);
//
//        if (jobl <= mid)
//            add(jobl, jobr, jobv, l, mid, i << 1);
//        if (jobr > mid)
//            add(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//
//        up(i);
//    }
//}
//
////A[l..r]范围上每个数A[i]变成min(A[i],v)
//void setMin(int jobl, int jobr, ll jobv, int l, int r, int i) {
//    //如果最大值小于jobv，不用更新
//    if (mx[i] <= jobv)
//        return;
//
//    //在次大值和最大值之间，懒标记
//    if (jobl <= l && r <= jobr && sem[i] < jobv)
//        lazy(i, r - l + 1, jobv - mx[i], 0, jobv - mx[i], 0);
//    else {
//        int mid = l + ((r - l) >> 1);
//        down(i, mid - l + 1, r - mid);
//
//        if (jobl <= mid)
//            setMin(jobl, jobr, jobv, l, mid, i << 1);
//        if (jobr > mid)
//            setMin(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//        up(i);
//    }
//}
//
//ll querySum(int jobl, int jobr, int l, int r, int i) {
//    if (jobl <= l && r <= jobr)
//        return sum[i];
//
//    int mid = l + ((r - l) >> 1);
//    down(i, mid - l + 1, r - mid);
//
//    ll ans = 0;
//    if (jobl <= mid) 
//        ans += querySum(jobl, jobr, l, mid, i << 1);
//
//    if (jobr > mid) 
//        ans += querySum(jobl, jobr, mid + 1, r, i << 1 | 1);
//    return ans;
//}
//
//ll queryMax(int jobl, int jobr, int l, int r, int i) {
//    if (jobl <= l && r <= jobr)
//        return mx[i];
//
//    int mid = l + ((r - l) >> 1);
//    down(i, mid - l + 1, r - mid);
//
//    ll ans = LLONG_MIN;
//    if (jobl <= mid)
//        ans = max(ans, queryMax(jobl, jobr, l, mid, i << 1));
//    if (jobr > mid) 
//        ans = max(ans, queryMax(jobl, jobr, mid + 1, r, i << 1 | 1));
//    return ans;
//}
//
//ll queryHisMax(int jobl, int jobr, int l, int r, int i) {
//    if (jobl <= l && r <= jobr)
//        return maxHistory[i];
//
//    int mid = l + ((r - l) >> 1);
//    down(i, mid - l + 1, r - mid);
//
//    ll ans = LLONG_MIN;
//    if (jobl <= mid)
//        ans = max(ans, queryHisMax(jobl, jobr, l, mid, i << 1));
//    if (jobr > mid)
//        ans = max(ans, queryHisMax(jobl, jobr, mid+1, r, i << 1 | 1));
//    return ans;
//}
//
//int main() {
//
//    int n = read(), m = read();
//
//    for (int i = 1; i <= n; i++)
//        arr[i] = read();
//
//    build(1, n, 1);
//
//    while (m--) {
//        int op = read(), l = read(), r = read();
//        if (op == 1) {
//            ll v = read();
//            add(l, r, v, 1, n, 1);
//        }
//        else if (op == 2) {
//            ll v = read();
//            setMin(l, r, v, 1, n, 1);
//        }
//        else if (op == 3) 
//            cout << querySum(l, r, 1, n, 1) << '\n';   
//        else if (op == 4) 
//            cout << queryMax(l, r, 1, n, 1) << '\n';
//        else if (op == 5) 
//            cout << queryHisMax(l, r, 1, n, 1) << '\n';
//        
//    }
//    return 0;
//}