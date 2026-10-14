//#include<iostream>
//#include<stack>
//#include<climits>
//using namespace std;
//
////返回栈的深度
//int deep(stack<int>& s) {
//    if (s.empty())
//        return 0;
//    else {
//        int tmp = s.top();
//        s.pop();
//        int ans = 1 + deep(s);
//        s.push(tmp);
//        return ans;
//    }
//}
//
////返回从上往下数deep层的最大值
//int maxVal(stack<int>& s, int deep) {
//    if (s.empty() || deep == 0) {
//        return INT_MIN;
//    }
//    int tmp = s.top();
//    s.pop();
//    int ans = max(tmp, maxVal(s, deep - 1));
//    s.push(tmp);
//    return ans;
//}
//
////返回从上往下数deep层最大值mx出现的次数
//int times(stack<int>& s, int deep, int mx) {
//    if (s.empty() || deep == 0) {
//        return 0;
//    }
//    int tmp = s.top();
//    s.pop();
//    int ans = times(s, deep - 1, mx);
//    if (tmp == mx) {
//        ans += 1;
//    }
//    s.push(tmp);
//    return ans;
//}
//
////把deep层中k个mx元素沉底
//void down(stack<int>& s, int deep, int mx, int k) {
//    if (deep == 0) {
//        for (int i = 0; i < k; ++i) {
//            s.push(mx);
//        }
//        return;
//    }
//
//    int tmp = s.top();
//    s.pop();
//    down(s, deep - 1, mx, k);
//    if (tmp != mx) {
//        s.push(tmp);
//    }
//    return;
//}
//
//void sort(stack<int>& s) {
//    int d = deep(s);
//    while (d > 0) {
//        int curMax = maxVal(s, d);
//        int count = times(s, d, curMax);
//        down(s, d, curMax, count);
//        d -= count;
//    }
//}
//
//// 测试函数
//int main() {
//    stack<int> s;
//    // 测试用例：入栈顺序为3,1,2,5,4（栈顶到栈底为4,5,2,1,3）
//    s.push(3);
//    s.push(1);
//    s.push(2);
//    s.push(5);
//    s.push(4);
//
//    sort(s);
//
//    // 输出排序结果（应从栈顶到栈底为1,2,3,4,5）
//    cout << "排序后栈顶到栈底元素：";
//    while (!s.empty()) {
//        cout << s.top() << " ";
//        s.pop();
//    }
//    return 0;
//}
