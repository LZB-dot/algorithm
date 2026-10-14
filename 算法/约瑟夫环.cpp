//#include<iostream>
//#include<queue>
//using namespace std;
//
//int main()
//{
//    queue<int> q;
//    int n, k, m;
//    cin >> n >> k >> m;
//
//    for (int i = 0; i < n; i++)
//        q.push((k + i) % n);
//
//    int count = 0;
//    while (q.size() > 1) 
//    {
//        int current = q.front();
//        q.pop();
//
//        count++;
//        if (count % m != 0) 
//            q.push(current);
//    }
//
//    cout << q.front() << endl;
//    return 0;
//}
