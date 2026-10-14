//#include<iostream>
//#include<stack>
//using namespace std;
//
//struct Board {
//    int sx, sy;//左上角坐标
//    int tx, ty;//特殊点坐标
//    int size;//棋盘规模
//};
//
//stack<Board>st;
//#define N 16
//int board[N][N] = { 0 }; // 初始化棋盘为0
//int L = 1;
//
//void BoardCover(int sx, int sy, int tx, int ty, int size)
//{
//    st.push({ sx,sy,tx,ty,size });
//    while (!st.empty())
//    {
//        // 先取出队首元素并弹出
//        Board curr = st.top();
//        st.pop();
//
//        int sx = curr.sx;
//        int sy = curr.sy;
//        int tx = curr.tx;
//        int ty = curr.ty;
//        int size = curr.size;
//
//        // 若当前棋盘大小为1，无需处理
//        if (size == 1)
//            continue;
//
//        int s = size >> 1; // 子棋盘大小
//        int cur = L++;
//
//        // 左上角
//        if (tx < sx + s && ty < sy + s)
//            st.push({ sx, sy, tx, ty, s });
//        else
//        {
//            board[sx + s - 1][sy + s - 1] = cur;
//            st.push({ sx, sy, sx + s - 1, sy + s - 1, s });
//        }
//
//        // 右上角
//        if (tx < sx + s && ty >= sy + s)
//            st.push({ sx, sy + s, tx, ty, s });
//        else
//        {
//            board[sx + s - 1][sy + s] = cur;
//            st.push({ sx, sy + s, sx + s - 1, sy + s, s });
//        }
//
//        // 左下角
//        if (tx >= sx + s && ty < sy + s)
//            st.push({ sx + s, sy, tx, ty, s });
//        else
//        {
//            board[sx + s][sy + s - 1] = cur;
//            st.push({ sx + s, sy, sx + s, sy + s - 1, s });
//        }
//
//        // 右下角
//        if (tx >= sx + s && ty >= sy + s)
//            st.push({ sx + s, sy + s, tx, ty, s });
//        else
//        {
//            board[sx + s][sy + s] = cur;
//            st.push({ sx + s, sy + s, sx + s, sy + s, s });
//        }
//    }
//}
//
//int main()
//{
//    int k = 4; // 4次方
//    int size = 1 << 4; // 计算2的k次幂
//    int x = 1, y = 1; // 特殊位置
//    board[x][y] = 0; // 标记特殊位置
//    BoardCover(0, 0, x, y, size);
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//            printf("%3d", board[i][j]);
//        cout << endl;
//    }
//    return 0;
//}