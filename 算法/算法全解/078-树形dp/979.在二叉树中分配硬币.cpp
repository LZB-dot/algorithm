//#include<iostream>
//#include<vector>
//#include<memory>
//using namespace std;
//
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
//struct Info {
//    int nodeCount;
//    int sum;
//    int inMove;
//
//    Info(int a, int b, int c) :
//        nodeCount(a), sum(b), inMove(c){ }
//};
//
//class Solution {
//public:
//    int distributeCoins(TreeNode* root) {
//        return dfs(root)->inMove;
//    }
//
//    shared_ptr<Info>dfs(TreeNode* x) {
//        if (x == nullptr) {
//            return make_shared<Info>(0, 0, 0);
//        }
//
//        shared_ptr<Info>left = dfs(x->left);
//        shared_ptr<Info>right = dfs(x->right);
//
//        int node = left->nodeCount + right->nodeCount + 1;
//
//        int inMove = left->inMove + right->inMove
//            + abs(left->sum - left->nodeCount) + abs(right->sum - right->nodeCount);
//
//        int sum = left->sum + right->sum + x->val;
//
//        return make_shared<Info>(node, sum, inMove);
//    }
//};
