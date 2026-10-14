//////牛A，B轮流吃草，谁吃完了最后一根草就算赢，A先吃，每次只能吃4的n次方
////
////#include<iostream>
////using namespace std;
////
////char work(int n, char c) {
////    //c是当前吃草玩家
////    //opponent是对手
////    char opponent = (c == 'A' ? 'B' : 'A');
////
////    if (n == 0) {
////        return opponent;
////    }
////
////    int pick = 1;
////    while (pick <= n) {
////        if (work(n - pick, opponent) == c) {
////            return c;
////        }
////
////        pick <<= 2;
////    }
////
////    return opponent;
////}
////
////int main() {
////    for (int n = 1; n <= 100; ++n) {
////        cout  << n <<": " << work(n, 'A') << endl;
////    }
////    return 0;
////}
////
//////1: A	6 : A	11 : A	16 : A
//////2 : B	7 : B	12 : B	17 : B
//////3 : A	8 : A	13 : A	18 : A
//////4 : A	9 : A	14 : A	19 : A
//////5 : B	10 : B	15 : B	20 : B
//
//#include<iostream>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	if (n % 2 == 0 || n % 5 == 0) {
//		cout << "B";
//	}
//	else{
//		cout << "A";
//	}
//	return 0;
//}