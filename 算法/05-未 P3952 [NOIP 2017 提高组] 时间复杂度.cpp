//#include<iostream>
//#include<vector>
//#include<unordered_set>
//#include<stack>
//#include<string>
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int T;
//	cin >> T;
//	// 新增：忽略cin后的换行符，避免getline读空行（解决输入输出混行问题）
//	cin.ignore();
//	while (T--) {
//		unordered_set<char>used;//记录变量域，辨别是否重复
//		stack<int>pow;//记录当前幂次
//		stack<char>var;//记录变量，方便终止
//		int l;
//		string s;
//		cin >> l >> s;
//		// 新增：忽略本行剩余的换行符，避免后续getline读取错误
//		cin.ignore();
//
//		//分析复杂度--0是常数，1...是幂次
//		int tar = 0;
//		if (s != "O(1)") {
//			auto pos = s.find("^");
//			tar = stoi(s.substr(pos + 1, s.size() - pos - 2));
//		}
//
//		bool flag = false;//语法错误，1-有错误
//		int cntF = 0, cntE = 0;//F和E数量要匹配
//		int maxpower = 0;//记录全局嵌套幂次
//		int curpower = 0;//记录当前嵌套幂次
//
//		for (int i = 0; i < l; ++i) {
//			// 如果已经有语法错误，跳过后续计算
//			if (flag) {
//				string tmp;
//				// 修正：用cin.ignore可能漏读，改用getline+cin同步处理
//				getline(cin, tmp);
//				continue;
//			}
//
//			char a;
//			// 修正：读取字符前先忽略可能的空白符（比如换行/空格）
//			cin >> ws;
//			cin >> a;
//
//			if (a == 'F') {
//				cntF++;
//				char b;
//				string x, y;
//				cin >> b >> x >> y;
//
//				//判断变量域是否已存在
//				if (used.count(b))
//					flag = true;
//				// 修正：即使flag为true，也要执行insert和push（保证栈结构不混乱）
//				if (!flag) {
//					used.insert(b);
//					var.push(b);
//				}
//
//				//判断是否为常数循环
//				bool cur = true;
//				// 修正：只有flag为false时才计算循环有效性（避免stoi崩溃）
//				if (!flag) {
//					if (x == "n" && y == "n") {
//						cur = true;
//					}
//					else if (x != "n" && y != "n") {
//						int t1 = stoi(x);
//						int t2 = stoi(y);
//						cur = (t1 > t2);
//					}
//					else if (x == "n" && y != "n") {
//						cur = true;
//					}
//					else {
//						cur = false;
//					}
//
//					//如果不是常数循环那么幂次加
//					int power = cur ? 0 : 1;
//					pow.push(power);
//					if (power == 1) {
//						curpower++;//嵌套参数加1
//						maxpower = max(maxpower, curpower);
//					}
//				}
//
//			}
//			else if (a == 'E') {
//				cntE++;
//				//无变量还要终止
//				if (var.empty())
//					flag = true;
//				else {
//					//销毁当前层变量
//					char cur = var.top();
//					var.pop();
//					used.erase(cur);
//					//恢复当前幂次和
//					int power = pow.top();
//					pow.pop();
//					if (power == 1)
//						curpower--;
//				}
//
//			}
//		}
//
//		if (cntF != cntE || !var.empty())
//			flag = true;
//
//		if (flag)
//			cout << "ERR\n";
//		else {
//			if (maxpower == tar)
//				cout << "Yes\n";
//			else
//				cout << "No\n";
//		}
//	}
//
//	return 0;
//}