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
//struct Info{
//    int maxVal;
//    int minVal;
//    bool isBST;
//    int sum;//当前子树键值和
//    int maxBSTSum;//比较到当前子树位置最大键值和
//
//    Info(int a, int b, int c, bool d, int e) :
//        maxVal(a), minVal(b), sum(c), isBST(d), maxBSTSum(e){ }
//};
//
//class Solution {
//public:
//    int maxSumBST(TreeNode* root) {
//        return dfs(root)->maxBSTSum;
//    }
//
//    shared_ptr<Info> dfs(TreeNode* x) {
//        if (x == nullptr) {
//            return make_shared<Info>(INT_MIN, INT_MAX, 0, true, 0);
//        }
//
//        shared_ptr<Info>left = dfs(x->left);
//        shared_ptr<Info>right = dfs(x->right);
//
//        int maxVal = max(x->val, max(left->maxVal, right->maxVal));
//        int minVal = min(x->val, min(left->minVal, right->minVal));
//        int sumVal = left->sum + right->sum + x->val;
//
//        bool isBst = left->isBST && right->isBST
//            && x->val > left->maxVal && right->minVal > x->val;
//
//        int sumBst;
//        if (isBst) {
//            sumBst = max(sumVal, max(left->maxBSTSum, right->maxBSTSum));
//        }
//        else {
//            sumBst = max(left->maxBSTSum, right->maxBSTSum);
//        }
//
//        return make_shared<Info>(maxVal, minVal, sumVal, isBst, sumBst);
//    }
//};