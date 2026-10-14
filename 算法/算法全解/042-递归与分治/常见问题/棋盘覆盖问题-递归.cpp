//#define _CRT_SECURE_NO_WARNINGS 1

//三种方案覆盖图案不同，栈时间最短，队列时间最长

//#include<iostream>
//using namespace std;
//#define N 16
//int board[N][N] = { 0 };
//int L = 1; // L型棋子编号
//
//void BoardCover(int sx, int sy, int tx, int ty, int size)
//{
//    // sx,sy是当前棋盘的左上角坐标
//    // tx,ty是特殊坐标
//    if (size == 1)
//        return;
//    int cur = L++;// 使用当前编号的L型棋子
//    int s = size >> 1;//子问题规模
//
//    //左上角
//    if (tx < sx + s && ty < sy + s)
//        BoardCover(sx, sy, tx, ty, s);
//    else
//    {
//        board[sx + s - 1][sy + s - 1] = cur;
//        BoardCover(sx, sy, sx + s - 1, sy + s - 1, s);
//    }
//
//    //右上角
//    if (tx < sx + s && ty >= sy + s)
//        BoardCover(sx, sy + s, tx, ty, s);
//    else
//    {
//        board[sx + s - 1][sy + s] = cur;
//        BoardCover(sx, sy + s, sx + s - 1, sy + s, s);
//    }
//
//    //左下角
//    if (tx >= sx + s && ty < sy + s)
//        BoardCover(sx + s, sy, tx, ty, s);
//    else
//    {
//        board[sx + s][sy + s - 1] = cur;
//        BoardCover(sx + s, sy, sx + s, sy + s - 1, s);
//    }
//
//    //右下角
//    if (tx >= sx + s && ty >= sy + s)
//        BoardCover(sx + s, sy + s, tx, ty, s);
//    else
//    {
//        board[sx + s][sy + s ] = cur;
//        BoardCover(sx + s, sy + s, sx + s, sy + s ,s);
//    }
//}
//
//int main() 
//{
//    int k = 4; // 4次方
//    int size = 1 << 4; // 计算2的k次幂
//    int x = 1, y = 1; // 特殊位置
//    BoardCover(0, 0, x, y, size);
//    for (int i = 0; i < size; i++) 
//    {
//        for (int j = 0; j < size; j++)
//            printf("%3d", board[i][j]);
//        cout << endl;
//    }
//    return 0;
//}