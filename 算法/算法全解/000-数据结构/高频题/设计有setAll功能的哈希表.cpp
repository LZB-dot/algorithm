//#include<iostream>
//#include<unordered_map>
//using namespace std;
//
//unordered_map<int, pair<int, int>> mp;
//int setAllValue = 0;
//int setAllTime = -1;    // 关键！初始设为-1，确保比第一个cnt（0）小
//int cnt = 0;
//
//// 插入或更新键值对
//void put(int k, int v) {
//    if (mp.count(k)) {  // 如果键已存在，更新值和时间戳
//        mp[k].first = v;
//        mp[k].second = cnt++;
//    }
//    else {  // 如果键不存在，插入新的键值对和时间戳
//        mp[k] = { v, cnt++ };
//    }
//}
//
//// 全局设置所有键的值
//void setAll(int v) {
//    setAllValue = v;
//    setAllTime = cnt++;  // 更新全局时间戳
//}
//
//// 获取键对应的值
//int get(int k) {
//    if (!mp.count(k)) {  // 键不存在
//        return -1;
//    }
//    // 比较键的修改时间和全局设置时间，返回较新的值
//    if (mp[k].second > setAllTime)
//        return mp[k].first;
//    else
//        return setAllValue;
//}
//
//// 检查键是否存在
//bool containsKey(int k) {
//    return mp.count(k) > 0;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        if (n == 1) {  // put操作
//            int k, v;
//            cin >> k >> v;
//            put(k, v);
//        }
//        else if (n == 2) {  // get操作
//            int k;
//            cin >> k;
//            cout << get(k) << endl;
//        }
//        else {  // setAll操作
//            int v;
//            cin >> v;
//            setAll(v);
//        }
//    }
//    return 0;
//}
