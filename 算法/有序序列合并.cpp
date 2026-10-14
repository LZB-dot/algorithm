//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//
//    vector<int> v1(n);
//    vector<int> v2(m);
//    for (int k = 0; k < n; k++) 
//        cin >> v1[k];  
//
//    for (int k = 0; k < m; k++)
//        cin >> v2[k];  
//
//    vector<int> res(n + m); 
//    int i = 0, j = 0, x = 0; 
//
//    while (i < n && j < m) 
//    { 
//        if (v1[i] <= v2[j])
//            res[x++] = v1[i++];
//        else
//            res[x++] = v2[j++];
//    }
//
//    while (i < n)
//        res[x++] = v1[i++];
//    while (j < m)
//        res[x++] = v2[j++];
//
//    for (int num : res)
//        cout << num << " ";
//    cout << endl;
//
//    return 0;
//}