//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define N 100 // 物品的最大数量
//#define C 100 // 背包的最大容量
//
//// 物品结构体，包含重量和价值
//typedef struct {
//    int weight;
//    int value;
//} Item;
//
//// 比较函数，用于qsort排序，按单位重量价值从高到低排序
//int compare(const void* a, const void* b) {
//    Item* item1 = (Item*)a;
//    Item* item2 = (Item*)b;
//    double ratio1 = (double)item1->value / item1->weight;
//    double ratio2 = (double)item2->value / item2->weight;
//    if (ratio1 < ratio2) return 1;
//    else if (ratio1 > ratio2) return -1;
//    return 0;
//}
//
//// 限界函数，计算上界
//double Bound(int i, Item items[], int n, int c, int cw, int cp) {
//    double cleft = c - cw; // 剩余容量，cw当前在背包中物品重量
//    double b = cp;        // cp当前在背包中物品价值
//    // 以物品单位重量价值递减序装入物品
//    while (i < n && items[i].weight <= cleft) {
//        cleft -= items[i].weight;
//        b += items[i].value;
//        i++;
//    }
//    // 装满背包
//    if (i < n) b += (double)items[i].value / items[i].weight * cleft;
//    return b;
//}
//
//// 回溯函数
//void Backtrack(int i, Item items[], int n, int c, int* cw, int* cp, int* bestp) {
//    if (i >= n) { // 到达叶节点
//        if (*cp > *bestp) {
//            *bestp = *cp;
//        }
//        return;
//    }
//    // 进入左子树（选择该物品）
//    if (*cw + items[i].weight <= c) {
//        *cw += items[i].weight;
//        *cp += items[i].value;
//        Backtrack(i + 1, items, n, c, cw, cp, bestp);
//        *cw -= items[i].weight;
//        *cp -= items[i].value;
//    }
//    // 进入右子树（不选择该物品）
//    if (Bound(i + 1, items, n, c, *cw, *cp) > *bestp) {
//        Backtrack(i + 1, items, n, c, cw, cp, bestp);
//    }
//}
//
//int main() {
//    Item items[N];
//    int n; // 物品数量
//    int c; // 背包容量
//    printf("请输入物品数量: ");
//    scanf("%d", &n);
//    printf("请输入背包容量: ");
//    scanf("%d", &c);
//    printf("请依次输入每个物品的重量和价值:\n");
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d", &items[i].weight, &items[i].value);
//    }
//    // 按单位重量价值从高到低排序
//    qsort(items, n, sizeof(Item), compare);
//    int cw = 0; // 当前重量
//    int cp = 0; // 当前价值
//    int bestp = 0; // 最优价值
//    Backtrack(0, items, n, c, &cw, &cp, &bestp);
//    printf("背包能装下的最大价值是: %d\n", bestp);
//    return 0;
//}