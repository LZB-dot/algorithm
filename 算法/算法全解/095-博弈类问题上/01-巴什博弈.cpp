////巴什博弈是最基础的博弈论问题，
////规则是：
////有 n 颗石子，两个人轮流拿，每次可以拿 1~m 颗石子；拿到最后一颗石子的人获胜。
////请根据 n 和 m，判断 “先手” 还是 “后手” 会赢。
//
////必胜态：剩m+1的倍数个石子，此时后手必赢
////必输态：剩m+1的倍数个石子，此时先手必输
////因为此时先手无论拿什么，后手都可以让先手继续面临m+1的倍数个石子状态
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 1001;
////1先手赢 0后手赢 -1未计算
//int dp[MAXN][MAXN];//当前有i颗石子，最多拿m颗谁赢
//
//int dfs(int n, int m) {
//	if (n == 0)
//		return 0;
//
//	if (dp[n][m] != -1)
//		return dp[n][m];
//
//	for (int i = 1; i <= m; ++i) {
//		if (dfs(n - i, m) == 0)
//			return dp[n][m] = 1;
//	}
//
//	return dp[n][m] = 0;
//}
//
//int math(int n, int m) {
//	return (n % (m + 1) == 0) ? 0 : 1;
//}
//
//void test() {
//	srand(time(0));
//	for (int i = 0; i < 1000; ++i) {
//		int n = rand() % 100 + 1;
//		int m = rand() % 100 + 1;
//		memset(dp, -1, sizeof(dp));
//		int p1 = dfs(n, m);
//		int p2 = math(n, m);
//		if (p1 != p2)
//			cout << "出错了" << endl;
//		
//		if (i % 100 == 0)
//			cout << "第" << i << "组测试完成" << endl;
//	}
//}
//
//int main() {
//	test();
//	return 0;
//}
//
