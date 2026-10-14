//#include<iostream>
//using namespace std;
//
//class Bitset {
//private:
//    int* set;
//    int size;  // 记录bitset能容纳的最大位数
//    int arrSize;  // 记录数组的大小
//
//public:
//    // 构造函数
//    Bitset(int n) {
//        size = n;
//        arrSize = (n + 31) / 32;
//        set = new int[arrSize]();  // 初始化所有位为0
//    }
//
//    // 析构函数，自动释放内存
//    ~Bitset() {
//        delete[] set;
//    }
//
//    // 添加位，先检查边界
//    void add(int n) {
//        set[n / 32] |= (1 << (n % 32));
//    }
//
//    // 移除位
//    void remove(int n) {
//        set[n / 32] &= ~(1 << (n % 32));
//    }
//
//    // 反转位
//    void reverse(int n) {
//        set[n / 32] ^= (1 << (n % 32));
//    }
//
//    // 检查是否包含某位
//    bool contains(int n) {
//        return ((set[n / 32] >> (n % 32)) & 1) == 1;
//    }
//};
