//#include<iostream>
//#include<deque>
//#include<vector>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, k;
//    cin >> n >> k;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//
//    vector<int>ansmin, ansmax;
//    deque<int> dqmin, dqmax;
//
//    for (int i = 0; i < n; ++i) {
//
//        if (!dqmin.empty() && dqmin.front() < i - k + 1)
//            dqmin.pop_front();
//        if (!dqmax.empty() && dqmax.front() < i - k + 1)
//            dqmax.pop_front();
//
//        while (!dqmin.empty() && nums[i] <= nums[dqmin.back()])
//            dqmin.pop_back();
//
//        while (!dqmax.empty() && nums[i] >= nums[dqmax.back()])
//            dqmax.pop_back();
//
//        dqmin.push_back(i);
//        dqmax.push_back(i);
//
//        if (i >= k - 1){
//            ansmin.push_back(nums[dqmin.front()]);
//            ansmax.push_back(nums[dqmax.front()]);
//        }
//    }
//
//    for (int i : ansmin) 
//        cout << i << " "; 
//    cout << "\n"; 
//    for (int i : ansmax) 
//        cout << i << " "; 
//    cout << "\n";
//    
//    return 0;
//}