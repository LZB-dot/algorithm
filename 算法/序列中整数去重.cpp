//#include<iostream>
//#include<vector>
//#include <unordered_set>//查找和插入较快，均为O(1)
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>nums(n);
//	for (int i = 0; i < n; ++i)
//		cin >> nums[i];
//	unordered_set<int>see;
//	vector<int>res;
//	for (int num : nums)
//	{
//		if (see.find(num) == see.end())
//		{
//			res.push_back(num);
//			see.insert(num);
//		}
//	}
//	for (int num : res)
//		cout << num << " ";
//	cout << endl;
//	return 0;
//}