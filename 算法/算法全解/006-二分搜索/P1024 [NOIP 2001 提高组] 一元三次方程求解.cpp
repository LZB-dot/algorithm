//#include<iostream>
//#include<vector>
//#include<cmath>
//#include<algorithm>
//#include<cstdio>
//using namespace std;
//
//const double eps = 1e-4;
//
//double a, b, c, d;
//
//// 计算三次函数值
//double cal(double x) {
//    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
//}
//
//// 二分查找求解区间[x, y]内的根
//double bs(double x, double y) {
//    double mid = 0.0;
//    // 当区间长度大于精度要求时继续二分
//    while (y - x > eps) {
//        mid = x + (y - x) / 2;  // 避免x+y溢出
//        // 符号相同则根在右半区间，否则在左半区间
//        if (cal(x) * cal(mid) > 0)
//            x = mid;
//        else
//            y = mid;
//    }
//    return (x + y) / 2;  // 返回区间中点作为根，保证精度
//}
//
//int main() {
//    cin >> a >> b >> c >> d;
//    vector<double> ans;
//
//    for (int i = -100; i < 100; ++i) {
//        double x1 = i;       // 区间左边界
//        double x2 = i + 1;   // 区间右边界
//        double f1 = cal(x1); // 左边界函数值
//        double f2 = cal(x2); // 右边界函数值
//
//        // 左边界是根，且未重复添加
//        if (fabs(f1) < eps) {
//            // 检查是否已经添加过该根（避免重复）
//            bool exist = false;
//            for (double root : ans) {
//                if (fabs(root - x1) < eps) {
//                    exist = true;
//                    break;
//                }
//            }
//            if (!exist) {
//                ans.push_back(x1);
//            }
//        }
//        // 区间两端函数值符号相反，说明有根
//        else if (f1 * f2 < 0) {
//            ans.push_back(bs(x1, x2));
//        }
//
//        // 找到3个根就停止遍历
//        if (ans.size() == 3) {
//            break;
//        }
//    }
//
//    // 排序根
//    sort(ans.begin(), ans.end());
//    printf("%.2lf %.2lf %.2lf\n", ans[0], ans[1], ans[2]);
//
//    return 0;
//}