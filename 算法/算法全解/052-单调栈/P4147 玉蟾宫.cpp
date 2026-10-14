//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m;
//    cin >> n >> m;
//
//    vector<vector<int>> grid(n, vector<int>(m, 0));
//    char x;
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> x;
//            if (x == 'F') {
//                grid[i][j] = (i == 0) ? 1 : grid[i - 1][j] + 1;
//            }
//            else {
//                grid[i][j] = 0;
//            }
//        }
//    }
//
//    int mx = 0;
//
//    for (int i = 0; i < n; ++i) {
//        vector<int> st;
//
//        for (int j = 0; j <= m; ++j) {
//            //添加0最小高度的判断，可以保证全部出栈
//            int cur = (j < m) ? grid[i][j] : 0;
//
//            while (!st.empty() && cur < grid[i][st.back()]) {
//                int top = st.back();
//                st.pop_back();
//
//                int left = (st.empty()) ? -1 : st.back();
//                int len = j - left - 1;
//                int w = grid[i][top];
//                mx = max(mx, len * w);
//            }
//
//            st.push_back(j);
//        }
//    }
//
//    cout << mx * 3 << endl;
//    return 0;
//}