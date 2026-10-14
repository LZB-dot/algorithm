//#include<iostream>
//#include<vector>
//#include<unordered_set>
//#include<climits>
//#include<bit>
//using namespace std;
//
//class Solution {
//public:
//    int findMaximumXOR(vector<int>& nums) {
//        int mx = INT_MIN;
//        for (int num : nums)
//            mx = max(mx, num);//确定处理的最高位
//        int high;
//        if (mx == 0)
//            high = 0;
//        else
//            high = 31 - __builtin_clz(mx);//去除前导0
//        int ans = 0;//保存当前确定的最大异或值
//        unordered_set<int>set;//存储处理后的数字
//        for (int i = high; i >= 0; --i)//从高位到低位
//        {
//            int better = ans | (1 << i);//构建最优解，将第i位设为1
//            set.clear();
//            for (int num : nums)
//            {
//                int n = (num >> i) << i;//保留当前位和更高位的信息，低位清零
//                set.insert(n);//存入哈希集合
//                if (set.count(better ^ n))//a^b=c，那么 a^c=b
//                {
//                    ans = better;
//                    break;
//                }
//            }
//        }
//        return ans;
//    }
//};