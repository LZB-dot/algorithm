//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstdlib>  // 补充rand()/srand()头文件
//#include<ctime>    // 补充time()头文件
//using namespace std;
//
//// 暴力全排列解法
//int dfs(vector<vector<int>>& meetings, int i) {
//	int n = meetings.size();
//	if (i == n) {
//		int ans = 0;
//		int cur = -1;
//		for (const auto& meeting : meetings) {
//			if (cur <= meeting[0]) {
//				ans++;
//				cur = meeting[1];
//			}
//		}
//		return ans;
//	}
//	int res = 0;
//	for (int k = i; k < n; ++k) {
//		swap(meetings[i], meetings[k]);
//		res = max(res, dfs(meetings, i + 1));
//		swap(meetings[i], meetings[k]);
//	}
//	return res;
//}
//
//int way1(vector<vector<int>> meetings) {
//	return dfs(meetings, 0);
//}
//
//// 贪心解法
//int way2(vector<vector<int>> meetings) {
//	sort(meetings.begin(), meetings.end(),
//		[](const vector<int>m1, const vector<int>m2) {
//			return m1[1] < m2[1];
//		});
//
//	int ans = 0;
//	int pre = -1;
//	for (auto& meeting : meetings) {
//		if (meeting[0] >= pre) {
//			ans++;
//			pre = meeting[1];
//		}
//	}
//	return ans;
//}
//
//void test() {
//	srand(time(0)); // 初始化随机数种子（仅执行一次）
//	int n = 5;
//	for (int k = 0; k < 1000; ++k) {
//		vector<vector<int>> meetings(n, vector<int>(2));
//		for (int i = 0; i < n; ++i) {
//			meetings[i][0] = rand() % 100 + 1; // 开始时间：1~100
//			meetings[i][1] = meetings[i][0] + 1 + rand() % 20;
//		}
//
//		vector<vector<int>> meetings1 = meetings;
//		vector<vector<int>> meetings2 = meetings;
//
//		int p1 = way1(meetings1);
//		int p2 = way2(meetings2);
//
//		if (p1 != p2) {
//			cout << "出错的会议列表：" << endl;
//			for (int i = 0; i < n; ++i) {
//				cout << meetings[i][0] << " " << meetings[i][1] << endl;
//			}
//			cout << "暴力解结果：" << p1 << " 贪心解结果：" << p2 << endl;
//			cout << "====================" << endl;
//		}
//
//		if (k % 100 == 0) {
//			cout << "第" << k << "组测试完成" << endl;
//		}
//	}
//	cout << "所有测试完成！" << endl;
//}
//
//int main() {
//	test();
//	return 0;
//}