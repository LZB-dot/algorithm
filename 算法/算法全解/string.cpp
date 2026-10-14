//#include<iostream>
//#include<string>
//#include<climits>
//#include<algorithm>
//using namespace std;
//
//
//int main() {
//
//	string s;
//	//预开辟100000字节，s.size()还是0
//	s.reserve(100000);
//
//	int n;
//	cin >> n;
//	//如果前面有用cin,需要使用ignore清空整行缓存区
//	cin.ignore(INT_MAX, '\n');
//	//读取带有空格的一行字符串
//	getline(cin, s);
//
//	char a = s.front();
//	char b = s.back();
//
//	s.push_back('a');
//	s.append("abc");
//	s += "abc";
//
//	string t = "hello";
//	if (s.find(t) == string::npos)
//		cout << "没找到\n";
//	else {
//		auto p = s.find(t);//在s字符串里面找到t的开头
//		cout << p << "\n";
//	}
//
//
//	//从下标2开始取5个字符
//	string sub = s.substr(2, 5);
//	//截取从下标2到末尾
//	sub = s.substr(2);
//
//	//从下标2开始删除3个字符
//	s.erase(2, 3);
//	
//	//从下标2开始的3个字符替换为hello,world
//	s.replace(2, 3, "hello,world");
//
//	//在下标2插入字符串
//	s.insert(2, "abc");
//
//	reverse(s.begin(), s.end());
//
//	//清空字符串
//	s.clear();
//
//	int num = 100;
//	s = to_string(num);//数字转字符串
//
//	int x = stoi(s);//字符串转int
//	double y = stod(s);//字符串转double
//	long long z = stoll(s);//字符串转long long
//
//	for (char& c : s) {
//		c = toupper(c);//转大写
//		c = tolower(c);//转小写
//	}
//
//	char d = 'a';
//	if (isdigit(d))
//		cout << "数字\n";
//	else if (isalpha(d))
//		cout << "字母\n";
//	else if (isalnum(d))
//		cout << "字母或数字\n";
//	else if (isspace(d))
//		cout << "空格，换行，制表符\n";
//
//
//	return 0;
//}