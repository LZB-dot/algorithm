//
////n堆石子全为1时，n奇数后手赢，n偶数先手赢
//
////不全为1时，反尼姆博弈
////此时异或和==0，先手必败
////异或和!=0，先手必胜
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		int n;
//		cin >> n;
//		int sum = 0;
//		int cnts = 0;
//		int a;
//		for (int i = 0; i < n; ++i) {
//			cin >> a;
//			if (a == 1)
//				cnts++;
//			sum ^= a;
//		}
//		string s;
//		if (cnts == n)
//			s = (n % 2 != 0) ? "Brother" : "John";
//		else
//			s = (sum == 0) ? "Brother" : "John";
//		cout << s << endl;
//	}	
//
//	return 0;
//}