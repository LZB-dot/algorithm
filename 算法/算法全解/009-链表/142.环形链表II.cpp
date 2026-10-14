//#include<iostream>
//using namespace std;
// 
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
// 
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        if (head == NULL || head->next == NULL || head->next->next == NULL)
//            return NULL;
//
//        ListNode* slow = head->next;
//        ListNode* fast = head->next->next;
//
//        while (slow != fast) {
//            if (fast->next == NULL || fast->next->next == NULL)
//                return NULL;
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//
//        fast = head;
//        while (slow != fast) {
//            slow = slow->next;
//            fast = fast->next;
//        }
//
//        return slow;
//    }
//};