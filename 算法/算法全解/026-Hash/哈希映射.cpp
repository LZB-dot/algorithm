//
////数据以 (键, 值) 对的形式存储，每个键（key）唯一对应一个值（value）
////重复插入相同键时，新值会覆盖旧值
//
////插入、删除、查找（通过键获取值） 的时间复杂度均接近 O(1)
//
//#include<iostream>
//#include<unordered_map>
//#include<string>
//using namespace std;
//
//#pragma GCC optimize(3)
//#define endl "\n"
//
//unordered_map<string,int>map1;//默认构造
//
//unordered_map<string, int>map2 = {
//	{"apple",5},
//	{"banana",3},
//	{"orange",7} };//初始化构造
//
//unordered_map<string, int>map3(map2.begin(), map2.end());//范围构造
//
//unordered_map<string,int>map4(map2);//复制构造
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cout.tie(nullptr);
//
//	//用[] 运算符插入（最简洁）
//	map1["apple"] = 5;  // 键不存在则插入，存在则修改值
//	map1["banana"] = 3;
//
//	//批量插入
//	map1.insert({ {"grape", 2}, {"mango", 4} });
//
//	//访问与修改
//	//键不存在时会插入默认值
//	cout << "app 的数量: " << map1["app"] << endl;
//	map1["app"] = 10;  // 修改已有键的值
//
//	auto it = map1.find("orange");
//	if (it != map1.end()) 
//	{
//		// first 是键，second 是值
//		cout << "找到: " << it->first << "=" << it->second << endl; 
//		it->second = 9;  // 修改值（键不可修改）
//	}
//
//	//按键删除：返回删除的元素个数（0 或 1）
//	size_t deleted = map2.erase("banana");
//	if (deleted > 0)
//		std::cout << "成功删除 banana" <<endl;
//
//	//按迭代器删除：无返回值
//	it = map2.find("orange");
//	if (it != map2.end())
//		map2.erase(it);  // 删除迭代器指向的键值对
//
//	//清空所有元素
//	map2.clear();
//
//	cout << "元素个数: " << map1.size() <<endl;
//
//	// 检查是否为空
//	if (map1.empty())
//		cout << "map 为空" << endl;
//
//	//范围 for 循环（推荐）
//	for (const auto& pair : map1)
//		cout << pair.first << "=" << pair.second << " ";  // first 是键，second 是值
//	cout << endl;
//
//	//迭代器遍历
//	for (auto it = map1.begin(); it != map1.end(); ++it)
//		cout << it->first << "=" << it->second << " ";
//
//	return 0;
//}
