//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//vector<int> father, size_;
//
//void init(int n) {
//    father.resize(n + 1);
//    size_.resize(n + 1, 1);
//    for (int i = 1; i <= n; ++i) {
//        father[i] = i;
//    }
//}
//
//int find(int x) {
//    int fx = x;
//    while (father[fx] != fx) {
//        fx = father[fx];
//    }
//    while (father[x] != fx) {
//        int nxt = father[x];
//        father[x] = fx;
//        x = nxt;
//    }
//    return fx;
//}
//
//void unite(int x, int y) {
//    int fx = find(x);
//    int fy = find(y);
//    if (fx == fy)
//        return;
//
//    if (size_[fx] < size_[fy]) {
//        size_[fy] += size_[fx];
//        father[fx] = fy;
//    }
//    else {
//        size_[fx] += size_[fy];
//        father[fy] = fx;
//    }
//}
//
//int get_(int x, const vector<int>& nums) {
//    return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
//}
//
//void solve() {
//    int n;
//    cin >> n;
//    vector<vector<int>> ques;
//    vector<int> nums;
//    int x, y, e;
//
//    for (int i = 0; i < n; ++i) {
//        cin >> x >> y >> e;
//        ques.push_back({ x, y, e });
//        nums.push_back(x);
//        nums.push_back(y);
//    }
//
//    sort(nums.begin(), nums.end());
//    nums.erase(unique(nums.begin(), nums.end()), nums.end());
//    init(nums.size());
//
//    for (int i = 0; i < n; ++i) {
//        if (ques[i][2] == 1) {
//            x = get_(ques[i][0], nums);
//            y = get_(ques[i][1], nums);
//            unite(x, y);
//        }
//    }
//
//    for (int i = 0; i < n; ++i) {
//        if (ques[i][2] == 0) {
//            x = get_(ques[i][0], nums);
//            y = get_(ques[i][1], nums);
//            if (find(x) == find(y)) {
//                cout << "NO\n";
//                return;
//            }
//        }
//    }
//
//    cout << "YES\n";
//
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int T;
//    cin >> T;
//    while (T--) {
//        solve();
//    }
//    return 0;
//}