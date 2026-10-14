////
////键（key）会按照升序（默认） 自动排序（基于 < 运算符或自定义比较器）。
////遍历元素会按照键的顺序输出
////
////重复插入相同键时，新值会覆盖旧值
////
////插入、删除、查找（通过键获取值） 的时间复杂度均接近 o(log n)
//
//
////
////数据以 (键, 值) 对的形式存储，每个键（key）唯一对应一个值（value）
////重复插入相同键时，新值会覆盖旧值
//
////插入、删除、查找（通过键获取值） 的时间复杂度均接近 O(1)
////
//
//#include<iostream>
//#include<map>
//#include<string>
//using namespace std;
//
//#pragma GCC optimize(3)
//#define endl "\n"
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cout.tie(nullptr);
//
//    // 各种构造方式示例
//    map<string, int> map1;  // 默认构造
//
//    // 初始化列表构造
//    map<string, int> map2 = {
//        {"apple", 5},
//        {"banana", 3},
//        {"orange", 7}
//    };
//
//    // 范围构造
//    map<string, int> map3(map2.begin(), map2.end());
//
//    // 复制构造
//    map<string, int> map4(map2);
//
//    // 用[]运算符插入元素
//    map1["apple"] = 5;
//    map1["banana"] = 3;
//
//    // 批量插入
//    map1.insert({ {"grape", 2}, {"mango", 4} });
//
//    // 访问与修改元素
//    // 注意：使用[]访问不存在的键会自动插入
//    cout << "app 的数量: " << map1["app"] << endl;  // 自动插入"app":0
//    map1["app"] = 10;  // 修改已有键的值
//
//    // 查找元素（map1中没有"orange"，所以代码块不会执行）
//    auto it = map1.find("orange");
//    if (it != map1.end())
//    {
//        cout << "找到: " << it->first << "=" << it->second << endl;
//        it->second = 9;  // 修改值（键不可修改）
//    }
//
//    // 按键删除元素
//    size_t deleted = map2.erase("banana");
//    if (deleted > 0)
//        cout << "成功删除 banana" << endl;
//
//    // 按迭代器删除元素
//    it = map2.find("orange");
//    if (it != map2.end())
//        map2.erase(it);
//
//    // 清空所有元素
//    map2.clear();
//
//    // 容器信息查询
//    cout << "元素个数: " << map1.size() << endl;
//    if (map1.empty())
//        cout << "map 为空" << endl;
//
//    // 范围for循环遍历
//    cout << "范围for循环遍历: ";
//    for (const auto& pair : map1)
//        cout << pair.first << "=" << pair.second << " ";
//    cout << endl;
//
//    // 迭代器遍历
//    cout << "迭代器遍历: ";
//    for (auto it = map1.begin(); it != map1.end(); ++it)
//        cout << it->first << "=" << it->second << " ";
//    cout << endl;
//
//    return 0;
//}
