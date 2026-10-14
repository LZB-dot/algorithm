//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int N = 11;
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    int x[8] = { -1,-1,-1,0,1,1,1,0 };
//    int y[8] = { -1,0,1,1,1,0,-1,-1 };
//    vector<vector<char>>v(n, vector<char>(m));
//    vector<vector<char>>res(n, vector<char>(m));
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//            cin >> v[i][j];
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//        {
//            if (v[i][j] == '*')
//                res[i][j] = '*';
//            else
//            {
//                int temp = 0;
//                for (int k = 0; k < 8; k++)
//                {
//                    int dx = i + x[k];
//                    int dy = j + y[k];
//                    if (dx < 0 || dy < 0 || dx >= n || dy >= m)
//                        continue;
//                    if (v[dx][dy] == '*')
//                        temp++;
//                }
//                res[i][j] = temp + '0';
//            }
//        }
//    for (vector<char>& a : res)
//    {
//        for (char b : a)
//            cout << b;
//        cout << endl;
//    }
//
//    return 0;
//}