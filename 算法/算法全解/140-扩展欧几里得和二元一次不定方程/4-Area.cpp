//
//
////http://poj.org/problem?id=1265
//
//// 机器人的移动区域
//// 二维网格中只有x和y的值都为整数的坐标，才叫格点
//// 某个机器人从格点(0,0)出发，每次机器人都走直线到达(x + dx, y + dy)的格点
//// 一共移动n次，每次的(dx, dy)都给定，途中路线不会交叉，输入保证机器人最终回到(0,0)
//// 机器人走的路线所围成的区域一定是多边形，输入保证机器人一定沿着逆时针方向行动
//// 返回多边形的内部一共几个格点，多边形的边上一共几个格点，多边形的面积
//// 3 <= n <= 100
//// -100 <= dx、dy <= 100
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//typedef long long ll;
//
//ll gcd(ll a, ll b) {
//	if (b != 0)
//		return gcd(b, a % b);
//	return a;
//}
//
//void solve(int t) {
//	int n;
//	cin >> n;
//
//	ll edge = 0;
//	ll area = 0;
//
//	int x = 0, y = 0;
//	for (int i = 1; i <= n; ++i) {
//		ll dx, dy;
//		cin >> dx >> dy;
//
//		int d = gcd(llabs(dx),llabs( dy));
//		edge += d;
//
//		ll px = x + dx;
//		ll py = y + dy;
//
//		area += x * py - px * y;
//
//		x = px;
//		y = py;
//	}
//
//	double S = area / 2.0;
//	int ans = (area - edge) / 2 + 1;
//
//	printf("Scenario #%d:\n", t);
//	printf("%d %lld %.1f\n\n", ans, edge, S);
//}
//
//int main() {
//	int T;
//	cin >> T;
//
//	for (int i = 1; i <= T; ++i)
//		solve(i);
// 
// return 0;
//}
