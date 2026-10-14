//#include<iostream>
//#include<vector>
//#include<cctype> 
//using namespace std;
//
//
//inline int read() {
//    char c;
//    int num = 0;
//
//    while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
//
//    bool flag = false;
//    if (c == '-') {
//        flag = true;
//        c = getchar(); 
//    }
//
//    while (isdigit(c)) {
//        num = num * 10 + (c - '0');
//        c = getchar();
//    }
//
//    return flag ? -num : num;
//}
//
//int main() {
//
//    int c = read(), h = read();
//    vector<int> nums(h);
//
//    for (int i = 0; i < h; ++i) 
//        nums[i] = read();
//    
//
//    vector<int> dp(c + 1, 0);
//
//    for (int i = 0; i < h; ++i) {
//        int w = nums[i];
//
//        for (int j = c; j >= w; --j) {
//            dp[j] = max(dp[j], dp[j - w] + w);
//        }
//    }
//
//    cout << dp[c] << "\n";
//    return 0;
//}