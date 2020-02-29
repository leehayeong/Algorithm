#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
가장 긴 바이토닉 부분수열
증가수열 + 감소수열 최댓값 구하기!
*/

int N, n[1001], dp[1001], mdp[1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> n[i];
	}

	// 증가하는 부분수열 구하기
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;	// 수열은 최소 길이 1
		for (int j = 1; j <= i; j++) {
			if (n[j] < n[i] && dp[j] + 1 > dp[i]) {		// 증가하고, 최댓값이라면 갱신
				dp[i] =  dp[j] + 1;	
			}
		}
	}

	// 감소하는 부분수열 구하기
	for (int i = N; i >= 1; i--) {
		mdp[i] = 1;
		for (int j = N; j >= i; j--) {
			if (n[j] < n[i] && mdp[j] + 1 > mdp[i]) {
				mdp[i] = mdp[j] + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dp[i] + mdp[i] - 1);
	}
	cout << ans;
}

