//#include<iostream>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 10000;
//
//int dp[MAXN];
//
//int work(int n) {
//    if (n == 1) 
//        return 1;
//    if (dp[n] != -1)
//        return dp[n];
//    long long ans = 1;
//    for (int i = 1; i <= n >> 1; ++i) {    
//        ans += work(i);
//    }
//    dp[n] = ans;
//    return ans;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    memset(dp, -1, MAXN);
//    cout << work(n) << endl;
//    return 0;
//}