//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<unordered_map>
//using namespace std;
//
//const string target = "123804765";
//int d[] = { -1,0,1,0,-1 };
//
//int main() {
//
//	string s;
//	cin >> s;
//
//	int sum = 0;
//	if (s == target) {
//		cout << "0\n";
//		return 0;
//	}
//
//	queue<string>q1, q2;
//	q1.push(s);
//	q2.push(target);
//	unordered_map<string, int>mp1, mp2;//记录到达该状态的距离
//	mp1[s] = 0;
//	mp2[target] = 0;
//
//	while (!q1.empty() && !q2.empty()) {
//		if (q1.size() > q2.size()) {
//			swap(q1, q2);
//			swap(mp1, mp2);
//		}
//
//		int size_ = q1.size();
//		for (int i = 0; i < size_; ++i) {
//			string cur = q1.front();
//			q1.pop();
//
//			int idx = cur.find('0');
//			int x = idx / 3;
//			int y = idx % 3;
//
//			for (int i = 0; i < 4; ++i) {
//				int dx = x + d[i];
//				int dy = y + d[i + 1];
//
//				if (dx >= 3 || dy >= 3 || dx < 0 || dy < 0)
//					continue;
//
//				string nxt = cur;
//				int exch = 3 * dx + dy;
//				swap(nxt[exch], nxt[idx]);
//				if (mp1.count(nxt))
//					continue;
//
//				if (mp2.count(nxt)) {
//					cout << mp1[cur] + 1 + mp2[nxt] << "\n";
//					return 0;
//				}
//
//				mp1[nxt] = mp1[cur] + 1;
//				q1.push(nxt);
//			}
//
//		}
//
//	}
//
//	return 0;
//}
//
//
//
//
