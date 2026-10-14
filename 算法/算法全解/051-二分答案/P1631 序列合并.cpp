//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//vector<ll> a, b;
//int n;
//
//bool check(ll mid) {
//    int cnt = 0;
//    int j = n - 1;
//    for (int i = 0; i < n; ++i) {
//        while (j >= 0 && a[i] + b[j] > mid)
//            --j;
//        cnt += j + 1;
//        if (cnt >= n)
//            return true;
//    }
//    return cnt >= n;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n;
//    a.resize(n);
//    b.resize(n);
//    for (int i = 0; i < n; ++i)
//        cin >> a[i];
//    sort(a.begin(), a.end());
//    for (int i = 0; i < n; ++i)
//        cin >> b[i];
//    sort(b.begin(), b.end());
//
//    ll l = a[0] + b[0], r = a.back() + b.back();
//    ll ans = r;
//    while (l <= r) {
//        ll mid = l + ((r - l) >> 1);
//        if (check(mid)) {
//            ans = mid;
//            r = mid - 1;
//        }
//        else {
//            l = mid + 1;
//        }
//    }
//
//    vector<ll> res;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            ll tmp = a[i] + b[j];
//            if (tmp <= ans)
//                res.push_back(tmp);
//            else
//                break;
//        }
//    }
//
//    sort(res.begin(), res.end());
//    for (int k = 0; k < n; ++k) {
//        if (k > 0) cout << " ";
//        cout << res[k];
//    }
//    cout << "\n";
//    return 0;
//}