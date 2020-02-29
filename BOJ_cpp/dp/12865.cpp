#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
평범한 배낭
N개의 불건, 무게 W, 가치 V, 최대무게 K
배낭에 넣을 수 있는 물건들의 가치의 최댓값?

dp[i][j] = i번째 보석까지 탐색하고, 무게가 j일 때 가치 
*/

int N, K;
int w[101], v[101], dp[101][100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> w[i];
		cin >> v[i];
	}

	for (int i = 1; i <= N; i++) {	// 보석i, 무게j(최대 K)
		for (int j = 1; j <= K; j++) {
			dp[i][j] = dp[i - 1][j];	// i번째 보석을 가져가지 않았다면, 이전 보석 무게 그대로에 가치도 그대로

			if (j - w[i] >= 0) {		
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);	// i번째 보석을 가져갔다면, 이전 보석 무게를 뺀 곳의 가치에 현재 가치를 더한 값 			
			}
		}
	}

	cout << dp[N][K];
}