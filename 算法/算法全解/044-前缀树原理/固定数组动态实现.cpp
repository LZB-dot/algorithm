
////路的可能性范围小，用固定数组实现
//
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//const int N = 26;
//
//struct TrieNode {
//	int pass;//记录有多少个字符串经过该节点
//	int end;//记录有多少个字符串以此结尾
//	TrieNode* next[N];//子节点数组，对应26个小写字母
//
//	TrieNode() :pass(0), end(0) {
//		for (int i = 0; i < N; i++)
//			next[i] = nullptr;
//	}
//};
//
//class Trie
//{
//private:
//	TrieNode* root;//根节点，所有字符串的起点
//
//public:
//	Trie() {//初始化根节点
//		root = new TrieNode();
//	}
//	//插入字符串到前缀树
//	void insert(const string& word)
//	{
//		TrieNode* node = root;
//		node->pass++;//根节点的pass是必经的
//		for (char c : word)
//		{
//			int path = c - 'a';//路径下标
//			//如果不存在该条路径，则新建
//			if (node->next[path] == nullptr)
//				node->next[path] = new TrieNode;
//			node = node->next[path];//移动到子节点
//			node->pass++;//子节点经过+1
//		}
//		node->end++;//结尾子节点+1
//	}
//	//查询字符串在前缀树中出现的次数
//	int search(const string& word)
//	{
//		TrieNode* node = root;
//		for (char c : word)
//		{
//			int path = c - 'a';
//			if (node->next[path] == nullptr)
//				return 0;
//			node = node->next[path];
//		}
//		return node->end;
//	}
//	//查询指定字符串前缀的数量
//	int prefixCount(const string& prefix)
//	{
//		TrieNode* node = root;
//		for (char c : prefix)
//		{
//			int path = c - 'a';
//			if (node->next[path] == nullptr)
//				return 0;
//			node = node->next[path];
//		}
//		return node->pass;
//	}
//	//删除字符串
//	void remove(const string& word)
//	{
//		if (search(word) == 0)
//			return;//找不到直接返回
//		TrieNode* node = root;
//		root->pass--;
//		for (char c : word)
//		{
//			int path = c - 'a';
//			TrieNode* child = node->next[path];
//			child->pass--;
//			if (child->pass == 0)
//			{
//				node->next[path] = nullptr;
//				delete child;
//				return;
//			}
//			node = child;
//		}
//		node->end--;
//	}
//};