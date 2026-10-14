//#include<iostream>
//#include<unordered_map>
//using namespace std;
//
//struct DListNode {
//    int key;//关键字
//    int val;//数据
//    DListNode* prev;
//    DListNode* next;
//    DListNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
//    DListNode(int k,int v):key(k),val(v),prev(nullptr),next(nullptr){}
//};
//
//
//class LRUCache {
//
//private:
//    DListNode* head = NULL;//头
//    DListNode* tail = NULL;//尾
//    unordered_map<int, DListNode*>mp;//存储关键字和链表地址
//    int capacity;//最大容量
//    int size;//当前容量
//
//    //移动到头部
//    void moveToHead(DListNode* node) {
//        removeNode(node);//从当前位置移除
//        addToHead(node);//添加到头部
//    }
//
//    void removeNode(DListNode* node) {
//        node->prev->next = node->next;
//        node->next->prev = node->prev;
//    }
//
//    void addToHead(DListNode* node) {
//        node->prev = head;
//        node->next = head->next;
//        head->next->prev = node;
//        head->next = node;
//    }
//
//    //移除尾部节点（最久未使用）
//    DListNode* removeTail() {
//        DListNode* node = tail;
//        removeNode(node);
//        return node;
//    }
//
//public:
//    
//
//    LRUCache(int capacity) {
//        //将private中的数据初始化
//        this->capacity = capacity;
//        this->size = 0;
//
//        head = new DListNode();
//        tail = new DListNode();
//
//        head->next = tail;
//        tail->prev == head;
//    }
//
//
//    int get(int key) {
//        if (!mp.count(key)) {
//            return -1;
//        }
//        DListNode* node = mp[key];
//        moveToHead(node);
//        return node->val;
//    }
//
//    void put(int key, int value) {
//        if (!mp.count(key)) {
//            DListNode* node = new DListNode(key, value);
//            mp[key] = node;
//            addToHead(node);
//            size++;
//            if (size > capacity) {
//                DListNode* del = removeTail();
//                mp.erase(del->key);
//                delete del;
//                size--;
//            }
//        }
//        else {
//            DListNode* node = mp[key];
//            node->val = value;
//            moveToHead(node);
//        }
//    }
//};
