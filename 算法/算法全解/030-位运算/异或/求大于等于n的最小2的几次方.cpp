//#include<iostream>
//using namespace std;
//
//int work(int n) {
//	if (n <= 0)
//		return 1;
//	n--;//避免如果n是2的幂，找到的将会是下一个不是它本身
//	n |= n >> 1;
//	n |= n >> 2;
//	n |= n >> 4;
//	n |= n >> 8;
//	n |= n >> 16;
//	//n 的二进制表示中 "最高位 1" 后面的所有位都变成 1
//	return n + 1;
//}
//
//int main() {
//	int num;
//	cin >> num;
//	cout << work(num);
//}