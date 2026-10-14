//#include<iostream>
//using namespace std;
//
//long long catalan(int n) {
//    if (n == 0)  
//        return 1;
//    long long res = 0;
//    // 递归公式：C(n) = Σ (C(i) * C(n-1-i)) （i从0到n-1）
//    for (int i = 0; i < n; ++i) {
//        res += catalan(i) * catalan(n - 1 - i);
//    }
//    return res; 
//}
//
//int main() {
//    int n;
//    cin >> n;
//    cout << catalan(n) << endl;
//    return 0;
//}