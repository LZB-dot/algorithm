//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//
//inline int read() {
//	int num = 0;
//	char c;
//
//	while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
//
//	bool flag = 0;
//	if (c == '-')
//		flag = 1;
//	else
//		num = c - '0';
//
//	while (isdigit(c = getchar()))
//		num = num * 10 + c - '0';
//
//	return flag ? -num : num;
//}
//
//int main() {
//	bool flag = 1;
//	int cnt = 1;
//	while (flag) {
//		vector<int>nums(7);
//
//		ll sum = 0;
//		flag = 0;
//		for (int i = 1; i <= 6; ++i) {
//			nums[i] = read();
//			sum += nums[i] * i;
//			if (nums[i] != 0)
//				flag = 1;
//		}
//
//		if (!(sum & 1)) {
//			cout << "Collection #" << cnt << ":\n";
//			cout << "Can't be divided.\n\n";
//			continue;
//		}
//
//
//
//
//	}
//}