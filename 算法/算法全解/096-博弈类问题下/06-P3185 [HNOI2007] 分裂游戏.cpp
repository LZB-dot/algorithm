//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <cstring> 
//using namespace std;
//
//const int MAXN = 21;
//const int MAXV = 101;
//int nums[MAXN];
//int sg[MAXN];
//bool appear[MAXV];
//int t, n;
//
//void build() {
//    sg[0] = 0;
//    for (int i = 1; i < MAXN; ++i) {
//        memset(appear, 0, sizeof(appear));
//        // 枚举所有可能的转移：从i移动到j和k (j,k < i)
//        for (int j = 0; j < i; ++j) {
//            for (int k = j; k < i; ++k) {
//                appear[sg[j] ^ sg[k]] = true;
//            }
//        }
//        // mex操作
//        for (int s = 0; s < MAXV; ++s) {
//            if (!appear[s]) {
//                sg[i] = s;
//                break;
//            }
//        }
//    }
//}
//
//string compute() {
//    int eor = 0;
//    // 计算全局异或和：第i个瓶子的贡献是 sg[i] 如果该位置有奇数个豆子
//    for (int i = 0; i < n; ++i) {
//        if (nums[i] % 2 == 1) {
//            eor ^= sg[n - 1 - i];  // 瓶子标号反向，最后一个是sg[0]
//        }
//    }
//
//    // 先手必败
//    if (eor == 0) {
//        return "-1 -1 -1\n0";
//    }
//
//    int cnt = 0;
//    int a = -1, b = -1, c = -1;
//
//    // 枚举所有可能的操作(i,j,k)
//    for (int i = 0; i < n; ++i) {
//        if (nums[i] == 0) continue;
//        for (int j = i + 1; j < n; ++j) {
//            for (int k = j; k < n; ++k) {
//                // 执行操作后的异或值
//                // 瓶子标号反向，所以使用 n-1-i, n-1-j, n-1-k
//                int new_eor = eor ^ sg[n - 1 - i] ^ sg[n - 1 - j] ^ sg[n - 1 - k];
//                if (new_eor == 0) {
//                    cnt++;
//                    if (a == -1) {  // 第一次找到的就是字典序最小的
//                        a = i;
//                        b = j;
//                        c = k;
//                    }
//                }
//            }
//        }
//    }
//
//    if (cnt == 0) {
//        return "-1 -1 -1\n0";
//    }
//
//    return to_string(a) + " " + to_string(b) + " " + to_string(c) + "\n" + to_string(cnt);
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    build();
//    cin >> t;
//    while (t--) {
//        cin >> n;
//        for (int i = 0; i < n; ++i) {
//            cin >> nums[i];
//        }
//        cout << compute() << endl;
//    }
//    return 0;
//}