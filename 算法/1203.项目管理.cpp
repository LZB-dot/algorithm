//#include<iostream>
//#include<vector>
//#include<queue>
//#include<unordered_map>
//#include<unordered_set>
//#include<string>
//using namespace std;
//
//class Solution {
//private:
//    //项目图
//    vector<int> item_head, item_to, item_next;
//    int item_cnt;
//    vector<int> item_indegree;
//
//    //小组图
//    vector<int> group_head, group_to, group_next;
//    int group_cnt;
//    vector<int> group_indegree;
//    
//    // gp[g] 存储组g的所有项目
//    vector<vector<int>> gp;  
//
//    void Init(vector<int>& head, vector<int>& to, vector<int>& next_,
//        vector<int>& indegree, int& cnt, int n) {
//        head.assign(n, 0);  
//        to.clear();
//        next_.clear();
//        cnt = 0;
//        indegree.assign(n, 0);
//    }
//
//    void Add(vector<int>& head, vector<int>& to, vector<int>& next_,
//        vector<int>& indegree, int& cnt, int u, int v) {
//        cnt++;
//        if (cnt >= to.size()) {
//            to.resize(cnt + 1, -1);
//            next_.resize(cnt + 1, -1);
//        }
//        to[cnt] = v;
//        next_[cnt] = head[u];
//        head[u] = cnt;
//        indegree[v]++;
//    }
//
//    vector<int> tuopu(int n, const vector<int>& head, const vector<int>& to_,
//        const vector<int>& next_, vector<int>& in) {
//        queue<int> q;
//        //入度为0的节点入队
//        for (int i = 0; i < n; ++i) {
//            if (in[i] == 0) {
//                q.push(i);
//            }
//        }
//
//        vector<int> res;
//        while (!q.empty()) {
//            int tmp = q.front();
//            q.pop();
//            res.push_back(tmp);
//
//            // 遍历所有出边（链式前向星遍历）
//            for (int u = head[tmp]; u != 0; u = next_[u]) {
//                int v = to_[u];
//                if (--in[v] == 0) {
//                    q.push(v);
//                }
//            }
//        }
//
//        //有环判断：拓扑序长度等于节点数则无环
//        return res.size() == n ? res : vector<int>();
//    }
//
//public:
//    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
//        //item_head.clear();
//        //item_to.clear(); 
//        //item_next.clear();
//        //item_indegree.clear();
//        //item_cnt = 0;
//
//        //group_head.clear(); 
//        //group_to.clear(); 
//        //group_next.clear();
//        //group_indegree.clear(); 
//        //group_cnt = 0;
//        //gp.clear();
//
//        //所有项目归属到具体小组
//        vector<int> item_to_group(n);  // 项目i → 所属组g
//        int id = m - 1;      //初始最大组号（原始组0~m-1）
//        // 先初始化原始组
//        gp.resize(m);
//        for (int i = 0; i < n; ++i) {
//            if (group[i] == -1) {
//                id++;
//                item_to_group[i] = id;
//                gp.push_back({ i }); 
//            }
//            else {
//                item_to_group[i] = group[i];
//                gp[group[i]].push_back(i);
//            }
//        }
//        int total_groups = id + 1;  // 总组数（0~max_group_id）
//
//        Init(item_head, item_to, item_next, item_indegree, item_cnt, n);
//
//        unordered_set<string> group_edge_set;  // 组间边去重
//        Init(group_head, group_to, group_next, group_indegree, group_cnt, total_groups);
//
//        //构建项目依赖和组间依赖
//        for (int cur_item = 0; cur_item < n; ++cur_item) {
//            for (int pre_item : beforeItems[cur_item]) {  // pre_item → cur_item
//                //添加项目依赖边
//                Add(item_head, item_to, item_next, item_indegree, item_cnt, pre_item, cur_item);
//
//                //处理跨组依赖，添加小组间边
//                int pre_group = item_to_group[pre_item];
//                int cur_group = item_to_group[cur_item];
//                if (pre_group != cur_group) {
//                    string edge_key = to_string(pre_group) + "_" + to_string(cur_group);
//                    if (group_edge_set.count(edge_key)) 
//                        continue;  // 去重
//                    group_edge_set.insert(edge_key);
//                    // 添加小组依赖边：pre_group → cur_group
//                    Add(group_head, group_to, group_next, group_indegree, group_cnt, pre_group, cur_group);
//                }
//            }
//        }
//
//        //小组级拓扑排序
//        vector<int> group_in = group_indegree;
//        vector<int> group_order = tuopu(total_groups, group_head, group_to, group_next, group_in);
//        if (group_order.empty()) 
//            return {};  // 小组间有环，无解
//
//        //组内项目拓扑排序
//        vector<int> result;
//        //遍历每个小组g
//        for (int g : group_order) {
//            // 跳过空组（可能存在原始组无项目）
//            if (g >= gp.size() || gp[g].empty()) 
//                continue;
//            
//            //当前组所有项目
//            const vector<int>& items = gp[g];  // 当前组的所有项目
//
//            // 全局项目ID → 组内局部ID（比如组内项目5、7、9，映射为0、1、2）
//            unordered_map<int, int> local_id;
//            // 组内局部id → 全局项目id
//            vector<int> global_id;
//            //组内项目数
//            int k = items.size();
//
//            for (int i = 0; i < k; ++i) {
//                //对组内项目重编号成局部id
//                local_id[items[i]] = i;
//                //添加进组内项目原编号
//                global_id.push_back(items[i]);
//            }
//
//            // 初始化组内子拓扑
//            vector<int> sub_head(k, 0);
//            vector<int> sub_to, sub_next;
//            int sub_cnt = 0;
//            vector<int> sub_indegree(k, 0);
//
//            // 构建组内边
//            for (int u : items) {
//                //记录项目的局部id
//                int u_local = local_id[u];
//                // 遍历u的所有出边
//                for (int e = item_head[u]; e != 0; e = item_next[e]) {
//                    int v = item_to[e];
//                    // 仅保留组内边
//                    if (local_id.count(v)) {
//                        int v_local = local_id[v];
//                        Add(sub_head, sub_to, sub_next, sub_indegree, sub_cnt, u_local, v_local);
//                    }
//                }
//            }
//
//            //组内拓扑排序
//            vector<int> sub_in_copy = sub_indegree;
//            vector<int> local_order = tuopu(k, sub_head, sub_to, sub_next, sub_in_copy);
//            if (local_order.empty()) 
//                return {};
//
//            // 映射回全局项目id并加入结果
//            for (int local_id : local_order) {
//                result.push_back(global_id[local_id]);
//            }
//        }
//
//        return result.size() == n ? result : vector<int>();
//    }
//};
//
