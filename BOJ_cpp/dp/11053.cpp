#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
가장 긴 증가하는 부분 수열
*/

int N, n[1001], dp[1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> n[i];
		dp[i] = 1;	// 수열은 최소 길이 1
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (n[j] < n[i]) {					// 증가한다면
				dp[i] = max(dp[i], dp[j] + 1);	// 이전 길이 + 1 또는 지금 현재 길이 중 더 큰 것
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;
}


/*
* max비교 하는 이유
20 30 20 40 일 경우, dp[1] = 1, dp[2] = 2, dp[3] = 1 인 상태이다.
i = 4일 때, n[j] < n[i] 일 때 dp를 갱신하므로, j = 1, 2, 3 모두 40보다 작기 때문에 갱신하게 된다.
j = 1, dp[4] = 1
j = 2, dp[4] = 2 ---> 최댓값
j = 3, dp[4] = 1 ---> 다시 감소하면 안 됨!!
최대 길이를 구하는 것이므로 dp의 최댓값에 + 1 을 해야하기 때문에 max로 수열 길이의 최댓값을 저장하는 것이다.
*/