//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//int n, m;
//vector<int> nums;
//int mx = 0;
//const int MAXN = 2005;  
//
//void dfs(int mask, int cnt, int pos, vector<bool> weight) {
//    if (cnt == n - m) {
//        int count = 0;
//        for (int w = 1; w <= MAXN; ++w) {
//            if (weight[w]) 
//                count++;
//        }
//        mx = max(mx, count);
//        return;
//    }
//
//    // ¼ôÖ¦£ºÊ£ÓàíÀÂë²»¹»
//    if (cnt + (n - pos) < n - m)
//        return;
//
//    for (int i = pos; i < n; ++i) {
//        if ((mask & (1 << i)) != 0)
//            continue;
//
//
//        vector<bool> new_weight = weight;
//        int cur = nums[i];
//
//        for (int w = 0; w <= MAXN - cur; ++w) {
//            if (weight[w]) {
//                new_weight[w + cur] = true;
//            }
//        }
//
//        dfs(mask | (1 << i), cnt + 1, i + 1, new_weight);
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> m;
//    nums.resize(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//
//    vector<bool> weight(MAXN, false);
//    weight[0] = true;
//
//    dfs(0, 0, 0, weight);
//    cout << mx << "\n";
//    return 0;
//}