#include <cstdio>

using namespace std;

/*
이항계수를 10007로 나눈 나머지
(n k) = n! / k! (n-k)!
dp를 활용.
k == 0 이라면? 답은 1 (n개를 모두 뽑지 않는 가짓수)
k == 1 이라면? 답은 n (n개 중 1개 뽑는 가짓수)
k == n 이라면? 답은 1 (n개를 모두 뽑는 가짓수)
dp[x][y] = dp[x-1][y-1] + dp[x-1][y]
*/

int n, k, result;
int dp[1001][1001];

int main() {
	scanf("%d %d", &n, &k);

	// 0행, 1행 채우기
	dp[0][0] = dp[1][0] = dp[1][1] = 1;

	// 2행부터는 dp를 활용하여 채우기
	// 이 전 행의 값 재사용. 위왼쪽 + 위
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				dp[i][j] = 1;
			} 
			else if (j == 1) {
				dp[i][j] = i;
			}
			else {
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
			}
		}
	}

	printf("%d", dp[n][k]);
}