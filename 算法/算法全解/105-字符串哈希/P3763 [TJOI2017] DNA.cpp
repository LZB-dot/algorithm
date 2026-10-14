//#include<iostream>
//#include<vector>
//using namespace std;
//
//typedef unsigned long long ull;
//const int base = 499;
//const int MAXN = 1e5 + 10;
//
//vector<ull> power(MAXN);
//vector<ull> hash0(MAXN);
//vector<ull> hash1(MAXN);
//string s0, s1;
//int k = 3;
//
//void init() {
//    power[0] = 1;
//    for (int i = 1; i < MAXN; ++i)
//        power[i] = power[i - 1] * base;
//}
//
//void build() {
//    int n = s0.size();
//    if (n > 0) {
//        hash0[0] = s0[0] - 'a' + 1; 
//        for (int i = 1; i < n; ++i)
//            hash0[i] = hash0[i - 1] * base + (s0[i] - 'a' + 1);
//    }
//
//    int m = s1.size();
//    if (m > 0) {
//        hash1[0] = s1[0] - 'a' + 1;
//        for (int i = 1; i < m; ++i)
//            hash1[i] = hash1[i - 1] * base + (s1[i] - 'a' + 1);
//    }
//}
//
//ull getHash(const vector<ull>& h, int l, int r) {
//    if (l > r)
//        return 0;
//    ull res = h[r];
//    if (l > 0)
//        res -= h[l - 1] * power[r - l + 1];
//    return res;
//}
//
////检查s0从l0开始、s1从l1开始的长度为len的子串是否相等
//bool same(int l0, int l1, int len) {
//    if (l0 + len - 1 >= s0.size() || l1 + len - 1 >= s1.size())
//        return false; 
//    int r0 = l0 + len - 1;
//    int r1 = l1 + len - 1;
//    return getHash(hash0, l0, r0) == getHash(hash1, l1, r1);
//}
//
////检查s0中从l0到r0的子串是否能通过最多k次修改匹配s1对应长度的子串
//bool check(int l0, int r0) {
//    int diff = 0;          //记录需要修改的次数
//    int pos0 = l0;         //s0的当前匹配位置
//    int pos1 = 0;          //s1的当前匹配位置
//    int len = r0 - l0 + 1; //待匹配的子串长度（等于s1的长度）
//
//    while (pos0 <= r0 && diff <= k) {
//        //二分查找当前位置能匹配的最大长度
//        int left = 0, right = len - pos1; //剩余可匹配的最大长度
//        int mx = 0;
//        while (left <= right) {
//            int mid = left + ((right - left) >> 1); 
//            if (mid == 0) {
//                mx = 0;
//                left = mid + 1;
//                continue;
//            }
//      
//            if (same(pos0, pos1, mid)) {
//                mx = mid;
//                left = mid + 1;
//            }
//            else 
//                right = mid - 1; 
//        }
//
//        //跳过已匹配的部分
//        pos0 += mx;
//        pos1 += mx;
//
//        if (pos0 <= r0) {
//            diff++;     
//            pos0++;   
//            pos1++;  
//        }
//    }
//
//    return diff <= k && pos0 > r0;
//}
//
//void solve() {
//
//    cin >> s0;
//    cin >> s1;
//    int n = s0.size();
//    int m = s1.size();
//    int ans = 0;
//
//    fill(hash0.begin(), hash0.end(), 0);
//    fill(hash1.begin(), hash1.end(), 0);
//    build(); 
//
//    for (int i = 0; i <= n - m; ++i) {
//        if (check(i, i + m - 1))
//            ++ans;
//    }
//
//    cout << ans << endl;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int T;
//    cin >> T;
//
//    init(); 
//
//    while (T--)
//        solve();
//
//    return 0;
//}