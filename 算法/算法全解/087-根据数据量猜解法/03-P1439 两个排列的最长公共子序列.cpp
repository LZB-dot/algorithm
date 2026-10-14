//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int n;
//vector<int>p1, p2;
//vector<int>where;
//
//int main() {
//	cin >> n;
//	p1.resize(n, 0);
//	p2.resize(n, 0);
//	where.resize(n + 1, 0);
//	for (int i = 0; i < n; ++i) {
//		cin >> p1[i];
//		where[p1[i]] = i;
//	}
//	for (int i = 0; i < n; ++i){
//		cin >> p2[i];
//		p2[i] = where[p2[i]];
//	}
//
//	vector<int>lis;
//	for (int num : p2) {
//		//找lis中第一个>=num的元素的迭代器
//		auto it = lower_bound(lis.begin(), lis.end(), num);
//		if (it == lis.end())
//			lis.push_back(num);
//		else {
//			*it = num;
//		}
//	}
//	cout << lis.size() << endl;
//
//	return 0;
//}
//
//
//
