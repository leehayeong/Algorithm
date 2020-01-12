#include <cstdio>

using namespace std;

/*
���װ���� 10007�� ���� ������
(n k) = n! / k! (n-k)!
dp�� Ȱ��.
k == 0 �̶��? ���� 1 (n���� ��� ���� �ʴ� ������)
k == 1 �̶��? ���� n (n�� �� 1�� �̴� ������)
k == n �̶��? ���� 1 (n���� ��� �̴� ������)
dp[x][y] = dp[x-1][y-1] + dp[x-1][y]
*/

int n, k, result;
int dp[1001][1001];

int main() {
	scanf("%d %d", &n, &k);

	// 0��, 1�� ä���
	dp[0][0] = dp[1][0] = dp[1][1] = 1;

	// 2����ʹ� dp�� Ȱ���Ͽ� ä���
	// �� �� ���� �� ����. ������ + ��
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