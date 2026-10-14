//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//    int val;
//    Node* next;
//    Node* random;
//
//    Node(int _val) {
//        val = _val;
//        next = NULL;
//        random = NULL;
//    }
//};
//
//
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        if (head == NULL)
//            return NULL;
//        Node* cur = head;
//        Node* next = NULL;
//
//        while (cur != NULL) {
//            next = cur->next;
//            cur->next = new Node(cur->val);
//            cur->next->next = next;
//            cur = next;
//        }
//
//        cur = head;
//        Node* copy = NULL;
//        while (cur != NULL) {
//            next = cur->next->next;
//            copy = cur->next;
//            copy->random = cur->random != NULL ? cur->random->next : NULL;
//            cur = next;
//        }
//
//        Node* ans = head->next;
//        cur = head;
//
//        while (cur != NULL) {
//            next = cur->next->next;
//            copy = cur->next;
//            cur->next = next;//还原原链表
//            copy->next = next != NULL ? next->next : NULL;
//            cur = next;
//        }
//
//        return ans;
//    }
//};