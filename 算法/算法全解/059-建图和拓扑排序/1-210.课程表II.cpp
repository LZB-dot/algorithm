////#include<iostream>
////#include<queue>
////#include<vector>
////using namespace std;
////
////class Solution {
////public:
////    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
////        vector<vector<int>>graph(numCourses);//邻接表
////        vector<int>indegree(numCourses, 0);//入度数组
////
////        //edge（a，b）  b指向a
////        for (auto edge : prerequisites) {
////            graph[edge[1]].push_back(edge[0]);//b节点指向a节点
////            indegree[edge[0]]++;//a节点的入度加一
////        }
////
////        queue<int>q;
////        for (int i = 0; i < numCourses; ++i)
////            if (indegree[i] == 0)
////                q.push(i); //将所有入度为0的加入队列
////
////        vector<int>res;
////        while (!q.empty()) {
////            int temp = q.front();
////            q.pop();
////            res.push_back(temp);//取出队首元素加入答案
////            for (auto it : graph[temp]) {
////                indegree[it]--;//队首元素出去，所以该节点指向的所有课程入度减一
////                if (indegree[it] == 0)
////                    q.push(it);//如果入度为0 可以入队
////            }
////        }
////
////        if (res.size() == numCourses) 
////            return res;
////        return {};
////    }
////};
//
//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//
//const int MAXN = 2005;
//
//class Solution {
//
//public:
//    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//        vector<vector<int>>graph(numCourses);
//        vector<int>indegree(numCourses,0);
//
//        for (auto& it : prerequisites) {
//            graph[it[1]].push_back(it[0]);
//            indegree[it[0]]++;
//        }
//
//        queue<int>q;
//        for (int i = 0; i < numCourses; ++i) {
//            if (indegree[i] == 0)
//                q.push(i);
//        }
//
//        vector<int>res;
//
//        while (!q.empty()) {
//            int u = q.front();
//            q.pop();
//            res.push_back(u);
//
//            for (int i : graph[u]) {
//                if (--indegree[i] == 0)
//                    q.push(i);
//            }
//        }
//
//        if (res.size() == numCourses) 
//            return res;
//        
//        return {};
//    }
//};