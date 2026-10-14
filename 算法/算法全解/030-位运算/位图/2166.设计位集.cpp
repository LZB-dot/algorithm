//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//class Bitset {
//private:
//    vector<int>bits;//存储位的整数数组，每个整数表示32个
//    int size;//位集合的总大小
//    int zeros;//0的数量
//    int ones;//1的数量
//    bool reverse;//是否反转
//public:
//    Bitset(int n) {
//        bits.resize((n + 31) / 32, 0);
//        this->size = n;
//        zeros = n;
//        ones = 0;
//        reverse = false;
//    }
//
//    void fix(int i) {
//        int index = i / 32;
//        int bit = i % 32;
//        if (!reverse) {
//            if ((bits[index] & (1 << bit)) == 0) {
//                zeros--;
//                ones++;
//                bits[index] |= (1 << bit);
//            }
//        }
//        else {
//            //反转状态：此时该位是反转后的，要设置1即设计0
//            if ((bits[index] & (1 << bit)) != 0) {
//                zeros--;
//                ones++;
//                bits[index] ^= (1 << bit);
//            }
//        }
//    }
//
//    void unfix(int i) {
//        int index = i / 32;
//        int bit = i % 32;
//        if (!reverse) {
//            if ((bits[index] & (1 << bit)) != 0) {
//                ones--;
//                zeros++;
//                bits[index] ^= (1 << bit);
//            }
//        }
//        else {
//            // 反转状态：要设置为0需要实际位是1
//            if ((bits[index] & (1 << bit)) == 0) {
//                ones--;
//                zeros++;
//                bits[index] |= (1 << bit);  // 设置为1（反转后显示为0）
//            }
//        }
//    }
//
//    void flip() {
//        reverse = !reverse;
//        swap(zeros, ones);
//    }
//
//    bool all() {
//        return ones == size;
//    }
//
//    bool one() {
//        return ones > 0;
//    }
//
//    int count() {
//        return ones;
//    }
//
//    string toString() {
//        string s;
//        for (int i = 0, k = 0; i < size; ++k) {
//            int num = bits[k];
//            for (int j = 0; j < 32 && i < size; ++j, ++i) {
//                int sta = (num >> j) & 1;
//                sta ^= reverse ? 1 : 0;
//                s += (char)('0' + sta);
//            }
//        }
//        return s;
//    }
//};