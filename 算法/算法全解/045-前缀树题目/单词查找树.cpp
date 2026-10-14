//#include<iostream>
//#include<string>
//using namespace std;
//
//const int N = 1000;
//int trie[N][26];
//int total = 0;
//
//void work(const string& word)
//{
//	int cur = 1;
//	for (char c : word)
//	{
//		int path = c - 'A';
//		if (trie[cur][path] == 0)
//			trie[cur][path] = ++total;
//		cur = trie[cur][path];
//	}
//}
//
//int main()
//{
//	string word;
//	while (cin >> word)
//		work(word);
//	cout << total << endl;
//	return 0;
//}