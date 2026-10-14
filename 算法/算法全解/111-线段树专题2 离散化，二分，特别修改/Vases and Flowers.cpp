//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 50005;
//
//int sum[MAXN << 2];    // 区间有花数量
//int change[MAXN << 2]; // 懒标记值
//bool update[MAXN << 2];// 懒标记是否生效
//int n;                 // 瓶子总数
//
//// 向上合并
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//
//// 打懒标记：v=0清空，v=1插花
//void lazy(int i, int v, int n) {
//	sum[i] = v * n;         // 区间和 = 值 * 长度
//	change[i] = v;
//	update[i] = true;
//}
//
//// 懒标记下传
//void down(int i, int ln, int rn) {
//	if (update[i]) {
//		lazy(i << 1, change[i], ln);
//		lazy(i << 1 | 1, change[i], rn);
//		update[i] = false;
//	}
//}
//
//// 建树：初始全空
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = 0;
//	}
//	else {
//		int mid = (l + r) >> 1;  // 修复：正确求mid
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	update[i] = false;
//	change[i] = 0;
//}
//
//// 区间更新
//void updateRange(int jobl, int jobr, int jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr) {
//		lazy(i, jobv, r - l + 1);
//	}
//	else {
//		int mid = (l + r) >> 1;  // 修复
//		down(i, mid - l + 1, r - mid);
//		if (jobl <= mid)
//			updateRange(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			updateRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//}
//
//// 区间查询有多少花
//int query(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr) {
//		return sum[i];
//	}
//	int mid = (l + r) >> 1;
//	down(i, mid - l + 1, r - mid);
//	int ans = 0;
//	if (jobl <= mid)
//		ans += query(jobl, jobr, l, mid, i << 1);
//	if (jobr > mid)
//		ans += query(jobl, jobr, mid + 1, r, i << 1 | 1);
//	return ans;
//}
//
//// 二分找 s~n 中第 k 个空瓶子（0）
//int findZero(int s, int k) {
//	int l = s, r = n, mid, ans = 0;
//	while (l <= r) {
//		mid = (l + r) >> 1;
//		int cnt = mid - s + 1 - query(s, mid, 1, n, 1);
//		if (cnt >= k) {
//			ans = mid;
//			r = mid - 1;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//	return ans;
//}
//
//// 插花操作：返回{第一个位置，最后一个位置}
//pair<int, int> insert(int from, int flowers) {
//	from++; // 题目0下标 → 线段树1下标
//	int start, end;
//	int totalZero = n - from + 1 - query(from, n, 1, n, 1);
//
//	if (totalZero == 0) {
//		start = -1;
//		end = -1;
//	}
//	else {
//		start = findZero(from, 1);
//		end = findZero(from, min(totalZero, flowers));
//		updateRange(start, end, 1, 1, n, 1);
//	}
//
//	start--; // 转回0下标
//	end--;
//	return { start, end };
//}
//
//// 清空操作
//int clearRange(int left, int right) {
//	left++;
//	right++;
//	int ans = query(left, right, 1, n, 1);
//	updateRange(left, right, 0, 1, n, 1);
//	return ans;
//}
//
//void solve() {
//	int m;
//	cin >> n >> m;
//	build(1, n, 1); // 初始化线段树
//
//	while (m--) {
//		int op;
//		cin >> op;
//		if (op == 1) {
//			int from, flower;
//			cin >> from >> flower;
//			auto it = insert(from, flower);
//			int st = it.first;
//			int ed = it.second;
//			if (st <0) {
//				cout << "Can not put any one.\n";
//			}
//			else {
//				cout << st << " " << ed << "\n";
//			}
//		}
//		else {
//			int l, r;
//			cin >> l >> r;
//			cout << clearRange(l, r) << "\n";
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//
//	return 0;
//}