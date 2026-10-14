//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//using namespace std;
//
//#define ll long long
//
////环的最大字段和=max（跨越首尾的最大字段和，线性最大字段和）
////跨越首尾的最大字段和=总和-最小字段和
//
//void solve() {
//    int n;
//    cin >> n;
//
//    vector<int> nums(n); 
//    ll sum = 0;
//    for (int i = 0; i < n; ++i) {
//        cin >> nums[i];
//        sum += nums[i];
//    }
//
//    ll curmx = nums[0], curmi = nums[0];
//    ll endmx = nums[0], endmi = nums[0];
//
//    for (int i = 1; i < n; ++i) {
//        curmx = max((ll)nums[i], curmx + nums[i]);
//        curmi = min((ll)nums[i], curmi + nums[i]);
//        endmx = max(endmx, curmx);
//        endmi = min(endmi, curmi);
//    }
//    
//    ll ans = max(endmx, sum - endmi);
//    cout << ans << "\n";
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    solve();
//    return 0;
//}