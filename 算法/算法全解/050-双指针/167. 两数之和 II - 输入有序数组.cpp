//#include<iostream>
//#include<vector>
//using namespace std;
//

//class Solution {
//public:
//    vector<int> twoSum(vector<int>& numbers, int target) 
//    {
//        vector<int>res(2);
//        int left = 0, right = numbers.size() - 1;
//        while (left < right)
//        {
//            int sum = numbers[left] + numbers[right];
//            if (sum == target)
//            {
//                res[0] = left + 1;
//                res[1] = right + 1;
//                return res;
//            }
//            else if (sum > target)
//                right--;
//            else if (sum < target)
//                left++;
//        }
//        return res;
//    }
//};