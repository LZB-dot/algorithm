//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
// 
//
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//        if (headA == NULL || headB == NULL)
//            return NULL;
//        ListNode* a = headA, * b = headB;
//        int diff = 0;
//        while (a->next != NULL) {
//            a = a->next;
//            diff++;
//        }
//        while (b->next != NULL) {
//            b = b->next;
//            diff--;
//        }
//
//        if (a != b)
//            return NULL;
//
//        if (diff < 0) {
//            a = headB;
//            b = headA;
//        }
//        else {
//            a = headA;
//            b = headB;
//        }
//        diff = abs(diff);
//        while (diff--) {
//            a = a->next;
//        }
//
//        while (a != b) {
//            a = a->next;
//            b = b->next;
//        }
//
//        return a;
//    }
//};