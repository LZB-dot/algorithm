//
//#include<iostream>
//#include<vector>
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
//
//
//struct Info{
//    //子树最大最小值
//    long long mx;
//    long long mi;
//    //最大BST大小
//    int maxSize;
//    bool isBST;
//
//    Info(long long a, long long b, bool c, int d) {
//        mx = a;
//        mi = b;
//        isBST = c;
//        maxSize = d;
//    }
//};
//
//class Solution {
//public:
//    int largestBSTSubtree(TreeNode* root) {
//        return f(root)->maxSize;
//    }
//
//    Info* f(TreeNode* x) {
//        if (x == nullptr) {
//            return new Info(LLONG_MIN, LLONG_MAX, true, 0);
//        }
//
//        Info* left = f(x->left);
//        Info* right = f(x->right);
//
//        long long maxVal = max((long long)x->val, max(left->mx, right->mx));
//        long long minVal = min((long long)x->val, min(left->mi, right->mi));
//
//        bool isBst = left->isBST && right->isBST
//            && left->mx < x->val && right->mi >= x->val;
//
//        int maxBSTSize;
//        if (isBst) {
//            maxBSTSize = 1 + left->maxSize + right->maxSize;
//        }
//        else {
//            maxBSTSize = max(left->maxSize, right->maxSize);
//        }
//
//        return new Info(maxVal, minVal, isBst, maxBSTSize);
//    }
//};
