//
//
//
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<climits>
//using namespace std;
//
//
// 
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
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
//    vector<int>getNxt(int m,const vector<int>& s) {
//        if (m == 1)
//            return{ -1 };
//
//        vector<int>nxt(m);
//        nxt[0] = -1;
//        nxt[1] = 0;
//
//        int i = 2, cn = 0;
//        while (i < m) {
//            if (s[i - 1] == s[cn])
//                nxt[i++] = ++cn;
//            else if (cn > 0)
//                cn = nxt[cn];
//            else
//                nxt[i++] = 0;
//        }
//
//        return nxt;
//    }
//
//    bool kmp(const vector<int>& s2, const vector<int>& nxt, TreeNode* root, int i) {
//        if (i == s2.size())
//            return true;
//
//        if (root == nullptr)
//            return false;
//
//        while (i >= 0 && s2[i] != root->val) {
//            i = nxt[i];
//        }
//
//        return kmp(s2, nxt, root->left, i + 1) || kmp(s2, nxt, root->right, i + 1);
//    }
//
//public:
//    bool isSubPath(ListNode* head, TreeNode* root) {
//        if (head == nullptr)
//            return true;
//        if (root == nullptr)
//            return false;
//
//        ListNode* tmp = head;
//        vector<int>s2;
//        while(tmp != nullptr) {
//            s2.push_back(tmp->val);
//            tmp = tmp->next;
//        }
//        int m = s2.size();
//
//        vector<int>nxt = getNxt(m, s2);
//
//        return kmp(s2, nxt, root, 0);
//    }
//};