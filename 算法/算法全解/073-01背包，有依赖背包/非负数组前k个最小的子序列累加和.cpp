////非负数组前k个最小的子序列累加和
////给定一个数组nums，含有n个数字，都是非负数
////给定一个正数k，返回所有子序列中累加和最小的前k个累加和
////子序列是包含空集的
////1 <= n <= 10 ^ 5
////1 <= nums[i] <= 10 ^ 6
////1 <= K <= 10 ^ 5
////注意这个数据量，用01背包的解法是不行的
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<unordered_set>
//
//using namespace std;
//
//class Solutions {
//public:
//	vector<long long> work(vector<int>& nums, int k) {
//		vector<long long> res;
//		// 处理空数组
//		if (nums.empty()) {
//			if (k >= 1) res.push_back(0);
//			return res;
//		}
//		// 空集是第一个最小和
//		if (k >= 1) {
//			res.push_back(0);
//			k--;
//		}
//		if (k == 0) return res;
//
//		sort(nums.begin(), nums.end());
//		int n = nums.size();
//		// 最小堆：{当前和, 最后选择的元素索引}
//		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeap;
//		// 去重集合：存储{当前和, 最后索引}的组合，避免重复入堆
//		unordered_set<long long> visited;
//
//		// 初始入堆：选择第一个元素
//		long long initialSum = nums[0];
//		minHeap.push({ initialSum, 0 });
//		visited.insert(initialSum * (n + 1) + 0); // 用哈希值唯一标识(和,索引)
//
//		while (k-- && !minHeap.empty()) {
//			auto [curSum, lastIdx] = minHeap.top();
//			minHeap.pop();
//			res.push_back(curSum);
//
//			// 只能选择后面的元素，保证子序列的有序性（避免重复子序列）
//			if (lastIdx + 1 < n) {
//				// 方案1：替换最后一个元素为下一个元素（如选了1，换成2）
//				long long sum1 = curSum - nums[lastIdx] + nums[lastIdx + 1];
//				long long key1 = sum1 * (n + 1) + (lastIdx + 1);
//				if (!visited.count(key1)) {
//					visited.insert(key1);
//					minHeap.push({ sum1, lastIdx + 1 });
//				}
//				// 方案2：在当前基础上添加下一个元素（如选了1，再加2）
//				long long sum2 = curSum + nums[lastIdx + 1];
//				long long key2 = sum2 * (n + 1) + (lastIdx + 1);
//				if (!visited.count(key2)) {
//					visited.insert(key2);
//					minHeap.push({ sum2, lastIdx + 1 });
//				}
//			}
//		}
//
//		return res;
//	}
//};
//
