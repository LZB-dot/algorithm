//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//
//class Solution {
//private:
//    int limit;
//    int ans = 0;
//
//    //col:之前皇后列的影响
//    //left:右上到左下
//    //right:左上到右下
//    void digui(int limit, int col, int left, int right) {
//        if (col == limit) {
//            ans++;
//        }
//        //把限制集合起来，当前是1的位置不能放
//        //但是前面还有很多个0，会影响判断
//        int ban = col | left | right;
//        //与全为1的答案&，反过来了，即现在是1能放皇后
//        int cur = limit & (~ban);
//        //放置皇后的尝试
//        int tmp = 0;
//        while (cur != 0) {
//            tmp = cur & (-cur);//让tmp只保留末尾的1，进行尝试
//            cur ^= tmp;//去除末尾1
//            //把tmp的1添加进答案进行下一列尝试
//            //左移即left的下一列限制
//            //右移即right的下一列限制
//            digui(limit, col | tmp, (left | tmp) << 1, (right | tmp) >> 1);
//        }
//    }
//
//public:
//    int totalNQueens(int n) {
//        if (n <= 0)
//            return ans;
//        limit = (1 << n) - 1;
//        digui(limit, 0, 0, 0);
//        return ans;
//    }
//};