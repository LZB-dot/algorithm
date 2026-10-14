//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll; 
//
//ll cal(const vector<int>& woods, int len) {
//    ll sum = 0;
//    for (int wood : woods) 
//        sum += wood / len;
//    
//    return sum;
//}
//
//int main() {
//    ios::sync_with_stdio(false); 
//    cin.tie(nullptr);
//
//    int n, k;
//    cin >> n >> k;
//
//    vector<int> woods(n);
//    int mx = 0;
//    for (int i = 0; i < n; ++i) 
//        cin >> woods[i];
//
//    mx = *max_element(woods.begin(), woods.end());
//    int left = 1, right = mx;
//    int ans = 0; 
//    while (left <= right) {
//        int mid = left + ((right - left) >> 1);
//        ll total = cal(woods, mid);
//
//        if (total >= k) {
//            ans = mid;
//            left = mid + 1;
//        }
//        else {
//            right = mid - 1;
//        }
//    }
//
//    cout << ans << endl;
//    return 0;
//}