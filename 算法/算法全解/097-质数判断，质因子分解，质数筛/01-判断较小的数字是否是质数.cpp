////判断较小的数字是否是质数
//
//
//#include<iostream>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//
//	
//	if (n <= 1) {
//		cout << "No" << endl;
//		return 0;
//	}
//
//	for (int i = 2; i * i <= n; ++i) {
//		if (n % i == 0) {
//			cout << "No" << endl;
//			break;
//		}
//	}
//	cout << "Yes" << endl;
//	return 0;
//}