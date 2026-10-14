//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
////s1+s2
//vector<int> add(const string& s1, const string& s2) {
//    int n = s1.size();
//    int m = s2.size();
//    int i = n - 1, j = m - 1;
//    int carry = 0;
//    vector<int> ans;
//
//    while (i >= 0 || j >= 0 || carry) {
//        int cur = carry;
//
//        if (i >= 0)
//            cur += s1[i--] - '0';
//        if (j >= 0)
//            cur += s2[j--] - '0';
//
//        ans.push_back(cur % 10);
//        carry = cur / 10;
//    }
//
//    reverse(ans.begin(), ans.end());
//    return ans;
//}
//
////先比较绝对值大小 s1 >= s2
//bool cmp(string s1, string s2) {
//    if (s1.size() != s2.size())
//        return s1.size() > s2.size();
//    return s1 >= s2;
//}
//
////s1 - s2
//vector<int> minu(string s1, string s2) {
//    bool sw = false;
//    if (!cmp(s1, s2)) {
//        swap(s1, s2);
//        sw = true;
//    }
//
//    int n = s1.size(), m = s2.size();
//    int i = n - 1, j = m - 1;
//    int borrow = 0;
//    vector<int> ans;
//
//    while (i >= 0) {
//        int cur = s1[i] - '0' - borrow;
//        borrow = 0;
//        if (j >= 0)
//            cur -= s2[j] - '0';
//
//        if (cur < 0) {
//            cur += 10;
//            borrow = 1;
//        }
//
//        ans.push_back(cur);
//        i--;
//        j--;
//    }
//
//    while (ans.size() > 1 && ans.back() == 0)
//        ans.pop_back();
//
//    reverse(ans.begin(), ans.end());
//
//    if (sw)
//        ans.insert(ans.begin(), -1);
//
//    return ans;
//}
//
//void print(vector<int> v) {
//    for (int x : v) {
//        if (x == -1)
//            cout << "-";
//        else
//            cout << x;
//    }
//    cout << "\n";
//}
//
//int main() {
//    string s1, s2;
//    cin >> s1 >> s2;
//
//    cout << "和：";
//    print(add(s1, s2));
//
//    cout << "差：";
//    print(minu(s1, s2));
//
//    return 0;
//}