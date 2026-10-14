//#include<iostream>
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//
//class Solution {
//private:
//    ListNode* start = NULL;  // 合并后的头节点
//    ListNode* end = NULL;    // 合并后的尾节点
//
//public:
//    ListNode* sortList(ListNode* head) {
//        if (head == NULL || head->next == NULL)
//            return head;
//
//        // 计算链表长度
//        ListNode* cur = head;
//        int n = 0;
//        while (cur != NULL) {
//            cur = cur->next;
//            n++;
//        }
//
//        // 创建哑节点，方便处理头节点变化
//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//
//        ListNode* lastT;  // 上一次合并的尾节点
//        ListNode* l1, * r1, * l2, * r2;
//        ListNode* next;   // 下一组的起始节点
//
//        for (int step = 1; step < n; step <<= 1) {
//            lastT = dummy;
//            l1 = dummy->next;  // 每次从链表头部开始处理
//
//            while (l1 != NULL) {
//                // 找到第一组的尾节点
//                r1 = findEnd(l1, step);
//                if (r1 == NULL) break;
//
//                // 找到第二组的头节点和尾节点
//                l2 = r1->next;
//                r2 = findEnd(l2, step);
//
//                // 记录下一组的起始位置
//                if (r2 != NULL) {
//                    next = r2->next;
//                    r2->next = NULL;  // 切断第二组与后续节点的连接
//                }
//                else {
//                    next = NULL;
//                }
//
//                // 切断第一组与第二组的连接
//                r1->next = NULL;
//
//                // 合并两组
//                merge(l1, r1, l2, r2);
//
//                // 将合并后的链表连接到上一部分
//                lastT->next = start;
//                lastT = end;       // 更新上一次合并的尾节点
//
//                // 处理下一组
//                l1 = next;
//            }
//        }
//
//        ListNode* result = dummy->next;
//        delete dummy;  // 释放哑节点
//        return result;
//    }
//
//    // 找到从l开始，长度为step的子链表的尾节点
//    ListNode* findEnd(ListNode* l, int step) {
//        if (l == NULL) return NULL;
//
//        while (l->next != NULL && --step > 0) {
//            l = l->next;
//        }
//        return l;
//    }
//
//    // 合并两个有序链表，并用start和end记录合并后的头和尾
//    void merge(ListNode* l1, ListNode* r1, ListNode* l2, ListNode* r2) {
//        // 如果第二组为空，直接使用第一组
//        if (l2 == NULL) {
//            start = l1;
//            end = r1;
//            return;
//        }
//
//        ListNode* pre = new ListNode(0);  // 临时头节点
//        ListNode* cur = pre;
//        ListNode* p1 = l1;
//        ListNode* p2 = l2;
//
//        // 合并两个有序链表
//        while (p1 != NULL && p2 != NULL) {
//            if (p1->val <= p2->val) {
//                cur->next = p1;
//                p1 = p1->next;
//            }
//            else {
//                cur->next = p2;
//                p2 = p2->next;
//            }
//            cur = cur->next;
//        }
//
//        // 处理剩余节点
//        if (p1 != NULL) {
//            cur->next = p1;
//            end = r1;  // 第一组有剩余，尾节点是r1
//        }
//        else {
//            cur->next = p2;
//            end = r2;  // 第二组有剩余，尾节点是r2
//        }
//
//        start = pre->next;  // 记录合并后的头节点
//        delete pre;         // 释放临时头节点
//    }
//
//
//};

