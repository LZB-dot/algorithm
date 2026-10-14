////
//////贪心核心：学会对数期验证思维正确与否
////
////#include<iostream>
////#include<vector>
////#include<algorithm>
////using namespace std;
////
////
////void f(vector<string>& res,int n, int i, vector<string>&nums) {
////    if (i == n) {
////        string ans = "";
////        for (const auto& s : nums)
////            ans += s;
////        res.push_back(ans);
////        return;
////    }
////
////    for (int k = i; k < n; ++k) {
////        swap(nums[i], nums[k]);
////        f(res, n, i + 1, nums);
////        swap(nums[i], nums[k]);
////    }
////
////}
////
////string way1 (vector<string> nums) {
////    int n = nums.size();
////    if (n == 0)
////        return "";
////
////    vector<string>res;
////    f(res, n, 0, nums);
////    sort(res.begin(), res.end());
////    return res[0];
////}
////
////bool compare(string s1, string s2) {
////    return s1 + s2 < s2 + s1;
////}
////
////string way2(vector<string> nums) {
////    int n = nums.size();
////    if (n == 0)
////        return "";
////    sort(nums.begin(), nums.end(), compare);
////    string res = "";
////    for (const auto& s : nums)
////        res += s;
////    return res;
////}
////
////vector<string> randomArray(int n, int len, int cnt) {
////    vector<string>s;
////
////    //字符串个数
////    for (int i = 0; i < n; ++i) {
////        int l = rand() % len + 1;//随机长度1 -- len
////        string tmp = "";
////        for (int j = 0; j < l; ++j) {
////            char c = 'a' + rand() % cnt;//随机字符a -- a+cnt-1
////            tmp += c;
////        }
////        s.push_back(tmp);
////    }
////
////    return s;
////}
////
////void print(const vector<string>& arr) {
////    for (const string& s : arr) {
////        cout << s << ",";
////    }
////    cout << endl;
////}
////
////
////int main() {
////    srand((unsigned)time(0));
////    cout << "开始测试" << endl;
////    for (int i = 1; i <= 1000; ++i) {
////        vector<string>input = randomArray(5, 4, 3);
////        string ans1 = way1(input);
////        string ans2 = way2(input);
////        if (ans1 != ans2) {
////            cout << "错误" << endl;
////            print(input);
////            cout << ans1 << endl;
////            cout << ans2 << endl;
////        }
////
////        if (i % 100 == 0)
////            cout << "第" << i << "组全部通过" << endl;
////    }
////
////    return 0;
////}
////
////
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//    string largestNumber(vector<int>& nums) {
//        vector<string> strs;
//        for (int num : nums) {
//            strs.push_back(to_string(num));
//        }
//
//        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
//            return a + b > b + a;
//            });
//
//        // 拼接结果
//        string res;
//        for (const string& s : strs) {
//            res += s;
//        }
//        if (res[0] == '0') {
//            return "0";
//        }
//
//        return res;
//    }
//};
