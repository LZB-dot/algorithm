//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//class FreqStack {
//private:
//    int topTimes;
//    unordered_map<int, int>times;//键的出现次数
//    unordered_map<int, vector<int> >stackTimes;//频率为键的元素列表
//public:
//    FreqStack() {
//        topTimes = 0;//最大频率初始化为0
//    }
//
//    void push(int val) {
//        times[val]++;//该数频率++
//        int tmp = times[val];
//        stackTimes[tmp].push_back(val);//把该数添加进对应频率表
//        topTimes = max(tmp, topTimes);//更新最大频率
//    }
//
//    int pop() {
//        vector<int>& top = stackTimes[topTimes];//保存此频率下的数
//        int ans = top.back();//取最后一次添加进去的，即栈顶
//        top.pop_back();//删除掉最后的数
//        if (top.empty()) {//如果该频率下没数了，删除该频率
//            stackTimes.erase(topTimes);
//            topTimes--;//最高频率--
//        }
//        times[ans]--;//该数的频率--
//        if (times[ans] == 0) {//频率为0即不存在，删除
//            times.erase(ans);
//        }
//        return ans;
//    }
//};
