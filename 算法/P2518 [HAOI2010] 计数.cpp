//#include<iostream>
//using namespace std;
//
//typedef long long ll;
//
//ll C[1001][1001];//C(i,j)，从i个中选j个组合数
//
//ll calC(ll n, ll m) {
//
//    if (C[n][m])
//        return C[n][m];
//    //在n个里面选1个有n种方法
//    if (m == 1)
//        return n;
//    //在n个里面选0个和n个都只有1种方法
//    if (m == 0 || m == n)
//        return 1;
//    //无意义
//    if (m > n)
//        return 0;
//    //递推公式
//    //选m个=不选第n个+选第n个
//    C[n][m] = calC(n - 1, m) + calC(n - 1, m - 1);
//    return C[n][m];
//}
//
//int freq[10];//数字i剩余数量
//int num[52];//存储数字
//ll ans;
//int n;//剩余需要排列的数字位数
//string s;
//
//ll cfb() {
//    ll ans = 1;//存储当前排列数
//    int m = n;
//    //枚举0-9
//    for (int i = 0; i <= 9; i++)
//        //如果有剩余，就计算组合数
//        if (freq[i]){
//            ans *= calC(m, freq[i]);
//            m -= freq[i];
//        }
//    return ans;
//}
//
//int main()
//{
//    cin >> s;
//    for (char c : s) {
//        num[++n] = c - '0';
//        freq[c - '0']++;
//    }
//
//    int tmp = n;
//    for (int i = 1; i <= tmp; i++) {
//        n--;//剩余排列位置-1，当前位计算
//        //枚举比原数该位小的所有数字
//        for (int j = 0; j < num[i]; j++)
//            if (freq[j]) {
//                freq[j]--; //选j放到当前位
//                ans += cfb(); //计算剩余位的排列数
//                freq[j]++; //回溯
//            }
//        freq[num[i]]--;//选回原数该位的数
//    }
//    cout << ans;
//    return 0;
//}
