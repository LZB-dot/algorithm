//#include<iostream>
//#include<map> 
//using namespace std;
//
//class Solution {
//public:
//    string intToRoman(int num) {
//        map<int, string, greater<int>> romanMap;  
//        // 传入greater<int>，让map按键降序排序
//
//        romanMap[1] = "I";
//        romanMap[4] = "IV";
//        romanMap[5] = "V";
//        romanMap[9] = "IX";
//        romanMap[10] = "X";
//        romanMap[40] = "XL";
//        romanMap[50] = "L";
//        romanMap[90] = "XC";
//        romanMap[100] = "C";
//        romanMap[400] = "CD";
//        romanMap[500] = "D";
//        romanMap[900] = "CM";
//        romanMap[1000] = "M";
//
//        string result;
//        // 遍历map
//        for (auto& pair : romanMap) {
//            int val = pair.first;   
//            string c = pair.second; 
//
//            // 重复拼接，直到num小于当前数值
//            while (num >= val) {
//                result += c;
//                num -= val;
//            }
//            if (num == 0) 
//                break; 
//        }
//        return result;
//    }
//};