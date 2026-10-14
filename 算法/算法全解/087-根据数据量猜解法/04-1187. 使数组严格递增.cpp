//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring> 
//#include<climits>  
//using namespace std;
//
//const int N = 2010;
//
//class Solution {
//private:
//    int dp[N];
//
//    int bs(const vector<int>& a, int target) {
//        int l = 0, r = a.size() - 1;  
//        int ans = -1;
//        while (l <= r) {
//            int mid = l + ((r - l) >> 1);
//            if (a[mid] > target) {
//                ans = mid;
//                r = mid - 1;
//            }
//            else {
//                l = mid + 1;
//            }
//        }
//        return ans;
//    }
//
//    int dfs(const vector<int>& arr1, const vector<int>& arr2, int n, int i) {
//        if (i == n)
//            return 0;
//        if (dp[i] != -1)
//            return dp[i];
//
//        int pre = (i == 0) ? INT_MIN : arr1[i - 1];
//        int ans = INT_MAX;
//        int find = bs(arr2, pre);
//        int next = 0;
//
//        for (int j = i, k = 0; j <= n; ++j, ++k) {
//            if (j == n) {
//                ans = min(ans, k);
//                break;
//            }
//            else {
//                if (pre < arr1[j]) {
//                    next = dfs(arr1, arr2, n, j + 1);
//                    if (next != INT_MAX)
//                        ans = min(ans, next + k);
//                }
//                if (find != -1 && find < arr2.size()) {
//                    pre = arr2[find++];
//                }
//                else {
//                    break;
//                }
//            }
//        }
//        dp[i] = ans;
//        return dp[i];
//    }
//
//    void Init(vector<int>& a) {
//        if (a.empty()) 
//            return;  
//        sort(a.begin(), a.end());
//        int n = a.size();
//        vector<int>tmp;
//        tmp.push_back(a[0]);
//        for (int i = 1; i < n; ++i) {
//            if (a[i] != a[i - 1]) {
//                tmp.push_back(a[i]);
//            }
//        }
//        a = tmp;
//    }
//public:
//    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
//        memset(dp, -1, sizeof(dp));
//        Init(arr2);
//        int res = dfs(arr1, arr2, arr1.size(), 0);
//        return res == INT_MAX ? -1 : res;
//    }
//};
