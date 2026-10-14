//#include<iostream>
//#include<vector>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
// 
//class Solution {
//private:
//    void copy(const vector<int>& path, vector<vector<int> >&ans) {
//        ans.push_back(path);
//    }
//
//    void process(TreeNode* h, int targetSum, 
//        int sum, vector<int>& path, vector<vector<int> >& ans) {
//        
//        if (h->left == nullptr && h->right == nullptr) {
//            if ((h->val + sum) == targetSum) {
//                path.push_back(h->val);
//                copy(path, ans);
//                path.pop_back();
//            }
//            return;
//        }
//
//        path.push_back(h->val);
//        if (h->left != nullptr) {
//            process(h->left, targetSum, sum + h->val, path, ans);
//        }
//        if (h->right != nullptr) {
//            process(h->right, targetSum, sum + h->val, path, ans);
//        }
//        path.pop_back();
//    }
//public:
//    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//        vector<vector<int> >ans;
//        if (root == nullptr)
//            return ans;
//        vector<int>path;
//        process(root, targetSum, 0, path, ans);
//        return ans;
//    }
//};
