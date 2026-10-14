//#include<iostream>
//#include<vector>
//using namespace std;
//
//bool solve(string str1, string str2) {
//	if (str1 == str2)
//		return true;
//
//	vector<int>cnt(26, 0);
//	int counts = 0;
//	for (char c : str2) {
//		if (cnt[c - 'a']++ == 0)
//			counts++;
//	}
//
//	if (counts == 26)
//		return false;
//
//	int n = str1.size();
//	vector<int>map(26, -1);
//	for (int i = 0; i < n; ++i) {
//		int idx = str1[i] - 'a';
//		int target = str2[i] - 'a';
//		if (map[idx] != -1 && map[idx] != target) {
//			return false;
//		}
//		map[idx] = target;
//	}
//
//	return true;
//	
//}