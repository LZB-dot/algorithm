//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int n, m;
//int d[10000005];
//
//int main()
//{
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//    {
//        int v, x;
//        cin >> v >> x;
//        d[x - 3 * v + 1 +1000000]++;
//        d[x - 2 * v + 1 +1000000] -= 2;
//        d[x + 1 +1000000] += 2;
//        d[x + 2 * v + 1 +1000000] -= 2;
//        d[x + 3 * v + 1 +1000000]++;
//    }
//    int ans = 0, now = 0;
//    for (int i = 0; i <= 1000000; i++)
//    {
//        now += d[i];
//        ans += now;
//    }
//    for (int i = 1000001; i <= m + 1000000; i++)
//    {
//        now += d[i];
//        ans += now;
//        cout << ans << " ";
//    }
//    cout << "\n";
//    return 0;
//}
//
