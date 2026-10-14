//#include<iostream>
//#include<vector>
//#include<cstring>
//
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 1e6 + 10;
//const int MOD = 19930726;
//
//ll cnt[MAXN] = { 0 };
//
//ll power(ll a, ll b) {
//    ll ans = 1;
//    a %= MOD;  
//    while (b > 0) {
//        if (b & 1)
//            ans = (ans * a) % MOD;
//        b >>= 1;
//        a = (a * a) % MOD;
//    }
//    return ans;
//}
//
//void manacher(const string& s) {
//    string ss;
//    for (char c : s) {
//        ss += '#';
//        ss += c;
//    }
//    ss += '#';
//
//    int n = ss.size();
//    int r = 0, c = 0;
//    vector<int> p(n);
//
//    for (int i = 0; i < n; ++i) {
//        int len = r > i ? min(r - i, p[2 * c - i]) : 1;
//
//        while (i + len < n && i - len >= 0 && ss[i + len] == ss[i - len])
//            ++len;
//
//        if (i + len > r) {
//            r = i + len;
//            c = i;
//        }
//
//        p[i] = len;
//
//        int cur = len - 1;
//        if ((cur & 1) && cur >= 1) {
//            cnt[cur]++;
//        }
//    }
//
//    for (int i = MAXN - 3; i >= 1; i -= 2) {
//        cnt[i] += cnt[i + 2];
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    memset(cnt, 0, sizeof(cnt));  
//
//    ll n, k;
//    cin >> n >> k;
//    string s;
//    cin >> s;
//
//    manacher(s);
//
//    ll ans = 1;
//    ll remain = k;
//
//    for (int i = MAXN - 1; i >= 1; i -= 2) {
//        if (cnt[i] == 0)
//            continue;
//
//        if (cnt[i] <= remain) {
//            ans = (ans * power(i, cnt[i])) % MOD;
//            remain -= cnt[i];
//        }
//        else {
//            ans = (ans * power(i, remain)) % MOD;
//            remain = 0;
//        }
//
//        if (remain == 0) 
//            break;
//    }
//
//    if (remain > 0) 
//        cout << "-1\n";
//    
//    else 
//        cout << ans << "\n";
//    
//
//    return 0;
//}