//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main() 
//{
//    int n, k;
//    cin >> n >> k;
//
//    if (k < 0 || k > 2 * n)
//    {
//        cout << -1 << endl;
//        return 0;
//    }
//
//    if (n % 2 == 0 && k % 2 != 0) 
//    {
//        cout << -1 << endl;
//        return 0;
//    }
//
//    int r, c;
//    if (n % 2 == 1) 
//    {  
//        r = k / 2;
//        c = k - r;
//        if (r < 0 || r > n || c < 0 || c > n)
//        {
//            cout << -1 << endl;
//            return 0;
//        }
//    }
//    else
//    { 
//        r = k / 2;
//        c = r;
//    }
//
//    vector<string> arr(n, string(n, '0'));
//
//    for (int i = 0; i < r; ++i)
//        arr[i][n - 1] = '1'; 
//
//    for (int j = 0; j < c; ++j) 
//        arr[n - 1][j] = '1';  
//
//    int a = 0;
//    for (int j = 0; j < n; ++j)
//        a ^= (arr[n - 1][j] - '0');
//
//    int b = (r <= n - 1) ? 0 : 1;
//    if (a != b) 
//        arr[n - 1][n - 1] = (arr[n - 1][n - 1] == '0') ? '1' : '0';
//
//    for (const string& row : arr)
//        cout << row << endl;
//
//    return 0;
//}
