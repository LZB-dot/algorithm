//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<vector<int>>grid(n, vector<int>(n, -1));
//	int k = 1;
//	int prex = 0, prey = n >> 1;
//	grid[prex][prey] = k;
//	while (k < n * n) {
//		++k;
//		if (prex == 0 && prey != n - 1) {
//			prex = n - 1;
//			prey = prey + 1;
//		}
//		else if (prex != 0 && prey == n - 1) {
//			prex = prex - 1;
//			prey = 0;
//		}
//		else if (prex == 0 && prey == n - 1) {
//			prex = prex + 1;
//		}
//		else if (prex != 0 && prey != n - 1) {
//			if (grid[prex - 1][prey + 1] == -1) {
//				prex = prex - 1;
//				prey = prey + 1;
//			}
//			else
//				prex = prex + 1;
//		}
//		grid[prex][prey] = k;
//	}
//
//	for (auto& i : grid) {
//		for (int j : i)
//			cout << j << " ";
//		cout << "\n";
//	}
//	return 0;
//}