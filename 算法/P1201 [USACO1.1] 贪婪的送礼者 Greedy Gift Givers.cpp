//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <string>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//
//    vector<string> people;
//    unordered_map<string, int> mp;
//
//    for (int i = 0; i < n; ++i) {
//        string name;
//        cin >> name;
//        people.push_back(name);
//        mp[name] = 0;
//    }
//
//    for (int i = 0; i < n; ++i) {
//        string giver; 
//        cin >> giver;
//
//        int money, cnt; 
//        cin >> money >> cnt;
//
//        if (cnt == 0)
//            continue;
//
//        int cur = money / cnt;
//        int sum = cur* cnt;
//        mp[giver] -= sum;
//
//        // 处理每个收礼人
//        for (int j = 0; j < cnt; ++j) {
//            string receiver;
//            cin >> receiver;
//            mp[receiver] += cur;
//        }
//    }
//
//    for (const string& name : people) {
//        cout << name << " " << mp[name] << endl;
//    }
//
//    return 0;
//}