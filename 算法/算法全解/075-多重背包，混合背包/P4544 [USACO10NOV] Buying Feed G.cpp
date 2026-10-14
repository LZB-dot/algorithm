//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<deque>  
//using namespace std;
//
//typedef long long ll;
//const ll INF = 1e15;  
//
//struct Shop {
//    ll x;    //位置
//    ll cnt;  //库存
//    ll cost; //单价
//};
//
//Shop sp[11000];              
//ll dp[510][11100];            //前i家店买了j吨的最小成本
//ll dist[11000];               //距离数组
//deque<ll> que;                
//int k, e, n;                 
//
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> k >> e >> n;
//    for (int i = 1; i <= n; ++i) {
//        cin >> sp[i].x >> sp[i].cnt >> sp[i].cost;
//    }
//
//    //增加一个虚拟商店计算最后一段路程
//    n++;
//    sp[n].x = e;
//    sp[n].cnt = 0;   //虚拟商店无库存
//    sp[n].cost = 0;  //虚拟商店无购买成本
//
//    //按位置升序排序商店
//    sort(sp + 1, sp + 1 + n, [](const Shop& a, const Shop& b) {
//        return a.x < b.x;
//        });
//
//    //计算相邻商店的距离
//    for (int i = 2; i <= n; ++i) {
//        dist[i] = sp[i].x - sp[i - 1].x;
//    }
//
//    memset(dp, 0x3f, sizeof(dp)); 
//    dp[0][0] = 0;
//
//    //遍历每一家店
//    for (int i = 1; i <= n; ++i) {
//        que.clear(); 
//        //遍历购买的吨数
//        for (int j = 0; j <= k; ++j) {
//            //超出当前商店库存限制的决策（队首弹出）
//            //队头就是这个区间已买的最好吨数，j-队头就是当前商店一个购买的
//            while (!que.empty() && j - que.front() > sp[i - 1].cnt) 
//                que.pop_front();
//            
//            //将当前决策j加入队列
//            if (dp[i - 1][j] != INF) {
//                while (!que.empty()) {
//                    ll last = que.back(); 
//                    if (dp[i - 1][last] - last * sp[i - 1].cost < dp[i - 1][j] - j * sp[i - 1].cost)
//                        break;
//                    
//                    que.pop_back(); 
//                }
//                que.push_back(j);
//            }
//
//            //取队列头的最优决策
//            if (!que.empty()) {
//                ll best = que.front(); 
//                // dp[i-1][best]：前i-1家店买best吨的成本
//                // (j-best)*sp[i-1].cost：在第i-1家店买(j-best)吨的费用
//                // j*j*dist[i]：从第i-1家店到第i家店，拉j吨的运费
//                dp[i][j] = dp[i - 1][best] + (j - best) * sp[i - 1].cost + j * j * dist[i];
//            }
//        }
//    }
//
//    cout << dp[n][k] << endl;
//    return 0;
//}