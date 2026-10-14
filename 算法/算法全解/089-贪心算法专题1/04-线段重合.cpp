//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<pair<int, int>>grid;
//	int a, b;
//	for (int i = 0; i < n; ++i) {
//		cin >> a >> b;
//		grid.emplace_back(a, b);
//	}
//
//	sort(grid.begin(), grid.end(), 
//		[](const pair<int,int>& a, const pair<int, int>& b) {
//			return a.first < b.first;
//		});
//
//	int mx = 0;
//	//Ð¡¸ù¶Ñ
//	priority_queue<int, vector<int>, greater<int>>min_heap;
//
//	for (const auto& line : grid) {
//		int st = line.first;
//		int ed = line.second;
//
//		while (!min_heap.empty() && min_heap.top() <= st) {
//			min_heap.pop();
//		}
//
//		min_heap.push(ed);
//		mx = max(mx, (int)min_heap.size());
//	}
//
//	cout << mx << endl;
//	return 0;
//}