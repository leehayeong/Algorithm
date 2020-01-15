#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
n-queen
n*n 체스판 위에 퀸 n개를 서로 공격할 수 없게 놓는 경우의 수는?

1. 첫 번째 행, 열에 원소를 배치한다. 
2. 다음 행에서 열이 다르고, 같은 대각선에 속하지 않는다면 배치한다.

3개의 배열 (세로, 대각선1, 대각선2) 을 만들고 체크
https://rebas.kr/761
*/

int n, cnt;
bool a[14];	// 세로줄 [y]
bool b[27];	// 대각선1 [x+y]
bool c[27];	// 대각선2 [x-y+n-1]

void nQueen(int x) {
	// 8개가 다 놓아졌다면 종료
	if (x == n) {
		cnt++;
		return;
	}

	// 퀸 배치
	for (int y = 0; y < n; y++) {
		// 퀸을 배치할 수 없다면 다음 경우로
		if (a[y] || b[x + y] || c[x - y + n - 1]) {
			continue;
		}

		// 배치할 수 있다면, 배치하고 다음 퀸 배치
		a[y] = b[x + y] = c[x - y + n - 1] = true;
		nQueen(x + 1);
		a[y] = b[x + y] = c[x - y + n - 1] = false;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	nQueen(0);
	cout << cnt;
}