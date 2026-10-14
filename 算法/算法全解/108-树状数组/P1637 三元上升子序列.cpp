//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 3e4 + 10;
//// tree1：以某个值结尾的升序一元组数量（每个数自身）
//// tree2：以某个值结尾的升序二元组数量（前面更小的数的一元组之和）
//ll tree1[MAXN], tree2[MAXN];
//int n, m;
//vector<int> tmp;
//vector<int> nums;
//
//inline int lowbit(int i) {
//    return i & -i;
//}
//
//inline void add(int p, ll v, ll tree[]) {
//    while (p <= m) {
//        tree[p] += v;
//        p += lowbit(p);
//    }
//}
//
//inline ll sum(int p, ll tree[]) {
//    ll ans = 0;
//    while (p > 0) {
//        ans += tree[p];
//        p -= lowbit(p);
//    }
//    return ans;
//}
//
//inline int getRank(int val) {
//    return lower_bound(tmp.begin(), tmp.end(), val) - tmp.begin() + 1;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n;
//    nums.resize(n + 1);
//    for (int i = 1; i <= n; ++i) {
//        cin >> nums[i];
//        tmp.push_back(nums[i]);
//    }
//
//    sort(tmp.begin(), tmp.end());
//    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
//    m = tmp.size(); 
//
//    ll ans = 0;
//    for (int i = 1; i <= n; ++i) {
//        int rk = getRank(nums[i]);
//
//        // 所有排名<rk的数的二元组数量之和 = 三元组数量
//        ans += sum(rk - 1, tree2);
//
//        //更新一元组数量
//        add(rk, 1, tree1);
//
//        ll cnt1 = sum(rk - 1, tree1); // 排名<rk的一元组总数
//        add(rk, cnt1, tree2);
//    }
//
//    cout << ans << "\n";
//    return 0;
//}