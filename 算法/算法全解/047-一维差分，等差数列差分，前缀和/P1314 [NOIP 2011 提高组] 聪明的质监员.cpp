//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<climits>
//using namespace std;
//
//#define ll long long
//
//vector<pair<int, int>> query;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m;
//    ll s; 
//    cin >> n >> m >> s;
//
//    vector<int> w(n + 1);
//    vector<int> v(n + 1); 
//    for (int i = 1; i <= n; ++i)
//        cin >> w[i] >> v[i];
//
//    query.resize(m);
//    for (int i = 0; i < m; ++i)
//        cin >> query[i].first >> query[i].second;
//
//    int left = 0;
//    int right = *max_element(w.begin() + 1, w.end());
//
//    ll ans = LLONG_MAX; 
//    while (left <= right) {
//        int mid = left + ((right - left) >> 1);
//
//        vector<ll> sumw(n + 1, 0), sumv(n + 1, 0); 
//        for (int i = 1; i <= n; ++i) {
//           
//            sumw[i] = sumw[i - 1] + (w[i] >= mid ? 1 : 0);
//            sumv[i] = sumv[i - 1] + (w[i] >= mid ? (ll)v[i] : 0);
//        }
//
//        ll cur = 0; 
//        for (auto it : query) {
//            int l = it.first, r = it.second;
//            cur += (sumw[r] - sumw[l - 1]) * (sumv[r] - sumv[l - 1]);
//        }
//
//        ll diff = abs(cur - s); 
//
//        if (diff < ans)
//            ans = diff;
//
//        if (cur > s)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//
//    cout << ans << "\n";
//
//    return 0;
//}