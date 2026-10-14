////#include<iostream>
////#include<vector>
////
////using namespace std;
////
////typedef long long ll;
////
////const int MAXN = 5e5 + 10;
////int n;
////int nums[MAXN];
////int help[MAXN];
////
//////统计[l, r]区间跨mid的逆序对，并合并有序
////ll merge(int l, int m, int r) {
////    ll ans = 0;
////    // 统计跨区间逆序对：左区间[l,m]，右区间[m+1,r]
////    for (int i = m, j = r; i >= l; --i) {
////        // 找到右区间中第一个比nums[i]小的元素
////        while (j >= m + 1 && nums[i] <= nums[j]) {
////            --j;
////        }
////        // j - m 是右区间中比nums[i]小的元素个数（逆序对数量）
////        ans += j - m;
////    }
////
////    // 合并两个有序区间到辅助数组
////    int i = l;
////    int a = l, b = m + 1;
////    while (a <= m && b <= r)
////        help[i++] = (nums[a] <= nums[b]) ? nums[a++] : nums[b++];
////
////    // 处理左区间剩余元素
////    while (a <= m)
////        help[i++] = nums[a++];
////
////    // 处理右区间剩余元素
////    while (b <= r)
////        help[i++] = nums[b++];
////
////    for (i = l; i <= r; ++i)
////        nums[i] = help[i];
////
////
////    return ans;
////}
////
//////计算[l, r]区间的逆序对数量
////ll solve(int l, int r) {
////    if (l == r)
////        return 0;
////
////    int mid = l + ((r - l) >> 1);
////    //总逆序对 = 左区间 + 右区间 + 跨区间
////    return solve(l, mid) + solve(mid + 1, r) + merge(l, mid, r);
////}
////
////int main() {
////    ios::sync_with_stdio(false);
////    cin.tie(nullptr);
////
////    cin >> n;
////    for (int i = 1; i <= n; ++i)
////        cin >> nums[i];
////
////    cout << solve(1, n) << "\n";
////
////    return 0;
////}
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 5e5 + 10;
//int n, m;        
//int nums[MAXN];   
//int tree[MAXN];   
//vector<int> tmp; 
//
//inline int lowbit(int i) {
//    return i & -i;
//}
//
//inline void add(int i, int v) {
//    while (i <= m) { 
//        tree[i] += v;
//        i += lowbit(i);
//    }
//}
//
//inline ll sum(int i) {
//    ll ans = 0;
//    while (i > 0) {  
//        ans += tree[i];
//        i -= lowbit(i);
//    }
//    return ans;
//}
//
//inline int getrank(int x) {
//    // lower_bound找第一个≥x的位置，+1让排名从1开始
//    return lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin() + 1;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n;
//    for (int i = 1; i <= n; ++i) {
//        cin >> nums[i];
//        tmp.push_back(nums[i]); 
//    }
//
//    sort(tmp.begin(), tmp.end());                          // 排序
//    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());  // 去重
//    m = tmp.size();                                        // 离散化后的值域大小
//
//    ll ans = 0;
//    for (int i = n; i >= 1; --i) {
//        int rk = getrank(nums[i]);         
//        ans += sum(rk - 1);                
//        add(rk, 1);                         
//    }
//
//    cout << ans << "\n";
//
//    return 0;
//}
