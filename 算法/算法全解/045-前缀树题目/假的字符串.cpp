//#include<iostream>
//#include<vector>
//#include<string>
//#include<queue>
//using namespace std;
//
//const int N = 3e5 + 5;
//int trie[N][26];
//bool ed[N];
//int total = 1;
//vector<string>res;
//
//int in[26];//入度
//vector<int>adj[26];//邻接表
//
//void insert(const string& words)
//{
//    int cur = 1;
//    for (char c : words) {
//        int path = c - 'a';
//        if (trie[cur][path] == 0)
//            trie[cur][path] = ++total;
//        cur = trie[cur][path];
//    }
//    ed[cur] = 1;
//}
//
//bool TopoSort()
//{
//    int cur = 0;//已排序的字母数量
//    queue<int>q;//存储入度为0的字母，即可直接排序
//    for (int i = 0; i < 26; ++i)
//        if (in[i] == 0)
//            q.push(i);//入度为0直接加入队列
//
//    while (!q.empty()) {
//        int tmp = q.front();
//        q.pop();
//        cur++;
//
//        for (int v : adj[tmp])
//            if (--in[v] == 0)//v入度-1，因为tmp已排序，v少了前置约束
//                q.push(v);//变为0入队
//    }
//    return cur == 26;//26个字母均排序无矛盾，否则存在环
//}
//
//bool is(const string& s)
//{
//    //初始化
//    for (int i = 0; i < 26; ++i) {
//        in[i] = 0;
//        adj[i].clear();
//    }
//    int cur = 1;
//    for (int i = 0; i < s.size(); ++i) {
//        char c = s[i];
//        int path = c - 'a';
//
//        for (int j = 0; j < 26; ++j) {
//            if (j != path && trie[cur][j] != 0) {
//                adj[path].push_back(j);//计算邻接表
//                in[j]++;//计算入度
//            }
//        }
//        if (ed[cur])//去除前缀
//            return false;
//        cur = trie[cur][path];
//    }
//    return TopoSort();
//}
//
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    int n;
//    cin >> n;
//    vector<string>arr(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> arr[i];
//        insert(arr[i]);
//    }
//
//    for (const string& s : arr)
//        if (is(s))
//            res.push_back(s);
//
//
//    cout << res.size() << endl;
//    for (string s : res)
//        cout << s << endl;
//
//    return 0;
//}


////3
////ab
////aa
////bb
////2
////aa
////bb