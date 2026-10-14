//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> singleNumber(vector<int>& nums) {
//        int a = 0;
//        for (int i : nums) {
//            a ^= i;
//        }
//        // 使用无符号类型来避免否定最小值时的未定义行为
//        //a&-a得到只有第一次出现1的位置为1，其余均为0的二进制数
//        //1001&(-1001)
//        //-1001=0110+1=0111
//        //0001
//        int firstOne = a & (-(unsigned int)a);
//        //说明答案两个数在这一位一个为0，一个为1
//        int b = 0;
//        for (int i : nums) {
//            if ((i & firstOne) == 0)
//                b ^= i;
//        }
//
//        vector<int>ans(2);
//        ans[0] = b;
//        ans[1] = a ^ b;
//        return ans;
//    }
//};