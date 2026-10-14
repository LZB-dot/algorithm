//#include <iostream>
//#include <vector>
//#include <deque>
//#include <cstdio>
//
//using namespace std;
//
//int n, s, t;
//vector<double>sum; 
//vector<int>nums;     
//
//bool check(double mid) {
//
//    sum[0] = 0;
//    for (int i = 1; i <= n; ++i) {
//        sum[i] = sum[i - 1] + (double)nums[i] - mid;
//    }
//
//    deque<int> q;
//
//    // 遍历i从s到n
//    for (int i = s; i <= n; ++i) {
//        //把i-s加入队列
//        int pos = i - s;
//
//        while (!q.empty() && sum[q.back()] > sum[pos])
//            q.pop_back();
//
//        q.push_back(pos);
//
//        while (!q.empty() && q.front() < i - t) {
//            q.pop_front();
//        }
//
//        if (!q.empty() && sum[i] - sum[q.front()] >= 0) {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//int main() {
//
//    cin >> n >> s >> t;
//    sum.resize(n + 1);
//    nums.resize(n + 1);
//    for (int i = 1; i <= n; ++i) 
//        cin >> nums[i];
//    
//
//
//    double l = -1e4, r = 1e4, mid, ans = l;
//    while (r - l > 1e-5) {
//        mid = (l + r) / 2;
//        if (check(mid)) {
//            ans = mid;
//            l = mid;
//        }
//        else {
//            r = mid;
//        }
//    }
//
//    printf("%.3lf\n", ans); 
//    return 0;
//}