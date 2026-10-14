//#include<iostream>
//#include<queue>
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
//public:
//
//    //有右孩子没有左孩子肯定不是
//    //满足上述条件后，如果某个节点的两个子节点不全，之后的必须都是叶节点
//    bool isCompleteTree(TreeNode* root) {
//        queue<TreeNode*> q;
//        bool leaf = false;
//        TreeNode* left = nullptr;
//        TreeNode* right = nullptr;
//        q.push(root);
//        while (!q.empty()) {
//            root = q.front();
//            q.pop();
//            left = root->left;
//            right = root->right;
//            if ((leaf && (left || right)) || (!left && right)) 
//                return false;
//            if (left) 
//                q.push(left);
//            if (right) 
//                q.push(right);
//            if (!left || !right) 
//                leaf = true;
//        }
//        return true;
//    }
//};