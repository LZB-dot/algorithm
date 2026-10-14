//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//const int MAXN = 5005;
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int l, r, h;
//	vector<pair<int, int>>houses;
//
//	while (cin >> l >> h >> r) {
//		houses.push_back({ l,h });
//		houses.push_back({ r,-h });
//	}
//
//	sort(houses.begin(), houses.end(),
//		[](const pair<int, int>& a, const pair<int, int>& b) {
//			if (a.first != b.first)
//				return a.first < b.first;
//			return a.second > b.second;
//		});
//
//	priority_queue<int>heap;
//	vector<int>cnt(MAXN, 0);
//
//	heap.push(0);
//	cnt[0] = 1;
//	int preh = 0;
//	int m = houses.size();
//
//	for (auto& house : houses) {
//		int x = house.first;
//		int h = house.second;
//
//		if (h > 0) {
//			heap.push(h);
//			cnt[h]++;
//		}
//		else 
//			cnt[-h]--;
//		
//		while (!heap.empty() && cnt[heap.top()] == 0)
//			heap.pop();
//
//		int cur = heap.top();
//		if (cur != preh) {
//			cout << x << " " << cur << " ";
//			preh = cur;
//		}
//
//	}
//
//	cout << "\n";
//	return 0;
//}