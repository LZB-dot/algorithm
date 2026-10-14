//#include<iostream>
//#include<vector>
//using namespace std;
//
//
// 
//struct ListNode {
//    int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//
//        ListNode* fast = dummy;
//        for (int i = 0; i < n; ++i) {
//            fast = fast->next;
//            if (fast == NULL) {
//                return head;
//            }
//        }
//
//        ListNode* slow = dummy;
//        while (fast->next != NULL) {
//            slow = slow->next;
//            fast = fast->next;
//        }
//
//        ListNode* tmp = slow->next;
//        slow->next = slow->next->next;
//        delete(tmp);
//
//        ListNode* ans = dummy->next;
//        delete(dummy);
//        return ans;
//    }
//};