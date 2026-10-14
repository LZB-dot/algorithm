//#include<iostream>  
//#include<vector>  
//#include<algorithm>  
//#include<string>
//using namespace std;  
//
//inline int read() {  
//   char c;  
//   int num = 0;  
//
//   while ((c = getchar()) == ' ' || c == '\n' || c == '\r');  
//
//   bool flag = false;  
//   if (c == '-')   
//       flag = true;  
//   else  
//       num = c - '0';  
//
//   while (isdigit(c = getchar()))   
//       num = num * 10 + c - '0';  
//
//   return flag ? -num : num;  
//}  
//
//int main() {  
//   int n = read();  
//   
//   vector<int>nums(n << 1);
//   for (int i = 0; i < n; ++i) {
//       nums[i] = read();
//       nums[i + n] = nums[i];
//   }
//
//   
//   int m = (n << 1);
//   int i = 0, j = 1;
//   int k = 0;
//   while (i < n && j < n && k < n) {
//       if (i == j) {
//           j++;
//           continue;
//       }
//
//       if (nums[i + k] == nums[j + k])
//           ++k;
//       else {
//           if (nums[i+k] > nums[j+k])
//               i = i + k + 1;
//           else
//               j = j + k + 1;
//           k = 0;
//       }
//   }
//
//   int t = min(i, j);
//   for (int x = t; x < t + n; ++x)
//       cout << nums[x] << " ";
//   cout << "\n";
//
//   return 0;
//}