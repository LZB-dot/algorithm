//#include<iostream>
//#include<string>
//using namespace std;
//
//typedef long long ll;
//
////从位置 i 开始的子串与整个字符串的前缀的最长匹配长度
////字符串：abbabbsdabb
////     0：abbabbsdabb	n
////	   1：bbabbsdabb	0
////	   2：babbsdabb		0
////	   3：abbsdabb		3
////	   4：bbsdabb		0
//void getZ(const char* s, int n, int* z) {
//    z[0] = n;
//    int c = 1, r = 1;
//    for (int i = 1; i < n; ++i) {
//        int len = (r > i) ? min(r - i, z[i - c]) : 0;
//        while (i + len < n && s[i + len] == s[len])
//            len++;
//        if (i + len > r) {
//            r = i + len;
//            c = i;
//        }
//        z[i] = len;
//    }
//}
//
////字符串 a 的每个位置与字符串 b 的前缀匹配的最长长度
////a = "abababc"（n = 7）
////b = "abab"（m = 4）
////	0：abababc
////	   abab			4
////	1：bababc
////	   abab			0
////	2：ababc
////	   abab			4
////	3：babc
////	   abab			0
////	4：abc
////	   abab			2
//void getE(const char* a, int n, const char* b, int m, int* z, int* e) {
//    int c = 0, r = 0;
//    for (int i = 0; i < n; ++i) {
//        int len = (r > i) ? min(r - i, z[i - c] ) : 0;
//        while (i + len < n && len < m && a[i + len] == b[len])
//            ++len;
//        if (i + len > r) {
//            r = i + len;
//            c = i;
//        }
//        e[i] = len;
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    string a, b;
//    cin >> a >> b;
//    int n = a.size(), m = b.size();
//
//    int* z = new int[m]();
//    int* p = new int[n]();
//
//    getZ(b.c_str(), m, z);
//    getE(a.c_str(), n, b.c_str(), m, z, p);
//
//    ll ans1 = 0, ans2 = 0;
//    for (int i = 0; i < m; ++i)
//        ans1 ^= (ll)(i + 1) * (z[i] + 1);
//    for (int i = 0; i < n; ++i)
//        ans2 ^= (ll)(i + 1) * (p[i] + 1);
//
//    cout << ans1 << '\n' << ans2 << '\n';
//
//    delete[] z;
//    delete[] p;
//    return 0;
//}