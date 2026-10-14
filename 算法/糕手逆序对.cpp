////#include<iostream>
////#include<vector>
////using namespace std;
////
////vector<int> v;
////bool found = false;
////int n, m;
////
////int count() {
////    int cnt = 0;
////    for (int i = 0; i < v.size(); ++i) {
////        for (int j = i + 1; j < v.size(); ++j) {
////            if (v[i] > v[j]) {
////                cnt++;
////                if (cnt > m) 
////                    return cnt;  
////            }
////        }
////    }
////    return cnt;
////}
////
////void digui(int start) {
////    if (found) 
////        return;  
////
////    if (start == n) {
////        if (count() == m) {
////            found = true;
////            for (int num : v) {
////                cout << num << " ";
////            }
////        }
////        return;
////    }
////
////    for (int i = start; i < n; ++i) {
////        swap(v[start], v[i]);
////        digui(start + 1);
////        if (found) 
////            return; 
////        swap(v[start], v[i]);
////    }
////}
////
////int main() {
////    cin >> n >> m;
////    v.resize(n);
////    for (int i = 0; i < n; ++i) {
////        v[i] = i + 1;
////    }
////
////    digui(0);
////    return 0;
////}
//
////#include<iostream>
////#include<vector>
////#include<set>
////using namespace std;
////
////typedef long long ll;
////
////void work(int n, ll m) {
////	vector<int>res;
////	set<int>s;//保证升序
////
////	for (int i = 1; i <= n; ++i) {
////		s.insert(i);
////	}
////
////	for (int i = 0; i < n; ++i) {
////		int cur = n - i - 1;//剩余数
////		ll mx = cur * (cur - 1) / 2;//剩余数的最大逆序对
////
////		if (m <= mx) {
////			res.push_back(*s.begin());
////			s.erase(s.begin());
////		}
////		else {
////			int need = m - mx;//需要提前搞定的逆序对数
////			auto x = s.begin();
////			advance(x, need);//从开头向后走
////			res.push_back(*x);
////			s.erase(x);
////			m -= need;//剩下需要搞定的逆序对数
////		}
////	}
////
////	for (int num : res) {
////		cout << num << " ";
////	}
////	cout << endl;
////}
////
////int main() {
////	int n;
////	ll m;
////	cin >> n >> m;
////	work(n, m);
////	return 0;
////}
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//
//void work(int n, ll m) {
//    vector<int> res;
//    vector<int> arr(n + 1);  // 1-based索引，存储可用元素
//
//    // 初始化数组为1~n
//    for (int i = 1; i <= n; ++i) {
//        arr[i] = i;
//    }
//
//    int left = 1;  // 当前可用元素的起始位置
//
//    for (int i = 0; i < n; ++i) {
//        int cur = n - i - 1;  // 剩余元素数量
//        ll mx = (ll)cur * (cur - 1) / 2;  // 剩余元素可形成的最大逆序对
//
//        if (m <= mx) {
//            res.push_back(arr[left]);
//            left++;
//        }
//        else {
//            //需要选择更大的元素来贡献额外逆序对
//            int need = m - mx;  //额外需要的逆序对数量
//            int pos = left + need;  //选中元素的位置
//
//            int selected = arr[pos];
//            res.push_back(selected);
//
//            for (int j = pos; j > left; --j) {
//                swap(arr[j], arr[j - 1]);
//            }
//
//            // 对剩余元素进行逆序排序
//            sort(arr.begin() + left + 1, arr.end(), greater<int>());
//
//            for (int j = left + 1; j <= n; ++j) {
//                res.push_back(arr[j]);
//            }
//            break;
//        }
//    }
//
//    for (int num : res) {
//        cout << num << " ";
//    }
//    cout << endl;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
//    int n;
//    ll m;
//    cin >> n >> m;
//    work(n, m);
//
//    return 0;
//}
//
