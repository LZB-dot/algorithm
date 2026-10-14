//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//const int N = 2e6;  // 增大数组容量，避免溢出
//int trie[N][2];
//int total = 1;
//int high;
//
//// 重置字典树
//void resetTrie() {
//    total = 1;
//    // 只需要重置已使用的节点，无需全部重置
//    for (int i = 1; i <= total; ++i) {
//        trie[i][0] = trie[i][1] = 0;
//    }
//}
//
//void insert(int num) {
//    int cur = 1;
//    for (int i = high; i >= 0; --i) {
//        int path = (num >> i) & 1;
//        if (trie[cur][path] == 0) {
//            trie[cur][path] = ++total;
//        }
//        cur = trie[cur][path];
//    }
//}
//
//// 确定最高位
//void setHigh(vector<int>& nums) {
//    int mx = INT_MIN;
//    for (int num : nums) {
//        mx = max(num, mx);
//    }
//    if (mx == 0) {
//        high = 0;
//    }
//    else {
//        high = 31 - __builtin_clz(mx);  // 计算最高有效位位置
//    }
//}
//
//int maxXor(int num) {
//    if (total == 1)
//        return INT_MIN;
//
//    int cur = 1;
//    int res = 0;
//    for (int i = high; i >= 0; --i)
//    {
//        int path = (num >> i) & 1;
//        int want = path ^ 1;  // 希望找到相反的位以最大化异或
//
//        // 如果希望的路径不存在，则使用相同的位
//        if (trie[cur][want] == 0)
//            want = path;
//        res |= (path ^ want) << i;
//        cur = trie[cur][want];
//    }
//    return res;
//}
//
//int findMaximumXOR(vector<int>& nums) 
//{
//    if (nums.size() < 2)
//        return 0; 
//
//    setHigh(nums);  // 先确定最高位
//    resetTrie();
//
//    int ans = INT_MIN;
//    insert(nums[0]);  // 先插入第一个元素
//
//    // 对于每个后续元素，先查询再插入，确保只与之前的元素比较
//    for (int i = 1; i < nums.size(); ++i)
//    {
//        ans = max(ans, maxXor(nums[i]));
//        insert(nums[i]);
//    }
//
//    return ans;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    cout << findMaximumXOR(nums) << endl;
//    return 0;
//}
