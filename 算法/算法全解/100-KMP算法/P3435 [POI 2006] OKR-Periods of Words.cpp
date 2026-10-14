//#include<iostream>
//#include<cstdio>
//#include<vector>
//#include<algorithm>
//#define ll long long
//using namespace std;
//
//
//vector<int> getNxt(const string& s, int n) {
//    if (n == 1)
//        return { -1 };
//
//    vector<int> nxt(n + 1);
//    nxt[0] = nxt[1] = 0;
//    int j = 0;
//    for (int i = 1; i < n; i++) {
//        while (j && s[i] != s[j]) {
//            j = nxt[j];
//        }
//        j += (s[i] == s[j]);
//        nxt[i + 1] = j;
//    }
//    return nxt;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    string s;
//    cin >> s;
//
//    ll cnt = 0;
//    vector<int> nxt = getNxt(s, n);
//
//    //最大周期长度=i-nxt[i]
//    for (int i = 1; i <= n; i++) {
//        int j = i;
//        while (nxt[j]) {
//            j = nxt[j];
//        }
//        if (nxt[i] != 0) {
//            nxt[i] = j; 
//        }
//        cnt += (i - j);  
//    }
//
//    cout << cnt << "\n";
//
//    return 0;
//}