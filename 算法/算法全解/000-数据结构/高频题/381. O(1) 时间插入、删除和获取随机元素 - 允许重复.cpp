//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <unordered_set>
//#include <cstdlib>
//#include <ctime>
//using namespace std;
//
//class RandomizedCollection {
//private:
//    // 存储值到其所有索引的映射
//    unordered_map<int, unordered_set<int>> mpst;
//    // 存储所有元素，用于随机访问
//    vector<int> nums;
//
//public:
//    // 初始化随机数生成器
//    RandomizedCollection() {
//        srand(time(nullptr));
//    }
//
//    // 插入元素
//    // 如果元素不存在则返回true，否则返回false
//    bool insert(int val) {
//        // 检查元素是否已存在
//        bool isNew = mpst.find(val) == mpst.end() || mpst[val].empty();
//
//        // 将元素添加到向量末尾
//        nums.push_back(val);
//        // 记录新元素的索引
//        mpst[val].insert(nums.size() - 1);
//
//        return isNew;
//    }
//
//    // 删除元素
//    // 如果元素存在则返回true，否则返回false
//    bool remove(int val) {
//        // 检查元素是否存在
//        if (mpst.find(val) == mpst.end() || mpst[val].empty()) {
//            return false;
//        }
//
//        // 获取要删除元素的一个索引
//        int index = *mpst[val].begin();
//        // 获取最后一个元素的值和索引
//        int lastVal = nums.back();
//        int lastIndex = nums.size() - 1;
//
//        // 用最后一个元素覆盖要删除的元素
//        nums[index] = lastVal;
//
//        // 从映射中删除要删除元素的索引
//        mpst[val].erase(index);
//        // 如果该元素已无其他索引，从映射中移除该元素
//        if (mpst[val].empty()) {
//            mpst.erase(val);
//        }
//
//        // 更新最后一个元素的索引记录
//        mpst[lastVal].erase(lastIndex);
//        mpst[lastVal].insert(index);
//
//        // 删除向量的最后一个元素
//        nums.pop_back();
//
//        return true;
//    }
//
//    // 随机返回一个元素
//    // 每个元素被返回的概率与其出现次数线性相关
//    int getRandom() {
//        // 生成0到nums.size()-1之间的随机索引
//        int randomIndex = rand() % nums.size();
//        return nums[randomIndex];
//    }
//};
//
