//#include<iostream>
//#include<queue>
//#include<vector>
//#include<algorithm> // 用于reverse函数
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
//public:
//    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//        vector<vector<int>> ans;
//        queue<TreeNode*> q;
//
//        if (root == nullptr) {
//            return ans;
//        }
//
//        q.push(root);
//        bool flag = true; // 标记当前层是否从左到右
//
//        while (!q.empty()) {
//            int size = q.size();
//            vector<int> currentLevel; // 存储当前层的节点值
//
//            for (int i = 0; i < size; ++i) {
//                TreeNode* tmp = q.front();
//                q.pop();
//                currentLevel.push_back(tmp->val);
//
//                // 正常顺序入队左右孩子（先左后右）
//                if (tmp->left != nullptr) {
//                    q.push(tmp->left);
//                }
//                if (tmp->right != nullptr) {
//                    q.push(tmp->right);
//                }
//            }
//
//            // 如果需要从右到左，则反转当前层的结果
//            if (!flag) {
//                reverse(currentLevel.begin(), currentLevel.end());
//            }
//
//            ans.push_back(currentLevel);
//            flag = !flag; // 切换下一层的遍历方向
//        }
//
//        return ans;
//    }
//};
