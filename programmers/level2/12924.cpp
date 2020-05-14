#include <string>
#include <vector>

using namespace std;

/* 
숫자의 표현
연속된 자연수들로 n을 표현하는 방법의 수
*/

int ans = 0;

void dfs(int i, int sum, int n) {
	if (sum == n) {
		ans++;
		return;
	}
	else if (sum > n) {
		return;
	}

	dfs(i + 1, sum + i, n);
}

int solution(int n) {
	int answer = 0;

	for (int i = 1; i <= n; i++) {
		dfs(i, 0, n);
	}

	answer = ans;
	return answer;
}