#include <string>
#include <vector>

using namespace std;

// 피보나치 수

int dp[100001];

int fib(int n) {
	if (n == 0 || n == 1) return n;
	if (dp[n] != 0) return dp[n];
	return dp[n] = (fib(n - 1) + fib(n - 2)) % 1234567;
}

int solution(int n) {
	int answer = fib(n);
	return answer;
}