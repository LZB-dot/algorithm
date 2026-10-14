//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//string mul(string a, string b) {
//    if (a == "0" || b == "0")
//        return "0";
//
//    reverse(a.begin(), a.end());
//    reverse(b.begin(), b.end());
//
//    vector<int>res(a.size() + b.size(), 0);
//
//    for (int i = 0; i < a.size(); ++i) {
//        for (int j = 0; j < b.size(); ++j) {
//            int tmp = (a[i] - '0') * (b[j] - '0');
//            res[i + j] += tmp;
//            res[i + j + 1] += res[i + j] / 10;
//            res[i + j] %= 10;
//        }
//    }
//
//    string ans;
//    int i = res.size() - 1;
//    while (i >= 0 && res[i] == 0)
//        --i;
//    
//    while (i >= 0) {
//        ans.push_back(res[i] + '0');
//        --i;
//    }
//
//    return ans;
//}
//
//int lastZero(string s) {
//    string num = s;
//    int k = 0;
//    while (num.back() == '0') {
//        ++k;
//        num.pop_back();
//    }
//    return k;
//}
//
//int countThree(string num) {
//    int count = 0;
//    string n = num;
//
//    while (true) {
//        int remain = 0; 
//        string s;
//
//        for (char c : n) {
//            int tmp = c - '0';
//            int cur = remain * 10 + tmp; 
//            s.push_back((cur / 3) + '0'); 
//            remain = cur % 3;
//        }
//
//        if (remain != 0) 
//            break;  
//
//        count++; 
//
//        // 处理商：移除前面的0（例如"00123"变为"123"）
//        size_t firstNonZero = s.find_first_not_of('0');
//        if (firstNonZero == string::npos) {
//            n = "0";  // 如果商全是0，则结果为0
//        }
//        else {
//            n = s.substr(firstNonZero);  // 截取从第一个非0字符开始的子串
//        }
//
//        if (n == "0")
//            break;
//    }
//
//    return count;  // 返回质因数p的总个数
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//    string x1, x2;
//    cin >> x1;
//
//    for (int i = 1; i < n; ++i) {
//        cin >> x2;
//        x1 = mul(x1, x2);
//    }
//
//    cout << min(lastZero(x1), countThree(x1)) << endl;
//
//
//    return 0;
//}