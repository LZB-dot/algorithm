//////用规格 6 和 8 的袋子装苹果，求最少袋子数
////
////#include<iostream>
////#include<vector>
////#include<climits>
////using namespace std;
////
////int work(int n) {
////    if (n < 0)
////        return INT_MAX;  //用INT_MAX表示无效
////    if (n == 0)
////        return 0;       //刚好装满，0个袋子
////
////    int p1 = work(n - 6);
////    int p2 = work(n - 8);
////
////    // 计算两种方案的总袋子数（无效路径用INT_MAX标记）
////    int res1 = (p1 != INT_MAX) ? (p1 + 1) : INT_MAX;
////    int res2 = (p2 != INT_MAX) ? (p2 + 1) : INT_MAX;
////
////    return min(res1, res2);
////}
////
////int main() {
////    for (int i = 0; i < 100; ++i) {
////        int ans = work(i);
////        cout << i << ":  " << (ans == INT_MAX ? -1 : ans) << endl;
////    }
////    return 0;
////}
////
////
////0:00		 12 : 02	 18 : 03	26 : 04 	34 : 05	    42 : 06
////1 : -1	 13 : -1	 19 : -1	27 : -1	    35 : -1	    43 : -1
////2 : -1	 14 : 02	 20 : 03	28 : 04     36 : 05 	44 : 06
////3 : -1	 15 : -1	 21 : -1	29 : -1	    37 : -1	    45 : -1
////4 : -1	 16 : 02	 22 : 03	30 : 04     38 : 05     46 : 06
////5 : -1	 17 : -1	 23 : -1	31 : -1	    39 : -1	    47 : -1
////6 : 01		         24 : 03 	32 : 04    	40 : 05 	48 : 06 
////7 : -1		         25 : -1	33 : -1	    41 : -1	    49 : -1
////8 : 01
////9 : -1
////10 : -1
////11 : -1
////
//
//#include<iostream>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	if ((n & 1) != 0){
//		cout << -1;
//		return 0;
//	}
//	if (n < 18) {
//		if (n == 0)
//			cout << 0;
//		else if (n == 6 || n == 8)
//			cout << 1;
//		else if (n == 16 || n == 12 || n == 14)
//			cout << 2;
//		else
//			cout << -1;
//	}
//	else {
//		cout << (n - 18) / 8 + 3;
//	}
//	return 0;
//}