//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//#include<string>
//using namespace std;
//
//const int MAXN = 200001;  //目标字符串数量
//const int MAXS = 200001;  //所有目标字符串的总字符数量
//
////前缀树
//int tree[MAXS][26], ed[MAXN];
//int cnt = 0;              //节点计数
//
//// 链式前向星
//int head[MAXS], nxt[MAXS], to[MAXS];
//int edge = 0;             //边计数
//
//int fail[MAXS];
//int times[MAXS];
//
////加边
//void add(int u, int v) {
//    nxt[edge] = head[u];
//    to[edge] = v;
//    head[u] = edge;    
//    edge++;           
//}
//
////插入字符串到字典树
//void insert(int i, const string& s) {
//    int u = 0;
//    for (char c : s) {
//        int path = c - 'a';
//        if (!tree[u][path])
//            tree[u][path] = ++cnt;
//        u = tree[u][path];
//    }
//    ed[i] = u;//记录每个字符串的结尾节点编号
//}
//
////构建fail指针
////--指向当前节点结尾字符串的最长真后缀对应的节点
//void setFail() {
//    queue<int> q;
//    //初始化根节点的子节点
//    //根节点的子节点的fail均指向根，即最长真后缀为空集
//    for (int i = 0; i < 26; ++i) {
//        if (tree[0][i]) {
//            fail[tree[0][i]] = 0; 
//            q.push(tree[0][i]);
//        }
//    }
//
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        //遍历当前节点的所有子节点
//        for (int i = 0; i < 26; ++i) {
//            //子节点存在，进队
//            //设置fail指针为父节点的fail指针指向的节点加上当前这个字符对应的子节点
//            if (tree[u][i]) {
//                fail[tree[u][i]] = tree[fail[u]][i];
//                q.push(tree[u][i]);
//            }
//            //不存在的子节点指向父节点的fail指针指向的节点加上当前这个字符对应的子节点
//            else {
//                tree[u][i] = tree[fail[u]][i];
//            }
//        }
//    }
//}
//
////DFS 循环条件 edge 从 0 开始，i != -1 才终止
//void dfs(int u) {
//    for (int i = head[u]; i != -1; i = nxt[i]) {
//        dfs(to[i]);
//        times[u] += times[to[i]];
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    memset(head, -1, sizeof(head));
//
//    int n;
//    cin >> n;
//    ////忽略换行符（避免后续 getline 读空）
//    //cin.ignore();
//
//    for (int i = 1; i <= n; ++i) {
//        string s;
//        cin >> s;
//        //// 用 getline 读取带空格的字符串
//        //getline(cin, s);
//        insert(i, s);
//    }
//
//    setFail();
//
//    //正确读取目标文本（先 ignore 避免吞空）
//    string t;
//    cin >> t;
//    /*getline(cin, t);*/
//    int u = 0;
//    for (char c : t) {
//        u = tree[u][c - 'a'];
//        times[u]++;
//    }
//
//    // 构建 fail 反图（汇总词频用）
//    for (int i = 1; i <= cnt; ++i) {
//        add(fail[i], i);
//    }
//
//    // 遍历反图，汇总每个节点的词频
//    dfs(0);
//
//    // 输出每个目标串的出现次数
//    for (int i = 1; i <= n; ++i)
//        cout << times[ed[i]] << "\n";
//
//    return 0;
//}