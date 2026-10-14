//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//
//typedef long long ll;
//typedef pair<int, int> pii;
//
//ll max_area = 0;
//int width, height;
//int n;
//
//vector<int> x;
//vector<int> y;
//vector<int> dx;
//vector<int> dy;
//
//vector<vector<int>> dp;
//vector<int> left_;
//vector<int> right_;
//vector<int> st;
//vector<int> nearx;
//vector<vector<bool>> obstacle;
//
//int getx(int x) {
//    return lower_bound(dx.begin() + 1, dx.end(), x) - dx.begin();
//}
//
//int gety(int y) {
//    return lower_bound(dy.begin() + 1, dy.end(), y) - dy.begin();
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    cin >> width >> height >> n;
//
//    x.resize(n + 1);
//    y.resize(n + 1);
//
//    for (int i = 1; i <= n; ++i) {
//        cin >> x[i] >> y[i];
//        dx.push_back(x[i]);
//        dy.push_back(y[i]);
//    }
//
//    dx.push_back(0);
//    dx.push_back(width);
//    dy.push_back(0);
//    dy.push_back(height);
//
//    sort(dx.begin(), dx.end());
//    dx.erase(unique(dx.begin(), dx.end()), dx.end());
//    dx.insert(dx.begin(), 0);
//    int cntx = dx.size() - 1;
//
//    sort(dy.begin(), dy.end());
//    dy.erase(unique(dy.begin(), dy.end()), dy.end());
//    dy.insert(dy.begin(), 0);
//    int cnty = dy.size() - 1;
//
//    obstacle.resize(cntx + 1, vector<bool>(cnty + 1, false));
//    for (int i = 1; i <= n; ++i) {
//        int x_idx = getx(x[i]);
//        int y_idx = gety(y[i]);
//        obstacle[x_idx][y_idx] = true;
//    }
//
//    dp.resize(cntx + 1, vector<int>(cnty + 1, 0));
//    nearx.resize(cnty + 1, 0);
//
//    for (int i = 1; i <= cntx; ++i) {
//        for (int j = 1; j <= cnty; ++j) {
//            dp[i][j] = dx[i] - nearx[j];
//            if (obstacle[i][j]) {
//                nearx[j] = dx[i];
//            }
//        }
//    }
//
//    left_.resize(cnty + 1);
//    right_.resize(cnty + 1);
//    st.reserve(cnty + 1);
//
//    for (int x_idx = 1; x_idx <= cntx; ++x_idx) {
//        st.clear();
//        fill(left_.begin(), left_.end(), 0);
//        fill(right_.begin(), right_.end(), 0);
//
//        for (int y_idx = 1; y_idx <= cnty; ++y_idx) {
//            while (!st.empty() && dp[x_idx][st.back()] >= dp[x_idx][y_idx]) {
//                st.pop_back();
//            }
//            left_[y_idx] = st.empty() ? 0 : dy[st.back()];
//            st.push_back(y_idx);
//        }
//
//        st.clear();
//        for (int y_idx = cnty; y_idx >= 1; --y_idx) {
//            while (!st.empty() && dp[x_idx][st.back()] >= dp[x_idx][y_idx]) {
//                st.pop_back();
//            }
//            right_[y_idx] = st.empty() ? height : dy[st.back()];
//            st.push_back(y_idx);
//        }
//
//        for (int y_idx = 1; y_idx <= cnty; ++y_idx) {
//            ll current_area = (ll)dp[x_idx][y_idx] * (right_[y_idx] - left_[y_idx]);
//            max_area = max(max_area, current_area);
//            if (y_idx > 1) {
//                ll edge_area = (ll)dx[x_idx] * (dy[y_idx] - dy[y_idx - 1]);
//                max_area = max(max_area, edge_area);
//            }
//        }
//    }
//
//    cout << max_area << endl;
//
//    return 0;
//}