//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<int>ans;
//int n, b, d, mx;
//
////检查当前数num是否与已选数的汉明距离都≥d
//bool check(int num) {
//    //已选数为空时，直接加入（第一个数一定符合）
//    if (ans.empty()) {
//        return true;
//    }
//    // 遍历所有已选数，验证汉明距离
//    for (int selected : ans) {
//        int val = num ^ selected; // 不同位为1，相同位为0
//        int diff = 0; // 统计不同位的数量（汉明距离）
//        // 遍历b位二进制，统计1的个数
//        for (int j = 0; j < b; ++j) {
//            if (val & (1 << j)) { // 该位是1，说明不同
//                diff++;
//            }
//        }
//        // 汉明距离不足d，直接返回false
//        if (diff < d) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main() {
//    cin >> n >> b >> d;
//    mx = (1 << b) - 1; // b位二进制数的最大值
//    int count = 0;     // 记录当前行已输出的数的个数
//
//    // 枚举所有b位二进制数，直到选够n个
//    for (int i = 0; i <= mx && ans.size() < n; ++i) {
//        if (check(i)) {
//            ans.push_back(i); 
//            cout << i << " ";
//            count++;
//            if (count == 10 && ans.size() != n) {
//                cout << endl;
//                count = 0; 
//            }
//        }
//    }
//    cout << endl;
//
//    return 0;
//}