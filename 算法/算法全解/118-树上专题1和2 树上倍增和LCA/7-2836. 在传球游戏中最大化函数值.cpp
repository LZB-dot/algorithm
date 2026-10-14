//#include <vector>
//#include <algorithm>
//using namespace std;
//
//typedef long long ll;
//
//class Solution {
//public:
//    ll getMaxFunctionValue(vector<int>& receiver, ll k) {
//        int n = receiver.size();
//        const int LOG = 35;
//
//        vector<vector<int>> stjump(n, vector<int>(LOG));
//        vector<vector<ll>> val(n, vector<ll>(LOG));
//
//        for (int i = 0; i < n; ++i) {
//            stjump[i][0] = receiver[i];
//            val[i][0] = receiver[i];
//        }
//
//        for (int p = 1; p < LOG; ++p) {
//            for (int i = 0; i < n; ++i) {
//                stjump[i][p] = stjump[stjump[i][p - 1]][p - 1];
//                val[i][p] = val[i][p - 1] + val[stjump[i][p - 1]][p - 1];
//            }
//        }
//
//        ll ans = 0;
//        for (int i = 0; i < n; ++i) {
//            ll sum = i;
//            int cur = i;
//            for (int p = 0; p < LOG; ++p) {
//                if (k & (1LL << p)) {
//                    sum += val[cur][p];
//                    cur = stjump[cur][p];
//                }
//            }
//            ans = max(ans, sum);
//        }
//        return ans;
//    }
//};