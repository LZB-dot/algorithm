//#include<iostream>
//#include<queue>
//using namespace std;
//
//class Solution {
//public:
//    int halveArray(vector<int>& nums) {
//        priority_queue<double, vector<double>>pq;
//        double sum = 0.0;
//        for (int i : nums)
//        {
//            pq.push(i);
//            sum += i;
//        }
//        sum /= 2;
//        int ans = 0;
//        for (double temp = 0.0, cur; temp < sum; temp += cur)
//        {
//            cur = pq.top() / 2;
//            pq.pop();
//            pq.push(cur);
//            ans++;
//        }
//        return ans;
//    }
//};