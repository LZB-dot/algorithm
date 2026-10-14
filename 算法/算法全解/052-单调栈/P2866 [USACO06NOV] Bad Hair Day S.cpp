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
//    vector<int>nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    
//    int r = 0;
//    vector<int>st(n);
//    ll ans = 0;
//    for (int i = 0; i < n; ++i) {
//        while (r > 0 && nums[i] >= nums[st[r - 1]]) {
//            int top = st[--r];
//            ans += i - top - 1;
//        }
//        st[r++] = i;
//    }
//
//    while (r > 0) {
//        int top = st[--r];
//        ans += n - top - 1;
//    }
//
//    cout << ans << "\n";
//
//
//   
//
//    return 0;
//}