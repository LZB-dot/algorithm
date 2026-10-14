//#include<iostream>
//#include<unordered_map>
//using namespace std;
//
//struct Node {
//	int val;
//	Node* prev;
//	Node* next;
//
//	Node(int v) :val(v), prev(nullptr), next(nullptr){}
//};
//
//int main() {
//
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	unordered_map<int, Node*>nodeMap;
//
//	int n;
//	cin >> n;
//	Node* head = new Node(1);
//	nodeMap[1] = head;
//
//	while (n--) {
//		int x;
//		cin >> x;
//		if (x == 1) {
//			int a, b;
//			cin >> a >> b;
//			Node* newNode = new Node(b);
//			nodeMap[b] = newNode;
//
//			Node* aNode = nodeMap[a];
//			Node* aNext = aNode->next;
//
//			aNode->next = newNode;
//			newNode->prev = aNode;
//			newNode->next = aNext;
//
//			if (aNext != nullptr) {
//				aNext->prev = newNode;
//			}
//		}
//
//		else if (x == 2) {
//			int a;
//			cin >> a;
//			Node* aNode = nodeMap[a];
//			if (aNode->next != nullptr)
//				cout << aNode->next->val << '\n';
//			else
//				cout << 0 << '\n';
//		}
//
//		else {
//			int a;
//			cin >> a;
//
//			Node* aNode = nodeMap[a];
//			Node* bNode = aNode->next;
//			
//			if (bNode != nullptr) {
//				aNode->next = bNode->next;
//				if (bNode->next != nullptr) {
//					bNode->next->prev = aNode;
//				}
//
//				nodeMap.erase(bNode->val);
//				delete bNode;
//			}
//		}
//
//	}
//}