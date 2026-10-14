//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX 100
//
//// 定义队列节点结构体
//typedef struct Node {
//	int level;//当前层次
//	int weight;
//	int bound;//上界重量
//	struct Node* next;
//}Node;
//
//// 定义优先队列结构体
//typedef struct {
//	Node* front;
//	Node* rear;
//}PriorQueue;
//
////初始化
//void initQueue(PriorQueue* q)
//{
//	q->front = q->rear = NULL;
//}
//
////判断队列是否为空
//int isEmpty(PriorQueue* q)
//{
//	return q->front == NULL;
//}
//
//// 插入节点到优先队列（按上界重量降序插入）
//void enqueue(PriorQueue* q, int level, int weight, int bound)
//{
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	newNode->level = level;
//	newNode->weight = weight;
//	newNode->bound = bound;
//	newNode->next = NULL;
//	if (isEmpty(q))
//		q->front = q->rear = newNode;
//	else if (bound > q->front->bound)
//	{
//		newNode->next = q->front;
//		q->front = newNode;
//	}
//	else
//	{
//		Node* current = q->front;
//		while (current->next != NULL && current->next->bound > bound)
//			current = current->next;
//		newNode->next = current->next;
//		current->next = newNode;
//		if (newNode->next == NULL)
//			q->rear = newNode;
//	}
//}
//
//Node* dequeue(PriorQueue* q)
//{
//	if (isEmpty(q))
//		return NULL;
//	Node* temp = q->front;
//	q->front = q->front->next;
//	if (q->front == NULL)
//		q->rear = NULL;
//	return temp;
//}
//
//int bound(int i, int weight, int* w, int c, int n)
//{
//	int cleft = c - weight;
//	int b = weight;
//	while (i < n && w[i] <= cleft)
//	{
//		cleft -= w[i];
//		b += w[i];
//		i++;
//	}
//	if (i < n)
//		b += cleft;
//	return b;
//}
//
//// 优先队列分支限界法求解装载问题
//int maxLoading(int* w, int c, int n) {
//	PriorQueue q;
//	initQueue(&q);
//
//	int bestWeight = 0;
//	enqueue(&q, 0, 0, bound(0, 0, w, c, n));
//
//	while (!isEmpty(&q)) {
//		Node* node = dequeue(&q);
//		int level = node->level;
//		int weight = node->weight;
//		int boundVal = node->bound;
//		free(node);
//
//		if (level == n) {
//			if (weight > bestWeight) {
//				bestWeight = weight;
//			}
//		}
//		else {
//			if (boundVal > bestWeight) {
//				// 考虑左子树（装载当前集装箱）
//				int leftWeight = weight + w[level];
//				if (leftWeight <= c) {
//					enqueue(&q, level + 1, leftWeight, bound(level + 1, leftWeight, w, c, n));
//				}
//				// 考虑右子树（不装载当前集装箱）
//				enqueue(&q, level + 1, weight, bound(level + 1, weight, w, c, n));
//			}
//		}
//	}
//
//	return bestWeight;
//}
//
//int main() {
//	int w[] = { 20, 30, 60, 40, 50 };
//	int c = 100;
//	int n = sizeof(w) / sizeof(w[0]);
//
//	int result = maxLoading(w, c, n);
//	printf("最大装载重量为: %d\n", result);
//
//	return 0;
//}

