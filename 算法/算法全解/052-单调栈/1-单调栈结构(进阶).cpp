//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 1000010;
//const int INF = -1000000;  
//
//int st[MAXN];
//int r = 0;//栈顶存放下一个元素位置
//int ans[MAXN][3]; 
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//    vector<int> a(n + 2, 0);
//    for (int i = 1; i <= n; ++i) {
//        cin >> a[i];
//    }
//
//    a[0] = INF;
//    a[n + 1] = INF;
//
//    for (int i = 0; i <= n + 1; ++i) {
//        while (r != 0 && a[st[r - 1]] >= a[i]) {
//            int top = st[--r];
//            ans[top][1] = st[r - 1];
//            ans[top][2] = i;
//        }
//
//        st[r++] = i;
//    }
//
//    for (int i = n; i >= 1; --i) {
//        if (ans[i][2] != n + 1 && a[i] == a[ans[i][2]]) 
//            ans[i][2] = ans[ans[i][2]][2];
//    }
//
//    for (int i = 1; i <= n; ++i) {
//        int L = ans[i][1];
//        int R = ans[i][2];
//
//        int x = (L == 0) ? -1 : L - 1;
//        int y = (R == n + 1) ? -1 : R - 1;
//
//        cout << x << " " << y << "\n";
//    }
//
//    return 0;
//}