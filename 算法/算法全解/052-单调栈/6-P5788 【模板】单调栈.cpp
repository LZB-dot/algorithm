//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 3e6 + 10;
//int st[MAXN];
//int r = 0;
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
//    vector<int>ans(n, 0);
//
//    for (int i = 0; i < n; ++i) {
//        while (r > 0 && nums[st[r - 1]] < nums[i]) {
//            int id = st[--r];
//            ans[id] = i + 1;
//        }
//
//        st[r++] = i;
//    }
//
//    for (int i : ans)
//        cout << i << " ";
//    cout << "\n";
//
//
//    return 0;
//}