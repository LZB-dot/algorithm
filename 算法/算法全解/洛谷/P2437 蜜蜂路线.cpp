//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//const int N = 1001;
//vector<vector<int>> dp(N);  
//
//
//vector<int> add(vector<int>& a, vector<int>& b) {
//    vector<int> ans;
//    int carry = 0; 
//    int i = 0;
//
//    while (i < a.size() || i < b.size() || carry > 0) {
//        int sum = carry; 
//
//        if (i < a.size()) 
//            sum += a[i];
//
//        if (i < b.size()) 
//            sum += b[i];
//        
//        ans.push_back(sum % 10);
//        carry = sum / 10;
//        i++;
//    }
//    return ans;
//}
//
//void work(int k) {
//    
//    if (k >= 1) 
//        dp[1] = { 1 }; 
//    if (k >= 2) 
//        dp[2] = { 2 }; 
//
//    for (int i = 3; i <= k; ++i) {
//        dp[i] = add(dp[i - 1], dp[i - 2]);
//    }
//}
//
//int main() {
//    int m, n;
//    cin >> m >> n;
//    int k = n - m;
//
//    work(k);
//
//    reverse(dp[k].begin(), dp[k].end());
//    for (int num : dp[k]) {
//        cout << num;
//    }
//    cout << endl;
//
//    return 0;
//}