#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
쉬운 계단 수
인접한 모든 자리수의 차이가 1이 나는 수가 몇 개 있는지?

"마지막 자릿수"의 수를 보면 (7), 그 앞자리 수는 (6) 또는 (8)임을 알 수 있다.
또 그 앞자리 수는 (5)(7) / (7)(9) 이다. 이렇게 N자리 수가 될 때까지 반복한다.
*/

int N, dp[101][10];
const int MOD = 1000000000;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	// 한자리 수
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	
	// 두 자리수부터
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1] % MOD;
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
		dp[i][9] = dp[i - 1][8] % MOD;
	}

	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans = (ans + dp[N][i]) % MOD;
	}
	cout << ans % MOD;
}