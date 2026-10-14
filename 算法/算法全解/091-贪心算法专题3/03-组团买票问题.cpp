//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>  // 新增：max函数需要
//#include<cstdlib>
//#include<ctime>
//using namespace std;
//
//#define ll long long
//
////Game构造函数参数顺序（Ki, Bi），earn逻辑正确
//struct Game {
//	int ki;  // 折扣系数
//	int bi;  // 基础票价
//	int people;  // 记录当前选该项目的人数
//
//	// 参数顺序 Ki -> ki，Bi -> bi
//	Game(int ki_val, int bi_val) : ki(ki_val), bi(bi_val), people(0) {}
//
//	// 计算新增1人时的收益：bi - ki*(2*people + 1)
//	int earn() const {
//		return bi - (2 * people + 1) * ki;
//	}
//};
//
//// 大根堆比较器（优先收益大的项目）
//struct Compare {
//	bool operator()(const Game& a, const Game& b) const {
//		return a.earn() < b.earn();
//	}
//};
//
//// 贪心解法（way1）- 修复后
//ll way1(int n, const vector<vector<int>>& games) {
//	priority_queue<Game, vector<Game>, Compare> heap;
//	// 传入(Ki, Bi)，构造函数已匹配
//	for (const auto& g : games) {
//		heap.emplace(g[0], g[1]);
//	}
//
//	ll ans = 0;
//	for (int i = 0; i < n; ++i) {
//		if (heap.empty()) break;
//		Game g = heap.top();
//
//		// earn <= 0 时停止（包含等于0的情况）
//		if (g.earn() <= 0) 
//			break;
//
//		ans += g.earn();
//		heap.pop();
//		g.people++;
//		heap.push(g);
//	}
//	return ans;
//}
//
//// 暴力递归辅助函数（dfs）- 修复后
//// 参数说明：
//// n: 总人数
//// idx: 当前处理到第idx个人（0~n-1）
//// games: 项目列表 {Ki, Bi}
//// m: 项目数（新增，避免重复计算）
//// counts: 每个项目被选的人数（长度=m）
//// total: 记录最大总花费
//void dfs(int n, int idx, const vector<vector<int>>& games, int m, vector<int>& counts, ll& total) {
//	// 递归终止：所有人分配完成
//	if (idx == n) {
//		ll res = 0;
//		// 遍历项目数m（不是人数n）
//		for (int i = 0; i < m; ++i) {
//			int ki = games[i][0];
//			int bi = games[i][1];
//			int x = counts[i];
//			// 计算逻辑 Bi - Ki * x，且用long long避免溢出
//			ll single = bi - 1LL * ki * x;
//			res += max(0LL, 1LL * x * single);
//		}
//		total = max(res, total);
//		return;
//	}
//
//	// 选项1：当前人不选任何项目
//	dfs(n, idx + 1, games, m, counts, total);
//
//	// 选项2：当前人选某个项目
//	for (int i = 0; i < m; ++i) {
//		counts[i]++;
//		dfs(n, idx + 1, games, m, counts, total);
//		counts[i]--;  // 回溯
//	}
//}
//
//// 暴力解法（way2）
//ll way2(int n, const vector<vector<int>>& games) {
//	ll ans = 0;
//	int m = games.size();  // 项目数
//	vector<int> counts(m, 0);
//	// 调用dfs，传入项目数m
//	dfs(n, 0, games, m, counts, ans);
//	return ans;
//}
//
//// （随机生成项目数m）
//void test() {
//	srand(time(0));
//
//	int MAX_N = 8;    // 最大人数
//	int MAX_M = 5;    // 最大项目数
//	int MAX_V = 20;   // Ki/Bi的最大值
//	int testTimes = 1000;
//
//	cout << "测试开始..." << endl;
//
//	for (int i = 0; i < testTimes; ++i) {
//		// 随机生成人数n（1~MAX_N）
//		int n = rand() % MAX_N + 1;
//		// 随机生成项目数m（1~MAX_M）
//		int m = rand() % MAX_M + 1;
//		// 随机生成m个项目的{Ki, Bi}
//		vector<vector<int>> games(m, vector<int>(2, 0));
//		for (int j = 0; j < m; ++j) {
//			games[j][0] = rand() % MAX_V + 1;  // Ki
//			games[j][1] = rand() % MAX_V + 1;  // Bi
//		}
//
//		// 执行两种解法
//		ll p1 = way1(n, games);
//		ll p2 = way2(n, games);
//
//		// 验证结果
//		if (p1 != p2) {
//			cout << " 出错了！" << endl;
//			cout << "人数n: " << n << " 项目数m: " << m << endl;
//			cout << "项目列表：";
//			for (auto& g : games) cout << "{" << g[0] << "," << g[1] << "} ";
//			cout << endl;
//			cout << "贪心结果p1: " << p1 << " 暴力结果p2: " << p2 << endl;
//			break;
//		}
//
//		// 每100组输出进度
//		if ((i + 1) % 100 == 0) {
//			cout << " 第" << (i + 1) << "组测试完成" << endl;
//		}
//	}
//
//	cout << "测试结束！" << endl;
//}
//
//int main() {
//	test();
//	return 0;
//}