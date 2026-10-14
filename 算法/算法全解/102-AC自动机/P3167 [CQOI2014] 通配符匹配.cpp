//#include<iostream>
//#include<vector>
//#include<string> 
//using namespace std;
//
//vector<string> parts;
//int k = 0;
//bool start = false, ed = false;
//
//vector<int> getNxt(const string& s) {
//    int m = s.size();
//    if (m == 0) return {};
//    if (m == 1)
//        return { -1 };
//
//    vector<int> nxt(m);
//    nxt[0] = -1;
//    nxt[1] = 0;
//    int i = 2, cn = 0;
//    while (i < m) {
//        if (s[i - 1] == s[cn] || s[i - 1] == '?' || s[cn] == '?')
//            nxt[i++] = ++cn;
//        else if (cn > 0)
//            cn = nxt[cn];
//        else
//            nxt[i++] = 0;
//    }
//    return nxt;
//}
//
//int kmp(const string& a, const string& b, int left) {
//    int n = a.size();
//    int m = b.size();
//
//    if (m == 0)
//        return left;
//    vector<int> nxt = getNxt(b);
//    int x = left, y = 0;
//
//    if (left < 0 || left + m > n)
//        return -1;
//
//    while (x < n && y < m) {
//        if (a[x] == b[y] || b[y] == '?' || a[x] == '?') {
//            ++x;
//            ++y;
//        }
//        else if (y > 0)
//            y = nxt[y];
//        else
//            ++x;
//    }
//    return (y == m) ? x : -1;
//}
//
//void solve() {
//    string t;
//    cin >> t;
//    int left = 0;
//
//    if (parts.empty()) {
//        cout << "YES\n";
//        return;
//    }
//
//    for (int i = 0; i < parts.size(); ++i) {
//        left = kmp(t, parts[i], left);
//
//        if (left == -1) {
//            cout << "NO\n";
//            return;
//        }
//
//        if (i == 0 && !start) {
//            if (left != parts[i].size()) {
//                cout << "NO\n";
//                return;
//            }
//        }
//
//        if (i == parts.size() - 1 && !ed) {
//            if (left != t.size()) {
//                cout << "NO\n";
//                return;
//            }
//        }
//    }
//    cout << "YES\n";
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    string s;
//    cin >> s;
//
//    if (!s.empty()) {
//        start = (s[0] == '*');
//        ed = (s.back() == '*');
//    }
//
//    parts.push_back("");
//    for (int i = 0; i < s.size(); ++i) {
//        if (s[i] != '*')
//            parts[k] += s[i];
//        else {
//            if (!parts[k].empty()) {
//                parts.push_back("");
//                ++k;
//            }
//        }
//    }
//
//    if (!parts.empty() && parts.back().empty()) {
//        parts.pop_back();
//    }
//
//    int n;
//    cin >> n;
//    while (n--)
//        solve();
//
//    return 0;
//}

//KMP算法失败---存在?，nxt数组跳转有问题