//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//#define ll long long
//
//int n, m;
//vector<int> nums;
//
//bool cal(int h) {
//    ll ans = 0;
//    for (int i : nums) {
//        if (i <= h) 
//            break; 
//        ans += i - h;
//      
//        if (ans >= m) 
//            return true;
//    }
//    return ans >= m;
//}
//
//void binary() {
//    int l = 0, r = nums[0];
//    int ans = 0;
//    while (l <= r) { 
//        int mid = l + ((r - l) >> 1); 
//        if (cal(mid)) { 
//            ans = mid;
//            l = mid + 1;
//        }
//        else { 
//            r = mid - 1;
//        }
//    }
//    cout << ans << "\n";
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> m;
//    nums.resize(n);
//    for (int i = 0; i < n; ++i) 
//        cin >> nums[i];
//    
//    sort(nums.begin(), nums.end(), greater<int>());
//    binary();
//    return 0;
//}