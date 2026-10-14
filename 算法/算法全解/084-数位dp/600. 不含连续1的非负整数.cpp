//
//
//class Solution {
//private:
//    vector<int> cnt;//统计i位中没有连续1的数字数
//
//    void Init() {
//        cnt.resize(31, 0);
//        cnt[0] = 1;
//        cnt[1] = 2;
//        for (int i = 2; i < 31; ++i) {
//            cnt[i] = cnt[i - 2] + cnt[i - 1];
//        }
//    }
//    //从最高位开始
//    int f(int n, int i) {
//        if (i == -1)
//            return 1;
//        int ans = 0;
//        //如果最大数当前位为1，则当前位可以主动取0
//        if ((n & (1 << i)) != 0) {
//            ans += cnt[i];
//            //如果最大数上一位还是1，则结束
//            if ((n & (1 << (i + 1)))) {
//                return ans;
//            }
//        }
//        //加上当前位为1的情况
//        ans += f(n, i - 1);
//        return ans;
//    }
//public:
//    int findIntegers(int n) {
//        Init();
//        return f(n, 30);
//    }
//};