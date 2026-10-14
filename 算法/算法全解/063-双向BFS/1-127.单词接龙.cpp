
////https://leetcode.cn/problems/word-ladder/description/
//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<unordered_set>
//using namespace std;
//
//class Solution {
//public:
//    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//
//        unordered_set<string>vis(wordList.begin(), wordList.end());
//        if (vis.find(endWord) == vis.end())
//            return 0;
//
//        unordered_set<string>small, big, nxt;
//
//        small.insert(beginWord);
//        big.insert(endWord);
//        
//
//        for (int len = 1; !small.empty(); ++len) {
//            
//            for (auto& s : small) {
//                string word = s;
//
//                for (int j = 0; j < word.size(); ++j) {
//                    char old = word[j];
//                    for (char c = 'a'; c <= 'z'; ++c) {
//                        if (c == old)
//                            continue;
//
//                        word[j] = c;
//
//                        if (big.count(word)) 
//                            return len;
//                        
//                        if (vis.count(word)) {
//                            vis.erase(word);
//                            nxt.insert(word);
//                        }
//
//                        word[j] = old;
//                    }
//                }
//            }
//
//            if (nxt.size() < big.size())
//                small = nxt;
//            else {
//                small = big;
//                big = nxt;
//            }
//
//            nxt.clear();
//        }
//
//        return 0;
//    }
//};