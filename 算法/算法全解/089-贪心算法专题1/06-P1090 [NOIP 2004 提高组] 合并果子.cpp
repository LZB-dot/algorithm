//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//
//int main() {
//	int n;
//	cin >> n;
//	int x;
//	priority_queue<int, vector<int>, greater<int>>min_heap;
//	for (int i = 0; i < n; ++i) {
//		cin >> x;
//		min_heap.push(x);
//	}
//	int sum = 0;
//	while (min_heap.size() != 1) {
//		int p1= min_heap.top();
//		min_heap.pop();
//		int p2 = min_heap.top();
//		min_heap.pop();
//		int tmp = p1 + p2;
//		sum += tmp;
//		min_heap.push(tmp);
//	}
//
//	cout << sum << endl;
//
//	return 0;
//}