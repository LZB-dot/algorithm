//
////阅读发现：当剩余6颗时，先手只能取1-5颗，此时后手必胜
////所以如果要让先手October赢，那么先手就必须让后手面临6的倍数颗石子
////此时无论后手取什么，先手都可以让后手再次面临这种状态
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//int main() {
//	int T;
//	cin >> T;
//
//	while (T--) {
//		int n;
//		cin >> n;
//		string s = (n % 6 == 0) ? "Roy wins!" : "October wins!";
//		cout << s << endl;
//	}
//
//	return 0;
//}