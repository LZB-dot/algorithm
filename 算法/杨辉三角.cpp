//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    vector<vector<int> >res(n, vector<int>(n, 0));
//    for (int i = 0; i < n; ++i)
//        res[i][0] = 1;
//    for (int i = 1; i < n; ++i)
//        for (int j = 1; j <= i; ++j)
//            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j <= i; ++j)
//            cout << res[i][j] << " ";
//        cout << endl;
//    }
//    return 0;
//}