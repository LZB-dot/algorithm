//#include<iostream>
//#include<stack>
//
//using namespace std;
//
////移除并返回栈底元素
//int bottomOut(stack<int>&s) {
//	int ans = s.top();
//	s.pop();
//	if (s.empty())
//		return ans;
//	else {
//		int bottom = bottomOut(s);
//		s.push(ans);
//		return bottom;
//	}
//}
//
//void reverse(stack<int>&s) {
//	if (s.empty())
//		return;
//
//	int bottom = bottomOut(s);
//	reverse(s);
//	s.push(bottom);
//}
//
//// 测试代码
//int main() {
//    stack<int> s;
//    // 压入元素 1,2,3,4,5（栈顶为5）
//    for (int i = 1; i <= 5; ++i) {
//        s.push(i);
//    }
//
//    reverse(s);  // 逆序栈
//
//    // 输出逆序后的栈（应从栈顶到栈底为1,2,3,4,5）
//    cout << "逆序后的栈元素（从栈顶到栈底）：";
//    while (!s.empty()) {
//        cout << s.top() << " ";
//        s.pop();
//    }
//    // 输出结果应为：1 2 3 4 5
//    return 0;
//}