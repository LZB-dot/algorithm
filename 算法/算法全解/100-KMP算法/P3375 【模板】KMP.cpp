//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
////nxt数组是不包括i位置的最长前缀后缀相等长度
//vector<int> getNxt(const string& s) {
//    int m = s.size();
//    vector<int> nxt(m + 1); 
//    nxt[0] = -1;
//    if (m == 0)
//        return nxt;
//    nxt[1] = 0;
//
//    //cn：当前匹配的前缀长度
//    int i = 2, cn = 0;
//    while (i <= m) { 
//        //匹配成功延长
//        if (s[i - 1] == s[cn]) {
//            nxt[i++] = ++cn;
//        }
//        //匹配失败回撤到更短的前缀
//        else if (cn > 0) {
//            cn = nxt[cn];
//        }
//        else {
//            nxt[i++] = 0;
//        }
//    }
//    return nxt;
//}
//
//
//void kmp(const string& s1, const string& s2, const vector<int>& nxt) {
//    int n = s1.size();
//    int m = s2.size();
//    if (n < m || m == 0)
//        return;
//
//    int x = 0, y = 0;
//    while (x < n) {
//        if (y == -1 || s1[x] == s2[y]) {
//            ++x; ++y;
//        }
//        else {
//            y = nxt[y];
//        }
//
//        if (y == m) {
//            cout << x - y + 1 << "\n";
//            y = nxt[y]; 
//        }
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    string s1, s2;
//    cin >> s1 >> s2;
//    int m = s2.size();
//
//    vector<int> nxt = getNxt(s2);
//    kmp(s1, s2, nxt);
//
//    for (int i = 1; i <= m; i++) {
//        cout << nxt[i] << " ";
//    }
//    cout << "\n";
//
//    return 0;
//}