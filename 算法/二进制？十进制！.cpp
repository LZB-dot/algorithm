//#include <iostream>
//#include <string>
//#include <algorithm> // 用于反转字符串
//using namespace std;
//
//int main()
//{
//    int a, b;
//    cin >> a >> b;
//    string x, y;
//    if (a == 0) x = "0";
//    if (b == 0) y = "0";
//
//    while (a > 0)
//    {
//        x += (a % 2 + '0');
//        a /= 2;
//    }
//
//    while (b > 0)
//    {
//        y += (b % 2 + '0');
//        b /= 2;
//    }
//
//    int i = 0, j = 0;
//    int carry = 0;
//    string result;
//
//    while (i < x.size() || j < y.size())
//    {
//
//        int bit1 = (i < x.size()) ? (x[i] - '0') : 0;
//        int bit2 = (j < y.size()) ? (y[j] - '0') : 0;
//
//        int sum = bit1 + bit2 + carry;
//        carry = sum / 10;
//        result += (sum % 10 + '0');
//
//        i++;
//        j++;
//    }
//
//    reverse(result.begin(), result.end());
//
//    cout << result << endl;
//    return 0;
//}
