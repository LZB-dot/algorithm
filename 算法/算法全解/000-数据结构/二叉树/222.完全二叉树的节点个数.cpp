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
//private:
//    int highLeft(TreeNode* cur, int level) {
//        if (cur == nullptr)
//            return level;
//        while (cur->left != nullptr) {
//            level++;
//            cur = cur->left;
//        }
//        return level;
//    }
//
//    int nodes(TreeNode* cur, int level, int h) {
//        if (level == h) {
//            return 1;
//        }
//        if (highLeft(cur->right, level + 1) == h) {
//            return (1 << (h - level)) + nodes(cur->right, level + 1, h);
//        }
//        else {
//            return (1 << (h - level - 1)) + nodes(cur->left, level + 1, h);
//        }
//    }
//public:
//    int countNodes(TreeNode* root) {
//        if (root == nullptr)
//            return 0;
//        int h = highLeft(root, 1);
//        return nodes(root, 1, h);
//    }
//};