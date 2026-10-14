////#include<iostream>
////#include<vector>
////#include<cstring>
////using namespace std;
////
////typedef long long ll;
////vector<int> num;
////int digit;
////ll memo[20][2][20][2];
////
////
////// lead → zero（0=无前导零，1=有前导零）
////ll dfs(int len, int free, int sum, int lead, int target) {
////
////    if (len == 0) 
////        return sum;
////
////    if (memo[len][free][sum][lead] != -1) {
////        return memo[len][free][sum][lead];
////    }
////
////    ll res = 0;
////    int upper = free ? 9 : num[len];
////
////    for (int i = 0; i < 10; i++) { 
////        if (!free && i > upper)
////            break;
////        int new_free = free || (i < upper);  
////        int new_lead = lead && (i == 0);   
////        int new_sum = sum + ((!lead || i) && (i == target));
////
////        res += dfs(len - 1, new_free, new_sum, new_lead, target);
////    }
////
////    memo[len][free][sum][lead] = res;
////    return res;
////}
////
////ll count(ll x, int target) {
////    digit = 0;
////    num.clear();
////    num.resize(20);  
////
////    if (x == 0) {
////        digit = 1;
////        num[1] = 0;
////    }
////    else {
////        while (x) {
////            digit++;
////            num[digit] = x % 10;
////            x /= 10;
////        }
////    }
////
////    memset(memo, -1, sizeof(memo));
////    return dfs(digit, 0, 0, 1, target);
////}
////
////int main() {
////    ll a, b;
////    cin >> a >> b;
////
////    for (int i = 0; i < 10; i++) {
////        ll c1 = count(b, i);
////        ll c2 = count(a - 1, i);
////        cout << (c1 - c2) << " ";
////    }
////    cout << endl;
////
////    return 0;
////}
//
//
//#include<iostream>
//using namespace std;
//
//typedef long long ll;
//
//ll count(ll num, int d) {
//    if (num < 0) 
//        return 0;
//    if (num == 0) 
//        return (d == 0) ? 1 : 0;
//
//    ll ans = 0;
//    ll right = 1; 
//    ll tmp = num; 
//
//    while (tmp > 0) {
//        ll cur = tmp % 10;  // 当前位数字
//        ll left = tmp / 10; // 当前位左边的数字
//        ll rt = num % right; // 当前位右边的数字
//
//        if (d == 0) {
//            // 数字0的特殊处理,前导0不计入
//            if (left > 0) {
//                // 0 不能作为最高位，所以left先减1
//                ans += (left - 1) * right;
//            }
//            if (left > 0) {
//                if (cur > 0) {
//                    ans += right;
//                }
//                else if (cur == 0) {
//                    ans += rt + 1;
//                }
//            }
//        }
//        else {
//            ans += left * right;
//            if (cur > d) {
//                ans += right;
//            }
//            else if (cur == d) {
//                ans += rt + 1;
//            }
//        }
//
//        tmp /= 10;
//        right *= 10;
//    }
//
//    return ans;
//}
//
//int main() {
//    ll a, b;
//    cin >> a >> b;
//
//    for (int i = 0; i < 10; i++) {
//        ll cnt_b = count(b, i);       
//        ll cnt_a_1 = count(a - 1, i);
//        cout << (cnt_b - cnt_a_1) << " ";
//    }
//    cout << endl;
//
//    return 0;
//}