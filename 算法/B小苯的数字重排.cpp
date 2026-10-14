//#include<iostream>
//#include<climits>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 2e5 + 5;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//	while (n--) {
//		int s;
//		cin >> s;
//		int arr[MAXN];
//		long long sum = 0;
//		for (int i = 0; i < s; ++i) {
//			cin >> arr[i];
//			sum += arr[i];
//		}
//		sort(arr, arr + s);
//		cout << sum * 2 - arr[1] - arr[0] << endl;
//	}
//	return 0;
//}