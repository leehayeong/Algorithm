#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

/*
연산자 끼워넣기
*/

int N, ssize;
int num[11], symbol[4];
int vmax = -1000000000, vmin = 1000000000;

void dfs(int nidx, int result) {
	// 마지막 연산자면 최대, 최소 갱신
	if (nidx == N) {
		vmax = max(vmax, result);
		vmin = min(vmin, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		// 심볼에 현재 연산자와 다음 수 계산
		if (symbol[i] != 0) {
			int ret = result;
			if (i == 0) ret += num[nidx];
			else if (i == 1) ret -= num[nidx];
			else if (i == 2) ret *= num[nidx];
			else if (i == 3) ret /= num[nidx];

			symbol[i]--;
			dfs(nidx + 1, ret);
			symbol[i]++;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> symbol[i];
	}

	dfs(1, num[0]);	// 다음 숫자 index, 결과

	cout << vmax << "\n" << vmin;
}