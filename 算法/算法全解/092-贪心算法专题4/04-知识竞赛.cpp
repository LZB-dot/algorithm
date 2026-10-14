//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<pair<int, int>>ability(n);
//	for (int i = 0; i < n; ++i)
//		cin >> ability[i].first >> ability[i].second;
//
//	sort(ability.begin(), ability.end(),
//		[](const pair<int, int>& a, const pair<int, int>& b) {
//			return abs(a.first - a.second) < abs(b.first - b.second);
//		});
//
//
//	int sum = 0;
//	int mx1 = ability[0].first, mx2 = ability[0].second;
//	for (int i = 1; i < n; ++i) {
//		if (ability[i].first > ability[i].second) {
//			sum = max(sum, ability[i].second + mx2);
//		}
//		else {
//			sum = max(sum, ability[i].first + mx1);
//		}
//
//		mx1 = max(mx1, ability[i].first);
//		mx2 = max(mx2, ability[i].second);
//	}
//
//	double ans = sum / 2;
//	printf("%.1lf\n", ans);
//	return 0;
//}