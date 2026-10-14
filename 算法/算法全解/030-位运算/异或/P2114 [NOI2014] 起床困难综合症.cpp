//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//#define ll long long
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    ll m;
//    cin >> n >> m;
//
//    vector<pair<string, int>> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i].first >> nums[i].second;
//
//    int f0[30] = { 0 }; //初始位为0时，经过所有操作后该位的结果
//    int f1[30] = { 0 }; //初始位为1时，经过所有操作后该位的结果
//
//    //预计算每一位初始为0/1时，经过所有操作后的结果
//    for (int bit = 0; bit <= 29; ++bit) {
//        int val0 = 0;
//        int val1 = 1;
//        ll mask = 1LL << bit;
//
//        for (auto& it : nums) {
//            // 取出操作数t的第bit位
//            int cur = (it.second & mask) ? 1 : 0;
//
//            if (it.first == "AND") {
//                val0 &= cur;
//                val1 &= cur;
//            }
//            else if (it.first == "OR") {
//                val0 |= cur;
//                val1 |= cur;
//            }
//            else {
//                val0 ^= cur;
//                val1 ^= cur;
//            }
//        }
//
//        f0[bit] = val0;
//        f1[bit] = val1;
//    }
//
//    ll ans = 0; //最大伤害值
//    ll x = 0;   //初始攻击力
//
//    //从高位到低位贪心选择初始位
//    for (int bit = 29; bit >= 0; --bit) {
//        ll mask = 1LL << bit;
//        // 尝试把当前位设为1
//        ll tmp = x | mask;
//        if (tmp <= m) {
//            int res1 = f1[bit];
//            int res0 = f0[bit];
//            if (res1 > res0) {
//                x = tmp;
//            }
//        }
//    }
//
//    for (int bit = 0; bit <= 29; ++bit) {
//        ll mask = 1LL << bit;
//        int val = (x & mask) ? 1 : 0;
//        int res = (val == 1) ? f1[bit] : f0[bit];
//        if (res) 
//            ans |= mask;
//    }
//
//    cout << ans << "\n";
//
//    return 0;
//}