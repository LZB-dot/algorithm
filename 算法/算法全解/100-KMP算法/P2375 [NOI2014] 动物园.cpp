//#include <iostream>
//#include <vector>
//#include <string>
//#include <cstring>
//using namespace std;
//
//const long long MOD = 1e9 + 7;
//
//vector<int> getNxt(const string& s) {
//    int m = s.size();
//    vector<int> nxt(m + 1);
//    nxt[0] = 0;
//    if (m == 0)
//        return nxt;
//    nxt[1] = 0;
//
//    int i = 2, cn = 0;
//    while (i <= m) {
//        if (s[i - 1] == s[cn]) 
//            nxt[i++] = ++cn;       
//        else if (cn > 0) 
//            cn = nxt[cn];        
//        else 
//            nxt[i++] = 0;        
//    }
//    return nxt;
//}
//
//int main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string a;
//        cin >> a;
//        int n = a.size();
//        if (n == 0) {
//            cout << 0 << endl;
//            continue;
//        }
//
//        vector<int> nxt = getNxt(a);
//
//        vector<int> ans(n + 1, 0);
//        ans[1] = 1; //第一个字符的公共前后缀只有自己，数量为1
//        for (int i = 2; i <= n; ++i) {
//            ans[i] = ans[nxt[i]] + 1; // 父节点深度+1 = 当前节点深度
//        }
//
//        //所有前缀的不重叠公共前后缀数量+1的乘积
//        long long cnt = 1;
//        int j = 0; //记录当前匹配的最长不重叠公共前后缀长度
//        for (int i = 1; i <= n; ++i) { 
//            while (j > 0 && a[i - 1] != a[j]) 
//                j = nxt[j];
//            
//            if (a[i - 1] == a[j]) 
//                j++;
//            
//            while ((j << 1) > i)  //j过长，需要回撤
//                j = nxt[j];
//            
//            cnt = (cnt * (ans[j] + 1)) % MOD;
//        }
//
//        cout << cnt << endl;
//    }
//    return 0;
//}