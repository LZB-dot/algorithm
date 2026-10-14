//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//unordered_map<long long, long long> pre, nxt;
//
//void remove(long long x) {
//    long long p = pre[x];
//    long long q = nxt[x];
//    nxt[p] = q;
//    pre[q] = p;
//}
//
//void insert(long long p, long long x) {
//    long long q = nxt[p];  
//    pre[x] = p;           
//    nxt[x] = q;           
//    nxt[p] = x;            
//    pre[q] = x;            
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    int n;
//    cin >> n;
//
//    vector<long long> nums(n); 
//    for (int i = 0; i < n; ++i) {
//        cin >> nums[i];
//    }
//    int m;
//    cin >> m;
//
//    pre[nums[0]] = -1LL;
//    nxt[-1LL] = nums[0];
//    for (int i = 1; i < n; ++i) {
//        pre[nums[i]] = nums[i - 1];
//        nxt[nums[i - 1]] = nums[i];
//    }
//    nxt[nums.back()] = -1LL;
//    pre[-1LL] = nums.back();
//
//    while (m--) {
//        int op;
//        cin >> op;
//        if (op == 1) {
//            long long x, y;
//            cin >> x >> y;
//            insert(x, y);
//        }
//        else if (op == 2) {
//            long long x;
//            cin >> x;
//            remove(x);
//        }
//    }
//
//    vector<long long> res;
//    long long cur = nxt[-1LL];
//    while (cur != -1LL) {
//        res.push_back(cur);
//        cur = nxt[cur];
//    }
//    for (int i = 0; i < res.size(); ++i) {
//        if (i > 0) 
//            cout << " ";
//        cout << res[i];
//    }
//    cout << endl;
//
//    return 0;
//}