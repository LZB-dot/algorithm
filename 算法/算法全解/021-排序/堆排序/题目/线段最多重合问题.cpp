//#include <iostream>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//#define endl "\n"
//#pragma GCC optimize(3)
//
//const int N = 10005;
//int arr[N][2];
//
//bool compare(int a, int b) {
//    return a < b;
//}
//
//int work(int n)
//{
//    int ans = 0;
//    if (n == 0)
//        return ans;
//    sort(arr, arr + n, compare);
//
//    priority_queue<int, vector<int>, greater<int>>pq;
//
//    for (int i = 0; i < n; ++i)
//    {
//        int s = arr[i][0];
//        int e = arr[i][1];
//        while (!pq.empty() && pq.top() <= s)
//            pq.pop();
//        pq.push(e);
//        ans = max(ans, (int)pq.size());
//    }
//    return ans;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//        cin >> arr[i][0] >> arr[i][1];
//
//    cout << work(n) << endl;
//    return 0;
//}