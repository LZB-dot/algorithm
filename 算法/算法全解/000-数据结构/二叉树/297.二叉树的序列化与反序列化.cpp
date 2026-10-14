//#include<iostream>
//#include<queue>
//#include<vector>
//#include<sstream>
//using namespace std;
//
//
//struct TreeNode {
//    int val;
//    TreeNode*  left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
// 
//class Codec {
//private:
//    void serializeDFS(TreeNode* root, string& s) {
//        if (root == nullptr) {
//            s += "#,";
//            return;
//        }
//        s += to_string(root->val) + ",";
//        serializeDFS(root->left, s);
//        serializeDFS(root->right, s);
//    }
//    TreeNode* deserializeDFS(vector<string>& nodes, int& idx) {
//        if (nodes[idx] == "#") {
//            idx++;
//            return nullptr;
//        }
//        TreeNode* root = new TreeNode(stoi(nodes[idx]));
//        idx++;
//        root->left = deserializeDFS(nodes, idx);
//        root->right = deserializeDFS(nodes, idx);
//        return root;
//    }
//public:
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        string s;
//        serializeDFS(root, s);
//        return s;
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        vector<string>nodes;
//        stringstream ss(data);
//        string node;
//        while (getline(ss, node, ',')) {
//            nodes.push_back(node);
//        }
//        int idx = 0;
//        return deserializeDFS(nodes, idx);
//    }
//};
