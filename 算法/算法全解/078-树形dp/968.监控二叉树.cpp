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
//class Solution {
//private:
//    int ans = 0;
//
//    //0未被覆盖，必须装摄像头
//    //1被覆盖无摄像头 
//    //2有摄像头
//    int dfs(TreeNode* x) {
//        if (x == nullptr) {
//            return 1;
//        }
//
//        int left = dfs(x->left);
//        int right = dfs(x->right);
//
//        if (left == 0 || right == 0) {
//            ans++;
//            return 2;
//        }
//
//        if (left == 2 || right == 2) {
//            return 1;
//        }
//
//        return 0;
//    }
//public:
//    int minCameraCover(TreeNode* root) {
//        if (dfs(root) == 0) {
//            ans++;
//        }
//        return ans;
//    }
//
//
//};