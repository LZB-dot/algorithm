//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//#define ll long long
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//
//    int r = 0; // 指向栈的下一个填充位置
//    vector<int> st(n + 1);
//    vector<vector<int>>ans(n, vector<int>(2, -1));
//
//    for (int i = 0; i < n; ++i) {
//        //大压小--严格递减
//        while (r > 0 && nums[i] <= nums[st[r - 1]]) {
//            int top = st[--r];
//            ans[top][1] = i;
//            ans[top][0] = (r > 0) ? st[r - 1] : -1;
//        }
//        st[r++] = i;
//    }
//
//    while (r > 0) {
//        int top = st[--r];
//        ans[top][1] = n;
//        ans[top][0] = (r > 0) ? st[r - 1] : -1;
//    }
//
//    //for (int i = n - 2; i >= 0; --i) {
//    //    if (ans[i][1] != -1 && nums[ans[i][1]] == nums[i])
//    //        ans[i][1] = ans[ans[i][1]][1];
//    //}
//
//    ll mx = 0;
//    for (int i = 0; i < n; ++i) {
//        int len = ans[i][1] - ans[i][0] - 1;
//        mx = max(mx, (ll)len * nums[i]);
//    }
//
//    cout << mx << "\n";
//
//    return 0;
//}