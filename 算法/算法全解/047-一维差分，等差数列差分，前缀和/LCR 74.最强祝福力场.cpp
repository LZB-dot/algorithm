//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//class Solution {
//public:
//    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
//        int n = forceField.size();
//        vector<long long>xs, ys;
//        for (auto& f : forceField) {
//            long long x = f[0], y = f[1], r = f[2];
//            //避免小数
//            xs.push_back((x << 1) - r);
//            xs.push_back((x << 1) + r);
//            ys.push_back((y << 1) - r);
//            ys.push_back((y << 1) + r);
//        }
//
//        auto dis = [](vector<long long>& nums) {
//            sort(nums.begin(), nums.end());
//            //unique会将容器中相邻的重复元素 “移除”
//            //实际是将不重复的元素移到前面，返回指向最后一个不重复元素之后的迭代器
//            //erase删除从unique返回的迭代器位置到容器末尾的元素
//            nums.erase(unique(nums.begin(), nums.end()), nums.end());
//            return (int)nums.size();
//            };
//
//        //对坐标x和y分别排序去重
//        int sizex = dis(xs);
//        int sizey = dis(ys);
//
//        //二分查找第一个大于v的位置，返回离散化坐标
//        auto rank = [&](vector<long long>& nums, long long v) {
//            int l = 0, r = nums.size() - 1;
//            int ans = 0;
//            while (l <= r) {
//                int m = (l + r) / 2;
//                if (nums[m] >= v) {
//                    ans = m;
//                    r = m - 1;
//                }
//                else {
//                    l = m + 1;
//                }
//            }
//            return ans + 1;
//            };
//
//        vector<vector<int>>diff(sizex + 2, vector<int>(sizey + 2, 0));
//
//        for (auto& f : forceField) {
//            long long x = f[0], y = f[1], r = f[2];
//            //
//            long long left = (x << 1) - r, right = (x << 1) + r;
//            long long bottom = (y << 1) - r, top = (y << 1) + r;
//            int a = rank(xs, left);
//            int b = rank(ys, bottom);
//            int c = rank(xs, right);
//            int d = rank(ys, top);
//            diff[a][b]++;
//            diff[c + 1][d + 1]++;
//            diff[c + 1][b]--;
//            diff[a][d + 1]--;
//        }
//
//        int ans = 0;
//        for (int i = 1; i <= sizex; ++i) {
//            for (int j = 1; j <= sizey; ++j) {
//                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
//                ans = max(ans, diff[i][j]);
//            }
//        }
//
//        return ans;
//    }
//};