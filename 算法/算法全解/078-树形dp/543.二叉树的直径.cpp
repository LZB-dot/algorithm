//
//
//#include<iostream>
//#include<vector>
//#include<memory>
//using namespace std;
//
//
//struct TreeNode {
//
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//
//struct Info {
//    int diameter;
//    int height;
//
//    Info(int a, int b) :
//        diameter(a), height(b){ }
//};
//
//
//class Solution {
//public:
//    int diameterOfBinaryTree(TreeNode* root) {
//        return dfs(root)->diameter;
//    }
//
//    shared_ptr<Info>dfs(TreeNode* tmp) {
//        if (tmp == nullptr) {
//            return make_shared<Info>(0, 0);
//        }
//
//        shared_ptr<Info>left = dfs(tmp->left);
//        shared_ptr<Info>right = dfs(tmp->right);
//
//        int height = max(left->height, right->height) + 1;
//
//        int case1 = max(left->diameter, right->diameter);
//        int case2 = left->height + right->height;
//
//        return make_shared<Info>(max(case1, case2), height);
//    }
//};