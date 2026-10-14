//
//
////https://www.luogu.com.cn/problem/P5656
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//
//ll x, y, px, py, d;
//
//void exgcd(ll a, ll b) {
//	if (b == 0) {
//		d = a;
//		x = 1;
//		y = 0;
//	}
//	else {
//		exgcd(b, a % b);
//		px = x;
//		py = y;
//		x = py;
//		y = px - py * (a / b);
//	}
//}
//
////正整数解是指x和y均为正数
//void solve() {
//	ll a, b, c;
//	cin >> a >> b >> c;
//
//	exgcd(a, b);
//
//	//无整数解
//	if (c % d != 0) {
//		cout << "-1\n";
//		return;
//	}
//
//	x *= c / d;
//	y *= c / d;
//	ll addx = b / d;//x的增量
//	ll addy = a / d;//y的增量
//
//	//有整数解
//	if (x < 0) {
//		//将x增加到最小的正整数
//		ll cnt = (1 - x + addx - 1) / addx;
//		x += cnt * addx;
//		y -= cnt * addy;
//	}
//	else {
//		//将x减少到最小的正整数
//		ll cnt = (x - 1) / addx;
//		x -= cnt * addx;
//		y += cnt * addy;
//	}
//
//	//此时得到的特解是x为最小正整数的时候的解 此时y是最大的特解
//	
//	//无正整数解
//	if (y <= 0) {
//		//打印x和y的最小正整数
//		cout << x << " ";
//		ll cnt = (1 - y + addy - 1) / addy;
//		cout << (y + cnt * addy) << "\n";
//	}
//	//有正整数解
//	else {
//		//y减少到1一下 有多少次就是正整数解个数
//		ll cnt = (y - 1) / addy;
//		//加上当前的y
//		cout << cnt+1 << " ";
//		
//		//打印正整数解的情况下x和y的最小正整数和最大正整数
//		cout << x << " ";
//		cout << y - addy * cnt << " ";
//		cout << x + addx * cnt << " ";
//		cout << y << "\n";
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int T;
//	cin >> T;
//
//	while (T--)
//		solve();
//
//	return 0;
//}