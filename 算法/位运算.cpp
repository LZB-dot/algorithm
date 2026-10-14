//#include<iostream>
//#include<bitset>
//using namespace std;
//
//int main()
//{
//
//	//~取反
//	int a = 8;
//	cout << a << endl;
//	cout << ~a << endl;
//	cout << ~a + 1 << endl;//取反 +1得到相反数
//
//	int b = -12;
//	cout << b << endl;
//	cout << ~b << endl;
//	cout << ~b + 1 << endl;//取反 +1得到相反数
//
//	//有符号int long 的最小数的相反数，绝对值都是它自己
//	//因为负数的最小值，在正数没有与之对应的数
//	cout << endl;
//	int c = 0b00001010;
//	int d = 0b00001100;
//	cout << bitset<32>(c | d) << endl;//或：有1为1
//	cout << bitset<32>(c & d) << endl;//与：都为1才为1
//	cout << bitset<32>(c ^ d) << endl;//异或：相同则为0，不同才为1
//
//	cout << endl;
//	int e = 18;
//	cout << (e << 1) << endl;
//	cout << (e << 2) << endl;
//	cout << (e >> 1) << endl;
//	cout << (e >> 2) << endl;
//	//对正数：<<1（乘以2）		<<2（乘以4） 
//	//		  >>1（除以2）		>>2（除以4）
//
//	cout << endl;
//	 e = -18;
//	cout << (e << 1) << endl;
//	cout << (e << 2) << endl;
//	cout << (e >> 1) << endl;
//	cout << (e >> 2) << endl;
//	//对负数：>>一样，向下取整
//	//		  <<会有溢出风险，符号位可能被移掉
//	return 0;
//}