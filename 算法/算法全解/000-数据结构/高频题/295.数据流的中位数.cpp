//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//class MedianFinder {
//private:
//    priority_queue<int>maxHeap;//大根堆存小的一半
//    priority_queue<int, vector<int>, greater<int>>minHeap;//小根堆存大的一半
//
//    //平衡两个堆的大小，保证maxHeap最多比minHeap多一个
//    void balance() {
//        if (maxHeap.size() > minHeap.size()+1) {
//            minHeap.push(maxHeap.top());
//            maxHeap.pop();
//        }
//        else if (minHeap.size() > maxHeap.size()) {
//            maxHeap.push(minHeap.top());
//            minHeap.pop();
//        }
//    }
//public:
//    MedianFinder() { }
//
//    void addNum(int num) {
//        if (maxHeap.empty() || maxHeap.top() >= num) {
//            maxHeap.push(num);
//        }
//        else {
//            minHeap.push(num);
//        }
//        balance();
//    }
//
//    double findMedian() {
//        if (maxHeap.size() == minHeap.size()) {
//            return (double)(maxHeap.top() + minHeap.top()) / 2;
//        }
//        else
//            return maxHeap.top();
//    }
//};
