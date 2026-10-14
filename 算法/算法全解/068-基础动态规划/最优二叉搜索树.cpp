//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX 100
//
//// 函数用于构建最优二叉搜索树
//void optimalBST(double p[], int n) {
//    // e[i][j] 存储包含键 i 到 j 的最优二叉搜索树的期望搜索代价
//    double e[MAX][MAX];
//    // w[i][j] 存储包含键 i 到 j 的子树的概率总和
//    double w[MAX][MAX];
//    // root[i][j] 存储包含键 i 到 j 的最优二叉搜索树的根节点
//    int root[MAX][MAX];
//
//    // 初始化 e 和 w 数组，对于单个键的情况
//    for (int i = 1; i <= n + 1; i++) {
//        // 当子树中没有键时，期望搜索代价为 0
//        e[i][i - 1] = 0;
//        // 当子树中没有键时，概率总和为 0
//        w[i][i - 1] = 0;
//    }
//
//    // 考虑不同长度的子树，从长度为 1 开始逐步增加
//    for (int l = 1; l <= n; l++) {
//        for (int i = 1; i <= n - l + 1; i++) {
//            int j = i + l - 1;  // 修正 j 的计算
//            // 初始化期望搜索代价为一个足够大的值
//            e[i][j] = 999999;
//            // 计算包含键 i 到 j 的子树的概率总和
//            w[i][j] = w[i][j - 1] + p[j - 1];
//
//            // 尝试所有可能的根节点 k
//            for (int k = i; k <= j; k++) {
//                // 计算以 k 为根节点的期望搜索代价
//                double t = e[i][k - 1] + e[k + 1][j] + w[i][j];
//                // 如果以 k 为根节点的期望搜索代价更小，则更新 e[i][j] 和 root[i][j]
//                if (t < e[i][j]) {
//                    e[i][j] = t;
//                    root[i][j] = k;
//                }
//            }
//        }
//    }
//
//    // 输出最优二叉搜索树的期望搜索代价
//    printf("最优二叉搜索树的期望搜索代价: %.2f\n", e[1][n]);
//}
//
//int main() {
//    // 示例：假设有 4 个键，每个键的搜索概率如下
//    double p[] = { 0.15, 0.1, 0.05, 0.1 };
//    int n = sizeof(p) / sizeof(p[0]);
//
//    // 调用 optimalBST 函数构建最优二叉搜索树
//    optimalBST(p, n);
//
//    return 0;
//}