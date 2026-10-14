//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int l, n, m;
//vector<int>nums;
//
////快读函数
//inline int read() {
//	int num = 0;
//	char c;
//	bool flag = false;
//
//	//跳过空格，换行，回车符
//	while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
//
//	//标记是否为负数
//	if (c == '-') 
//		flag = true;
//	else
//		num = c - '0';
//
//	while (isdigit(c = getchar()))
//		num = num * 10 + c - '0';
//
//	return (flag ? -1 : 1) * num;
//}
//
//
//bool check(int mid) {
//	int remove = 0;  //需要移走的岩石数
//	int last = 0;    //上一个保留的岩石下标
//
//	for (int i = 1; i <= n; ++i) {
//		//当前岩石到上一个保留岩石的距离 
//		if (nums[i] - nums[last] < mid) {
//			remove++;
//		}
//		else {
//			//保留当前岩石，更新last
//			last = i;
//		}
//	}
//
//	//终点到最后一个保留岩石的距离
//	if (l - nums[last] < mid) {
//		remove++;
//	}
//
//	return remove <= m;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	l = read();
//	n = read();
//	m = read();
//
//	nums.resize(n + 2);
//	nums[0] = 0;
//	for (int i = 1; i <= n; ++i) {
//		nums[i] = read();
//	}
//
//	int ans = 0;
//	int left = 1, right = l;
//	while (left <= right) {
//
//		int mid = left + ((right - left) >> 1);
//		if (check(mid)) {
//			ans = mid;
//			left = mid + 1;
//		}
//		else {
//			right = mid - 1;
//		}
//	}
//
//	cout << ans << "\n";
//	return 0;
//}