//
////路的可能性范围大，用哈希表实现
//
//
//#include<iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
//
//const int N = 26;
//
//struct TrieNode {
//	int pass;//记录有多少个字符串经过该节点
//	int end;//记录有多少个字符串以此结尾
//	//哈希表存储子节点，键为字符，值为子节点指针
//	unordered_map<char, TrieNode*>next; 
//
//	TrieNode() :pass(0), end(0) {}
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
//			//如果不存在该条路径，则新建
//			if (node->next.find(c) == node->next.end())
//				node->next[c] = new TrieNode;
//			node = node->next[c];//移动到子节点
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
//			if (node->next.find(c) == node->next.end())
//				return 0;
//			node = node->next[c];
//		}
//		return node->end;
//	}
//	//查询指定字符串前缀的数量
//	int prefixCount(const string& prefix)
//	{
//		TrieNode* node = root;
//		for (char c : prefix)
//		{
//			if (node->next.find(c) == node->next.end())
//				return 0;
//			node = node->next[c];
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
//			TrieNode* child = node->next[c];
//			child->pass--;
//			if (child->pass == 0)
//			{
//				node->next.erase(c);
//				delete child;
//				return;
//			}
//			node = child;
//		}
//		node->end--;
//	}
//};