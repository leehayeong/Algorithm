#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
체스판 다시 칠하기
체스판을 만들기 위해 지민이가 다시 칠해야 하는 사각형의 최소 개수는?
*/

int N, M;
char map[50][50];
char BLACK[50][50] = { 
{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
};
char WHITE[50][50] = {
{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' },
{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B' },
{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W' }
};

int calCnt(int x, int y) {
	int black = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (BLACK[i][j] != map[i + x][j + y]) black++;
		}
	}

	int white = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (WHITE[i][j] != map[i + x][j + y]) white++;
		}
	}

	return min(black, white);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j];
		}
	}

	int ans = 1000000000;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			ans = min(ans, calCnt(i, j));
		}
	}

	cout << ans;
}