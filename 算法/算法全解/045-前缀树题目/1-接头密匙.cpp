//
//const int MAX_NODE = 600;
//const int N = 12;//'#','-'
//int trie[MAX_NODE][N];
//int pass[MAX_NODE];
//int ed[MAX_NODE];
//int total = 1;
//
//class Solution {
//public:
//
//	void Init()
//	{
//		total = 1;
//		for (int i = 0; i < MAX_NODE; i++)
//		{
//			pass[i] = 0;
//			ed[i] = 0;
//			for (int j = 0; j < N; j++)
//				trie[i][j] = 0;
//		}
//	}
//
//	int path(char c)
//	{
//		if (c == '#')
//			return 10;
//		else if (c == '-')
//			return 11;
//		else
//			return c - '0';
//	}
//
//	void insert(const string& word)
//	{
//		int cur = 1;
//		pass[cur]++;
//		for (char c : word)
//		{
//			int p = path(c);
//			if (trie[cur][p] == 0)
//				trie[cur][p] = ++total;
//			cur = trie[cur][p];
//			pass[cur]++;
//		}
//		ed[cur]++;
//	}
//
//	int search(const string& s)
//	{
//		int cur = 1;
//		for (char c : s)
//		{
//			int p = path(c);
//			if (trie[cur][p] == 0)
//				return 0;
//			cur = trie[cur][p];
//		}
//		return ed[cur];
//	}
//
//	int prefixCount(const string& pre)
//	{
//		int cur = 1;
//		for (char c : pre)
//		{
//			int p = path(c);
//			if (trie[cur][p] == 0)
//				return 0;
//			cur = trie[cur][p];
//		}
//		return pass[cur];
//	}
//
//	void remove(const string& s)
//	{
//		int cur = 1;
//		pass[cur]--;
//		for (char c : s)
//		{
//			int p = path(c);
//			int child = trie[cur][p];
//			pass[child]--;
//			if (pass[child] == 0)
//			{
//				trie[cur][p] = 0;
//				return;
//			}
//			cur = child;
//		}
//		ed[cur]--;
//	}
//
//	vector<int> countConsistentKeys(vector<vector<int> >& b, vector<vector<int> >& a) {
//		string x;
//		for (vector<int>& nums : a)
//		{
//			x.clear();
//			for (int i = 1; i < nums.size(); i++)
//				x += to_string(nums[i] - nums[i - 1]) + "#";
//			insert(x);
//		}
//
//		vector<int>ans(b.size());
//		for (int i = 0; i < b.size(); i++)
//		{
//			x.clear();
//			vector<int>& nums = b[i];
//			for (int j = 1; j < nums.size(); j++)
//				x += to_string(nums[j] - nums[j - 1]) + "#";
//			ans[i] = prefixCount(x);
//		}
//		Init();
//		return ans;
//	}
//};