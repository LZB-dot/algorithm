//#include<iostream>
//#include<vector>
//#include<algorithm> 
//
//const int MAXN = 1e5 + 10;
//
//int n, q;
//int a[MAXN];
//int bucket[MAXN];    //下标i属于第几个桶
//int left_[MAXN];     //第cnt个桶的左边界
//int right_[MAXN];    //第cnt个桶的右边界
//int cnt = 1;         //桶的编号
//
//int stjump[MAXN][20];
//int mylog2[MAXN];    
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> q;
//    for (int i = 1; i <= n; ++i)
//        cin >> a[i];
//
//    for (int i = 1; i <= n;) {
//        int r = i;
//        while (r <= n && a[r] == a[i]) {
//            bucket[r] = cnt; 
//            ++r;
//        }
//        left_[cnt] = i;      
//        right_[cnt] = r - 1;  
//        ++cnt;
//        i = r;
//    }
//    --cnt; 
//
//    mylog2[1] = 0;
//    for (int i = 2; i <= cnt; ++i)
//        mylog2[i] = mylog2[i >> 1] + 1;
//
//    for (int i = 1; i <= cnt; ++i)
//        stjump[i][0] = right_[i] - left_[i] + 1;
//
//    for (int p = 1; p <= mylog2[cnt]; ++p) {
//        for (int i = 1; i + (1 << p) - 1 <= cnt; ++i) 
//            stjump[i][p] = max(stjump[i][p - 1], stjump[i + (1 << (p - 1))][p - 1]);
//    }
//
//    while (q--) {
//        int l, r;
//        cin >> l >> r;
//        if (l > r) 
//            swap(l, r);
//
//        int lb = bucket[l];
//        int rb = bucket[r];
//
//        if (lb == rb) 
//            cout << r - l + 1 << "\n";
//        else {
//            int pa = right_[lb] - l + 1;
//            int pb = r - left_[rb] + 1;
//            int pc = 0;
//
//            if (lb + 1 < rb) {
//                int L = lb + 1;
//                int R = rb - 1;
//                int p = mylog2[R - L + 1];
//                pc = max(stjump[L][p], stjump[R - (1 << p) + 1][p]);
//            }
//
//            cout << max({ pa,pb,pc }) << "\n";
//        }
//    }
//    return 0;
//}