//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//#define ll long long
//const int OFFSET = 400000;  //偏移量
//const int MAXN = 800001; 
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//    vector<int> iq(n + 1), eq(n + 1);
//   
//    for (int i = 1; i <= n; ++i) 
//        cin >> iq[i] >> eq[i];
//    
//
//    vector<int> dp(MAXN, -0x3f3f3f3f);
//    dp[OFFSET] = 0;  //IQ=0（偏移后下标400000），EQ=0
//
//    for (int i = 1; i <= n; i++) {
//        int curiq = iq[i];
//        int cureq = eq[i];
//        if (curiq >= 0) {
//            // IQ为正,逆序遍历
//            for (int j = MAXN - 1; j >= curiq; j--) 
//                if (dp[j - curiq] != -0x3f3f3f3f)
//                    dp[j] = max(dp[j], dp[j - curiq] + cureq);
//        }
//        else {
//            // IQ为负,正序遍历
//            for (int j = 0; j <= MAXN - 1 + curiq; j++) 
//                if (dp[j - curiq] != -0x3f3f3f3f) 
//                    dp[j] = max(dp[j], dp[j - curiq] + cureq);
//        }
//    }
//
//    ll ans = 0;
//    for (int i = OFFSET; i <= MAXN - 1; ++i) 
//        if (dp[i] >= 0)
//            ans = max(ans, (ll)i - OFFSET + dp[i]);
//
//    cout << ans << "\n";
//    return 0;
//}