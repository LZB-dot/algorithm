//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//
//class Solution {
//private:
//    // 序列化树为字符串，空节点用 "#" 表示
//    void build(TreeNode* head, vector<string>& s) {
//        if (head == NULL) {
//            s.push_back("#");  // 使用 "#" 表示空节点
//            return;
//        }
//        else {
//            s.push_back(to_string(head->val));
//            build(head->left, s);
//            build(head->right, s);
//        }
//    }
//
//    // 获取 KMP 的 next 数组
//    vector<int> getNxt(const vector<string>& s) {
//        int m = s.size();
//        if (m == 1)
//            return{ -1 };
//        vector<int> nxt(m, 0);
//        nxt[0] = -1;
//        nxt[1] = 0;
//        int cn = 0;
//        int i = 2;
//        while (i < m) {
//            if (s[i-1] == s[cn]) {
//                nxt[i++] = ++cn;
//            }
//            else if (cn > 0)
//                cn = nxt[cn];
//            else
//                nxt[i++] = 0;
//        }
//        return nxt;
//    }
//
//    int kmp(const vector<string>& s1, const vector<string>& s2) {
//        int n = s1.size();
//        int m = s2.size();
//        if (m == 0)
//            return 0;
//
//        vector<int> nxt = getNxt(s2);
//        int x = 0, y = 0;
//
//        while (x < n && y < m) {
//            if (s1[x] == s2[y]) {
//                ++x;
//                ++y;
//            }
//            else if (y > 0) 
//                y = nxt[y];  
//            else 
//                ++x; 
//            
//        }
//        return (y == m) ? (x - y) : -1;
//    }
//
//public:
//    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//        vector<string> s1, s2;
//        build(root, s1);  
//        build(subRoot, s2); 
//
//        return kmp(s1, s2) != -1;
//    }
//};