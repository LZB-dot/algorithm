////
////题目2
////选择k个数字使得两集合累加和相差不超过1
////给定一个正数n，表示1~n这些数字都可以选择
////给定一个正数k，表示要从1~n中选择k个数字组成集合A，剩下数字组成集合B
////希望做到集合A和集合B的累加和相差不超过1
////如果能做到，返回集合A选择了哪些数字，任何一种方案都可以
////Opacity
////如果不能做到，返回长度为0的数组
////100 % 0
////2 <= n <= 10 ^ 6
////1 <= k <= n
////来自真实大厂笔试，没有测试链接，用对数器验证
////评估一下数据规模，01背包的解法可行吗？
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define ll long long
//
//int main() {
//    int n, k;
//    cin >> n >> k;
//
//    //计算k个数的最小和、最大和
//    ll mi = (ll)k * (k + 1) / 2;  // 1+2+...+k
//    int range = n - k;
//    ll mx = mi + (ll)range * k;  //k个数能达到的最大和
//    //计算1~n的总和，以及目标sum
//    ll total = (ll)n * (n + 1) / 2;
//    ll target = total / 2;
//
//    vector<int> ans;
//
//    //先尝试target，不行且总和为奇数时尝试target+1
//    auto generate = [&](ll sum) -> bool {
//        if (sum < mi || sum > mx) {
//            return false;
//        }
//        ll need = sum - mi;
//        int right = need / range;  // 要放到最右边的数的个数
//        ll rem = need % range;          // 余数
//
//        ans.clear();
//        // 左边不需要调整的数：1 ~ (k - right_size - (rem>0 ? 1 : 0))
//        int left = k - right - (rem > 0 ? 1 : 0);
//        for (int i = 1; i <= left; ++i) {
//            ans.push_back(i);
//        }
//        // 中间数（有余数时）
//        if (rem > 0) {
//            ans.push_back(left + 1 + rem);
//        }
//        // 右边最大的数：n, n-1, ..., n - right_size + 1
//        for (int i = 0; i < right; ++i) {
//            ans.push_back(n - i);
//        }
//        return true;
//        };
//
//    // 尝试构造目标和
//    bool ok = generate(target);
//    // 如果失败且总和是奇数，尝试target+1
//    if (!ok && (total % 2 == 1)) {
//        ok = generate(target + 1);
//    }
//
//    if (!ok) {
//        // 无法构造，输出空
//        cout << -1 << endl;
//    }
//    else {
//        for (int num : ans) {
//            cout << num << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
