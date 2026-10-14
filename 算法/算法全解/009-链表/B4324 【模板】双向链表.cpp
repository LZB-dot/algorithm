//#include<iostream>
//using namespace std;
//
//const int MAXN = 5e5 + 10;
//
//// 保持你的变量名：pre对应参考代码的l，nxt对应参考代码的r，deleted对应参考代码的del
//int pre[MAXN], nxt[MAXN];
//bool deleted[MAXN] = { 0 };
//
//// 辅助函数：将节点x从当前链表中摘除（仅断开链接，不标记删除）
//void rm(int x) {
//    nxt[pre[x]] = nxt[x];
//    pre[nxt[x]] = pre[x];
//}
//
//// 辅助函数：将节点x插入到节点p的右侧
//void ins(int p, int x) {
//    pre[x] = p;
//    nxt[x] = nxt[p];
//    pre[nxt[p]] = x;
//    nxt[p] = x;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m;
//    cin >> n >> m;
//
//    //新增虚拟头节点0
//    nxt[0] = 1;  // 虚拟头节点0的后继是1
//    for (int i = 1; i <= n; ++i) {
//        pre[i] = i - 1;
//        nxt[i] = i + 1;
//    }
//    nxt[n] = 0;  // 尾节点n的后继是0
//
//    int a, b, c;
//    while (m--) {
//        cin >> a;
//        if (a == 1) {  // 将b插入到c左侧
//            cin >> b >> c;
//            if (b == c || deleted[b]) 
//                continue;  
//            rm(b);          // 先摘除b
//            ins(pre[c], b); // 插入到c的前驱右侧（即c左侧）
//        }
//        else if (a == 2) { // 将b插入到c右侧
//            cin >> b >> c;
//            if (b == c || deleted[b])
//                continue;
//            rm(b);          // 先摘除b
//            ins(c, b);      // 直接插入到c右侧
//        }
//        else if (a == 3) { // 删除节点b
//            cin >> b;
//            if (deleted[b]) continue;
//            rm(b);              // 摘除b
//            deleted[b] = true;  // 标记永久删除
//        }
//    }
//
//    // 从虚拟头节点0的后继开始（解决空链表/头节点删除问题）
//    int cur = nxt[0];
//    if (cur == 0) {
//        cout << "Empty!" << endl;
//    }
//    else {
//        while (cur != 0) {
//            cout << cur << " ";
//            cur = nxt[cur];
//        }
//        cout << endl;
//    }
//
//    return 0;
//}