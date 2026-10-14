//#include<iostream>
//#include<vector>
//#include<set>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
//        int rows = matrix.size();
//        int cols = matrix[0].size();
//        int maxSum = INT_MIN;
//        //规定左右列边界
//        for (int left = 0; left < cols; ++left) {
//            //第i行[left,right]的和
//            vector<int>rowSum(rows, 0);
//            for (int right = left; right < cols; ++right) {
//                //计算每一行区间和，每次会依次叠加上一次的
//                for (int i = 0; i < rows; ++i) {
//                    rowSum[i] += matrix[i][right];
//                }
//
//                //在rowSum中找不超过k的最大子数组和
//                set<int>prefix;//存储前缀和的有序集合
//                prefix.insert(0);//初始化为0
//
//                int cur = 0;//当前前缀和，即前i行的累加和
//                for (int sum : rowSum) {
//                    cur += sum;//前i行的和
//                    //查找第一个大于等于目标的元素
//                    //找到最小的pre使得cur-pre<=k，中间这个区间即为目标区间
//                    auto it = prefix.lower_bound(cur - k);
//                    if (it != prefix.end()) {
//                        maxSum = max(maxSum, cur - *it);
//                    }
//                    prefix.insert(cur);
//                }
//            }
//        }
//        return maxSum;
//    }
//};