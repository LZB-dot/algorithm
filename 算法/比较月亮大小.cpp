//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>v(n, 0);
//	bool flag = false;
//	for (int i = 0; i < n; i++)
//		cin >> v.at(i);
//	if (n == 1 && v.at(0) != 0 && v.at(0) != 15)
//	{
//		cout << "-1" << endl;
//		return 0;
//	}
//	if (v.at(n - 1) == 15)
//		cout << "DOWN" << endl;
//	else if (v.at(n - 1) == 0)
//		cout << "UP" << endl;
//	else if (v.at(n - 1) - v.at(n - 2) > 0)
//		cout << "UP" << endl;
//	else
//		cout << "DOWN" << endl;
//	return 0;
//}