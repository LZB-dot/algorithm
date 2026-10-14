//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<cstdlib>
//using namespace std;
//
//class RandomizedSet {
//private:
//    unordered_map<int, int> mp;  // 键：元素值，值：元素在vector中的索引
//    vector<int> nums;            // 存储实际元素，支持O(1)随机访问
//public:
//    RandomizedSet() {
//        srand(time(nullptr));  // 初始化随机数种子，确保每次运行结果不同
//    }
//
//    bool insert(int val) {
//        // 元素已存在，插入失败
//        if (mp.count(val)) {
//            return false;
//        }
//        // 元素不存在：vector尾部插入，哈希表记录索引
//        mp[val] = nums.size();
//        nums.push_back(val);
//        return true;
//    }
//
//    bool remove(int val) {
//        // 元素不存在，删除失败
//        if (!mp.count(val)) {
//            return false;
//        }
//        //获取目标元素的索引和vector最后一个元素的值
//        int delIndex = mp[val];
//        int lastVal = nums.back();
//
//        //用最后一个元素覆盖目标元素
//        nums[delIndex] = lastVal;
//        //更新哈希表中“最后一个元素”的新索引
//        mp[lastVal] = delIndex;
//
//        //从哈希表中删除目标元素
//        mp.erase(val);
//        //删除vector的最后一个元素
//        nums.pop_back();
//
//        return true;
//    }
//
//    int getRandom() {
//        //用double转换+rand()实现更均匀的随机数（可选）
//        int randIndex = rand() / (double)RAND_MAX * nums.size();
//        return nums[randIndex];
//    }
//};
//
//
