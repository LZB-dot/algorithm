//#include<iostream>
//#include<vector>
//#include<deque>
//#include<algorithm>
//#include<climits>
//using namespace std;
//
//int N, D;
//deque<int>mx;
//deque<int>mi;
//vector<pair<int, int>>arr;
//
//bool ok(int num) {
//	int mxVal, miVal;
//	if (!mx.empty()) {
//		mxVal = max(num, arr[mx.front()].second);
//	}
//	else {
//		mxVal = num;
//	}
//
//	if (!mi.empty()) {
//		miVal = min(num, arr[mi.front()].second);
//	}
//	else {
//		miVal = num;
//	}
//
//	return (mxVal - miVal) >= D;
//}
//
//void push(int r) {
//	while (!mx.empty() && arr[r].second >= arr[mx.back()].second) {
//		mx.pop_back();
//	}
//	mx.push_back(r);
//
//	while (!mi.empty() && arr[r].second <= arr[mi.back()].second) {
//		mi.pop_back();
//	}
//	mi.push_back(r);
//}
//
//void pop(int l) {
//	if (!mx.empty() && mx.front() == l) {
//		mx.pop_front();
//	}
//
//	if (!mi.empty() && mi.front() == l) {
//		mi.pop_front();
//	}
//}
//
//int work() {
//	sort(arr.begin(), arr.end());
//	int ans = INT_MAX;
//	for (int l = 0, r = 0; r < N; ++r) {
//		push(r);
//		while (l <= r && ok(arr[r].second)) {
//			ans = min(ans, arr[r].first - arr[l].first);
//			pop(l);
//			++l;
//		}
//	}
//	return ans == INT_MAX ? -1 : ans;
//}
//
//int main() {
//	cin >> N >> D;
//	arr.resize(N);
//	for (int i = 0; i < N; ++i) {
//		cin >> arr[i].first >> arr[i].second;
//	}
//	cout << work() << endl;
//	return 0;
//}