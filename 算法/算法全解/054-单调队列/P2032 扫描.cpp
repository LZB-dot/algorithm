//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//inline int read() {
//	int num = 0;
//	char c;
//
//	while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
//
//	bool flag = 0;
//	if (c == '-')
//		flag = true;
//	else
//		num = c - '0';
//
//	while (isdigit(c = getchar())) {
//		num = num * 10 + c - '0';
//	}
//
//	return (flag ? -1 : 1) * num;
//}
//
//int main() {
//	int n, k;
//	n = read();
//	k = read();
//
//	vector<int>nums(n);
//
//	for (int i = 0; i < n; ++i)
//		nums[i] = read();
//
//	vector<int>ans;
//	deque<int>q;
//	for (int i = 0; i < n; ++i) {
//		while (!q.empty() && q.front() < i - k + 1)
//			q.pop_front();
//
//		while (!q.empty() && nums[q.back()] <= nums[i])
//			q.pop_back();
//
//		q.push_back(i);
//
//		if (i >= k - 1)
//			ans.push_back(nums[q.front()]);
//	}
//
//	for (int i : ans)
//		cout << i << "\n";
//
//	return 0;
//}