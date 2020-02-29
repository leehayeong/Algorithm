#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
전깃줄
시작 위치로 정렬하고, 도착 위치가 증가하는 부분 수열이 아닌 만큼 없앤다.
*/

int N, dp[101];
vector<pair<int, int>> v;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());	// pair의 first로 정렬 됨

	// 증가하는 부분수열 구하기
	int length = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < N; j++) {
			if (v[j].second < v[i].second && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		length = max(length, dp[i]);
	}

	cout << N - length;
}