#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
포도주 시식
마실 수 있는 가장 많은 포도주의 양은?
연속으로 놓여있는 세 잔 모두 마실 수 없다.
1. 현재 포도주 + 전 포도주까지 누적
2. 현재 포도주 + 전 포도주 + 전전전 포도주까지 누적 (연속세잔 안되도록)
3. 현재 포도주 X = 전 포도주까지 누적
*/

int N, arr[10001], dp[10001];	


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= N; i++) {	
		// i번째 안마시는 경우.		i번째를 마시는 경우		
		// i - 1번째에서 끝			한 번 연속				두 번 연속
		dp[i] = max(dp[i - 1], max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]));
	}

	cout << dp[N];
}