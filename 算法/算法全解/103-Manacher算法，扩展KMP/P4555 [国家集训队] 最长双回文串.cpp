//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 2e5 + 10;  
//
////以处理后字符串ss的i位置结尾的最长回文长度（对应原串）
////以处理后字符串ss的i位置开头的最长回文长度（对应原串）
//int left_[MAXN], right_[MAXN];
//vector<int> p;
//
//void manacher(const string& s, int& cnt) {
//    fill(left_, left_ + MAXN, 0);
//    fill(right_, right_ + MAXN, 0);
//
//    string ss = "#";
//    for (char c : s) {
//        ss += c;
//        ss += '#';
//    }
//    cnt = ss.size();  
//    int n = cnt;
//    p.assign(n, 0); 
//    int c = 0, r = 0; 
//
//    for (int i = 0; i < n; ++i) {
//        int len = (r > i) ? min(p[2 * c - i], r - i) : 1;
//        while (i + len < n && i - len >= 0 && ss[i + len] == ss[i - len])
//            ++len;
//        if (i + len > r) {
//            r = i + len;
//            c = i;
//        }
//        p[i] = len;
//
//        int cur = len - 1;  
//        if (cur == 0) 
//            continue;
//
//        int L = i - len + 1;  //回文左边界
//        int R = i + len - 1;  //回文右边界
//
//        right_[L] = max(right_[L], cur);
//        left_[R] = max(left_[R], cur);
//    }
//
//    //从左到右，步长2
//    for (int i = 2; i < n; i += 2) {
//        if (i - 2 >= 0) {
//            right_[i] = max(right_[i], right_[i - 2] - 2);
//        }
//    }
//    //从右到左，步长2
//    for (int i = n - 2; i >= 0; i -= 2) {
//        if (i + 2 < n) {
//            left_[i] = max(left_[i], left_[i + 2] - 2);
//        }
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    string s;
//    cin >> s;
//    int cnt; 
//    manacher(s, cnt);
//
//    //遍历#位置，左右延申
//    int ans = 0;
//    for (int i = 2; i < cnt; i += 2) {
//        if (left_[i] != 0 && right_[i] != 0)
//            ans = max(ans, left_[i] + right_[i]);
//    }
//
//    cout << ans << "\n";
//    return 0;
//}
