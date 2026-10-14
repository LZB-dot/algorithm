//#include<iostream>
//#include<vector>
//#include<climits>
//#include<algorithm>
//#include<cstring> 
//using namespace std;
//
//const int MAXN = 2005;
//const int MAXV = 26;
//
//class Solution {
//private:
//    int n;
//    //ed记录末尾下标
//    //pre记录前一位下标
//    int ed[MAXV], pre[MAXN];
//    int tree[MAXN];
//
//    int help[MAXN];
//    int arr[MAXN];
//
//    inline int lowbit(int i) {
//        return i & -i;
//    }
//
//    inline void add(int p, int v) {
//        while (p <= n) {
//            tree[p] += v;
//            p += lowbit(p);
//        }
//    }
//
//    inline int sum(int p) {
//        int ans = 0;
//        while (p > 0) {
//            ans += tree[p];
//            p -= lowbit(p);
//        }
//        return ans;
//    }
//
//    //v字符添加一个j位置
//    //从尾巴插入
//    void push(int v, int j) {
//        pre[j] = ed[v];
//        ed[v] = j;
//    }
//
//    //将v字符的末尾取出，并删除
//    int pop(int v) {
//        int tmp = ed[v];
//        ed[v] = pre[ed[v]];
//        return tmp;
//    }
//
//    //一个序列变成有序序列，
//    //最少需要的相邻交换次数 = 这个序列的逆序对总数
//    int merge(int l, int m, int r) {
//        int ans = 0;
//
//        for (int i = m, j = r; i >= l; --i) {
//            while (j > m && arr[i] <= arr[j])
//                --j;
//            ans += j - m;
//        }
//
//        int i = l;
//        int a = l, b = m + 1;
//        while (a <= m && b <= r)
//            help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
//
//        while (a <= m)
//            help[i++] = arr[a++];
//        while (b <= r)
//            help[i++] = arr[b++];
//
//        for (i = l; i <= r; ++i)
//            arr[i] = help[i];
//
//        return ans;
//    }
//
//    int cal(int l, int r) {
//        if (l >= r)
//            return 0;
//        int m = l + ((r - l) >> 1);
//        return cal(l, m) + cal(m + 1, r) + merge(l, m, r);
//    }
//
//public:
//    int minMovesToMakePalindrome(string s) {
//        n = s.size();
//
//        memset(ed, 0, sizeof(ed));
//        memset(pre, 0, sizeof(pre));
//        memset(tree, 0, sizeof(tree));
//        memset(arr, 0, sizeof(arr));
//
//        //初始每个位置都为1，如果左侧放置了，则右侧对应位置的原来下标要标0
//        for (int i = 1; i <= n; ++i)
//            add(i, 1);
//
//        for (int i = 0; i < n; ++i)
//            push(s[i] - 'a', i + 1);
//
//        for (int l = 1; l <= n; ++l) {
//            if (arr[l] == 0) {
//                int r = pop(s[l - 1] - 'a');
//                if (l < r) {
//                    int k = sum(l);//查找左边放置位置
//                    arr[l] = k;
//                    arr[r] = n - k + 1;
//                }
//                else//奇数则在中间
//                    arr[l] = (n + 1) / 2;
//
//                add(r, -1);
//            }
//        }
//
//        return cal(1, n);
//    }
//};