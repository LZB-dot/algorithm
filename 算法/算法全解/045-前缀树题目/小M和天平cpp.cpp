////#include<iostream>
////#include<unordered_set>
////#include<vector>
////using namespace std;
////
////int main()
////{
////	ios::sync_with_stdio(false);
////	cin.tie(nullptr);
////
////	int N;
////	while (cin >> N) {
////		vector<int>stones(N);
////		for (int i = 0; i < N; ++i)
////			cin >> stones[i];
////
////		int M;
////		cin >> M;
////
////		unordered_set<int>s1;
////		s1.insert(0);
////		for (int i = 0; i < N; ++i) {
////			unordered_set<int>temp;
////			for (int it : s1) {
////				temp.insert(stones[i] + it);
////				if (stones[i] - it < 0)
////					continue;
////				temp.insert(stones[i] - it);
////			}
////			for (int it : temp) {
////				s1.insert(it);
////			}
////		}
////
////		while (M--) {
////			int k;
////			cin >> k;
////			if (s1.find(k) != s1.end())
////				cout << "YES" << endl;
////			else
////				cout << "NO" << endl;
////		}
////	}
////
////	return 0;
////}
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAX = 100 * 100;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N;
//    while (cin >> N) {
//        vector<int> stones(N);
//        for (int i = 0; i < N; ++i) {
//            cin >> stones[i];
//        }
//
//        int M;
//        cin >> M;
//
//        vector<bool> dp(MAX + 1, false);
//        dp[0] = true; 
//
//        for (int stone : stones) {
//            vector<bool> temp = dp;
//            for (int w = 0; w <= MAX; ++w) {
//                if (dp[w]) {
//                    if (w + stone <= MAX)
//                        temp[w + stone] = true;
//                    int t = w - stone;
//                    if (t < 0)
//                        t = -t;
//                    temp[t] = true;
//                }
//            }
//            dp = temp; 
//        }
//
//        while (M--) {
//            int k;
//            cin >> k;
//            if (k > MAX) {
//                cout << "NO\n";
//                continue;
//            }
//            cout << (dp[k] ? "YES" : "NO") << '\n';
//        }
//    }
//
//    return 0;
//}