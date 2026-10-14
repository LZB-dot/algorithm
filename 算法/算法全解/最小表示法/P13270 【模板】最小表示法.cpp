//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//    string s;
//    cin >> s;
//    string t = s + s; 
//    int i = 0, j = 1, k = 0;
//
//    while (i < n && j < n && k < n) {
//        if (i == j) {
//            j++; 
//            continue;
//        }
//
//        if (t[i + k] == t[j + k]) 
//            k++; 
//        else {
//            if (t[i + k] > t[j + k])
//                i = i + k + 1;
//            else 
//                j = j + k + 1; 
//            
//            k = 0; 
//        }
//    }
//
//    int m = min(i, j);
//    for (int x = m; x < m + n; ++x) 
//        cout << t[x];
//    
//    cout << "\n";
//
//    return 0;
//}