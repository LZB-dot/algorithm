//
////∞£ œ…∏
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int eratosthenes(int n) {
//	vector<bool>isPrime(n + 1, 1);
//	isPrime[0] = isPrime[1] = false;
//	for (int i = 2; i * i <= n; ++i) {
//		if (isPrime[i]) 
//			for (int j = i * i; j <= n; j += i) 
//				isPrime[j] = false;
//	}
//
//	int cnt = 0;
//	for (int i = 2; i <= n; ++i)
//		if (isPrime[i])
//			cnt++;
//
//	return cnt;
//}
//
//int euler(int n) {
//	vector<bool>isPrime(n + 1, true);
//	vector<int>primes;
//	isPrime[0] = isPrime[1] = false;
//
//	for (int i = 2; i <= n; ++i) {
//		if (isPrime[i]) {
//			primes.push_back(i);
//		}
//		for (int j = 0; j < primes.size() && primes[j] * i <= n; ++j) {
//			isPrime[i * primes[j]] = false;
//			if (i % primes[j] == 0)
//				break;
//		}
//	}
//
//	return primes.size();
//}
//
//class Solution {
//public:
//	int countPrimes(int n) {
//
//	}
//};