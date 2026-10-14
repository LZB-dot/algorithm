//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//
//ll manacher(const string& s, int n) {
//    string ss;
//    for (char c : s) {
//        ss += '#';
//        ss += c;
//    }
//    ss += '#';
//
//    int m = ss.size();
//    char to[500];
//    to['1'] = '0';
//    to['0'] = '1';
//    to['#'] = '#';
//
//    vector<int> p(m, 0);
//    int c = 0, r = 0;
//    ll ans = 0;
//
//    for (int i = 0; i < m; i += 2) {
//        p[i] = (i < r) ? min(r - i, p[(c << 1) - i]) : 1;
//
//        while (i + p[i] < m && i - p[i] >= 0) {
//            if (ss[i + p[i]] == to[ss[i - p[i]]]) {
//                p[i]++;
//            }
//            else {
//                break;
//            }
//        }
//
//        if (p[i] + i > r) {
//            r = p[i] + i;
//            c = i;
//        }
//
//        ans += p[i] >> 1;
//    }
//
//    return ans;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    string s;
//    cin >> n >> s;
//    cout << manacher(s, n) << "\n";
//
//    return 0;
//}