//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//    int numRabbits(vector<int>& answers) {
//        sort(answers.begin(), answers.end());
//        int n = answers.size();
//        int ans = 0;
//        int cnt = 0;
//        for (int i = 0; i < n;) {  
//            int x = answers[i];
//            cnt = 0; 
//            while (i < n && answers[i] == x) {
//                cnt++;
//                i++; 
//            }
//            // 向上取整
//            ans += (cnt + x) / (x + 1) * (x + 1);
//        }
//        return ans;
//    }
//};
