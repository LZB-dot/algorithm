//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 2e5 + 5;
//
//int main() {
//
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int T;
//	cin >> T;
//
//	while (T--) {
//		int arr[MAXN];
//		int n;
//		cin >> n;
//		for (int i = 1; i <= n; ++i)
//			cin >> arr[i];
//		sort(arr + 1, arr + n);
//		bool isji = 0;
//		int mid = n / 2;
//		if (n % 2 != 0){
//			isji = 1;
//			mid++;
//		}
//		int ans = 0;
//		for (int i = 1; i < mid; ++i) {
//			ans += arr[mid] - arr[i];
//		}
//		for (int i = mid+1; i <=n; ++i) {
//			ans += arr[i] - arr[mid];
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}