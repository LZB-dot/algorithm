//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//	int table[5][5] = {
//		{0,0,1,1,0},
//		{1,0,0,1,0},
//		{0,1,0,0,1},
//		{0,0,1,0,1},
//		{1,1,0,0,0}
//	};
//
//	int n, a, b;
//	cin >> n >> a >> b;
//	vector<int>A(a);
//	vector<int>B(b);
//	for (int i = 0; i < a; ++i)
//		cin >> A[i];
//	for (int i = 0; i < b; ++i)
//		cin >> B[i];
//
//	int suma = 0, sumb = 0;
//	for (int i = 0; i < n; ++i) {
//		suma += table[A[i % a]][B[i % b]];
//		sumb += table[B[i % b]][A[i % a]];
//	}
//	cout << suma << " " << sumb << "\n";
//	return 0;
//}