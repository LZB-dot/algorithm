//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<pair<int, int>> times(n); 
//
//    for (int i = 0; i < n; ++i) {
//        cin >> times[i].first >> times[i].second;
//    }
//    sort(times.begin(), times.end(), [](pair<int, int>& a, pair<int, int>& b) {
//        return a.second < b.second;
//        });
//
//    int last = -1;  
//    int count = 0;       
//
//    for (const auto& it : times) {
//        if (it.first >= last) {
//            // 选择当前比赛
//            last = it.second;
//            count++;
//        }
//    }
//
//    cout << count << endl;
//
//    return 0;
//}