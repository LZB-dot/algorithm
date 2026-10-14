//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//#define endl "\n"
//#pragma GCC optimize(3)
//
//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode(int x) :val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode* mergeKLists(vector<ListNode*>& arr) {
//		auto cmp = [](ListNode* a, ListNode* b) {
//			return a->val > b->val;
//			};
//
//		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>heap(cmp);
//
//		for (auto h : arr)
//			if (h != nullptr)
//				heap.push(h);
//
//		if (heap.empty())
//			return nullptr;
//
//		ListNode* head = heap.top();
//		heap.pop();
//		ListNode* pre = head;
//		if (pre->next != nullptr)
//			heap.push(pre->next);
//
//		while (!heap.empty())
//		{
//			ListNode* cur = heap.top();
//			heap.pop();
//			pre->next = cur;
//			pre = cur;
//			if (cur->next != nullptr)
//				heap.push(cur->next);
//		}
//
//		return head;
//
//	}
//	
//};
