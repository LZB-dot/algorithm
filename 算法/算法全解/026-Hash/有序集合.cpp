////哈希集合中不允许存在重复元素，插入重复元素时会被自动忽略
//
////高效的查找、插入和删除操作,时间复杂度接近 O(1)。
//
////自动升序排列
//
//#include<iostream>
//#include<set>
//#include<vector>
//using namespace std;
//
//#pragma GCC optimize(3)
//#define endl "\n"
//
//set<int>set1;//默认构造
//
//set<int>set2 = { 1,2,3,4 };//初始化构造
//
//vector<int>v = { 4,5,6,7 };
//set<int>set3(v.begin(), v.end());//范围构造
//
//set<int>set4(set2);//复制构造
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cout.tie(nullptr);
//
//	//元素插入--插入重复元素会被忽略
//	set1.insert(10);//单个插入
//	set1.insert(20);
//	set1.insert({ 30,40,50 });//批量插入
//	int arr[] = { 50,60,70 };
//	set1.insert(arr, arr + 2);//范围插入
//
//	//元素查找
//	auto it = set2.find(2);
//	if (it != set2.end())
//		cout << "找到" << *it << endl;
//	else
//		cout << "未找到" << endl;
//
//	//元素删除
//	//通过值
//	size_t count = set2.erase(2);//成功返回1，否则0
//	//通过迭代器
//	it = set2.find(3);
//	if (it != set2.end())
//		set2.erase(it);
//
//	// 获取元素数量
//	cout << "元素个数: " << set2.size() << endl;
//
//	// 检查是否为空
//	if (set2.empty())
//		cout << "集合为空" << endl;
//
//	// 范围 for 循环
//	for (int num : set2)
//		cout << num << " ";
//	cout << endl;
//
//	// 迭代器遍历
//	for (it = set2.begin(); it != set2.end(); ++it) 
//		cout << *it << " ";
//	cout << endl;
//
//	return 0;
//}
