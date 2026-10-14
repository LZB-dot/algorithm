//
////适用于严格的竞赛
//
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//const int MAXN = 1e6;//最大节点数量
//const int MAXM = 26;//字符数量
//
////每一层存放该节点i的子节点索引
////trie[i][j] 的值就是节点 i 中，字符 j（即 'a'+j）对应的子节点的索引。
//int trie[MAXN][MAXM];
//int pass[MAXN];//统计经过该节点的字符串数量
//int ed[MAXN];//统计以该节点为结尾的字符串数量
//int total;//已使用的节点总数
//
//void Init()
//{
//	total = 1;
//	for (int i = 0; i < MAXN; i++)
//	{
//		for (int j = 0; j < MAXM; j++)
//			trie[i][j] = 0;
//		pass[i] = 0;
//		ed[i] = 0;
//	}
//}
//
//void insert(const string& word)
//{
//	int cur = 1;//从根节点开始
//	pass[cur]++;//所有字符串都经过根节点
//	for (char c : word)
//	{
//		int path = c - 'a';
//		if (trie[cur][path] == 0)//子节点不存在需要新建
//			trie[cur][path] = ++total;
//		cur = trie[cur][path];//移动到子节点
//		pass[cur]++;//子节点路过+1
//	}
//	ed[cur]++;//结尾+1
//}
//
//int search(const string& word)
//{
//	int cur = 1;
//	for (char c : word)
//	{
//		int path = c - 'a';
//		if (trie[cur][path] == 0)
//			return 0;
//		cur = trie[cur][path];
//	}
//	return ed[cur];
//}
//
//int prefixCount(const string& prefix)
//{
//	int cur = 1;
//	for (char c : prefix)
//	{
//		int path = c - 'a';
//		if (trie[cur][path] == 0)
//			return 0;
//		cur = trie[cur][path];
//	}
//	return pass[cur];
//}
//
//void remove(const string& word)
//{
//	if (search(word) == 0)
//		return;
//	int cur = 1;
//	pass[cur]--;
//	for (char c : word)
//	{
//		int path = c - 'a';
//		int child = trie[cur][path];
//		pass[child]--;
//		if (pass[child] == 0)
//		{
//			trie[cur][path] = 0;
//			return;
//		}
//		cur = trie[cur][path];
//	}
//	ed[cur]--;
//}