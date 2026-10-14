////执行所有任务的最少初始电量
////
////每一个任务有两个参数：
////cost[i]：完成该任务需要耗费的电量
////need[i]：开始执行该任务时，手机至少需要拥有的电量
////
////你需要确定一个最小的初始电量，使得手机可以执行完所有任务。
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int way(const vector<int>& cost, const vector<int>& need) {
//	vector<pair<int, int>>projects;
//	for (int i = 0; i < cost.size(); ++i) {
//		projects.push_back({ cost[i], need[i] });
//	}
//
//	sort(projects.begin(), projects.end(),
//		[](const pair<int, int>& a, const pair<int, int>& b) {
//			return a.first - a.second > b.first - b.second;
//		});
//
//	int ans = 0;
//	for (auto& p : projects) {
//		int c = p.first;
//		int n = p.second;
//		ans = max(n, c + ans);
//	}
//
//	return ans;
//}