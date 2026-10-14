//#include<iostream>
//#include<vector>
//#include<climits>
//#include<algorithm>
//using namespace std;
//
//#define ll long long
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//    vector<int>h(n), v(n);
//    for (int i = 0; i < n; ++i)
//        cin >> h[i] >> v[i];
//
//    int r = 0;
//    vector<int>st(n);
//    vector<ll>ans(n);
//
//    for (int i = 0; i < n; ++i) {
//        //ะกันด๓
//        while (r > 0 && h[i] > h[st[r - 1]]) {
//            int idx = st[--r];
//            ans[i] += v[idx];
//            if (r > 0)
//                ans[st[r - 1]] += v[idx];
//        }
//        st[r++] = i;
//    }
//
//    while (r > 0) {
//        int idx = st[--r];
//        if (r > 0)
//            ans[st[r - 1]] += v[idx];
//    }
//
//    cout << *max_element(ans.begin(), ans.end()) << "\n";
//
//    
//
//    return 0;
//}