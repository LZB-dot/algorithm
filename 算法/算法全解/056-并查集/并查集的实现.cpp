//
////并查集的两个优化点
////路径压缩
////按大小（秩）合并
//
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//const int MAXN = 1e6 + 1;
//int father[MAXN];//存储父节点
//int size_[MAXN];//存储每个集合大小
//int stack[MAXN];//用于路径压缩的辅助栈
//int n, m;//n元素总数，m操作个数
//
////初始化
//void build() {
//	for (int i = 0; i <= n; ++i) {
//		father[i] = i;//每个节点父节点初始为自己，自成一个集合
//		size_[i] = 1;//初始化每个集合大小为1
//	}
//}
//
////带路径压缩的查找函数
//int find(int i) {
//	int sz = 0;
//	//从根节点开始记录路径上的整个集合
//	while (i != father[i]) {
//		stack[sz++] = i;
//		i = father[i];
//	}
//	//路径压缩将所有节点直接指向根节点
//	while (sz > 0) {
//		father[stack[--sz]] = i;
//	}
//
//	return i;
//}
//
////判断是否同个集合
//bool isSameSet(int x, int y) {
//	return find(x) == find(y);
//}
//
////合并集合
//void unionSet(int x, int y) {
//	int fx = find(x);
//	int fy = find(y);
//	if (fx != fy) {
//		//小集合合并到大集合上面，减少深度
//		if (size_[fx] >= size_[fy]) {
//			size_[fx] += size_[fy];
//			father[fy] = fx;
//		}
//		else{
//			size_[fy] += size_[fx];
//			father[fx] = fy;
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	cin >> n >> m;
//	build();
//	while (m--) {
//		int opt, x, y;
//		cin >> opt >> x >> y;
//		if (opt == 1) {
//			cout << (isSameSet(x, y) ? "Yes" : "No") << endl;
//		}
//		else if (opt == 2) {
//			unionSet(x, y);
//		}
//	}
//	return 0;
//}
