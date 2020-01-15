#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
스도쿠 9*9 1-9
1. 가로체크
2. 세로체크
3. 사각형체크
*/

int input[9][9];
bool row[10][10];
bool col[10][10];
bool rect[10][10];
vector<pair<int, int>> point;

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << input[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve(int i) {
	if (i == point.size()) {
		print();
		exit(0);
	}

	int x = point[i].first;
	int y = point[i].second;
	for (int k = 1; k <= 9; k++) {
		// 세 곳 다 나오지 않은 수라면 (숫자 k에 해당하는 값이 모두 false)
		if (!row[x][k] && !col[y][k] && !rect[((x / 3) * 3) + (y / 3)][k]) {
			row[x][k] = true;
			col[y][k] = true;
			rect[((x / 3) * 3) + (y / 3)][k] = true;
			
			// 수 바꾸고, 다음 빈칸 채우러
			input[x][y] = k;
			solve(i + 1);

			row[x][k] = false;
			col[y][k] = false;
			rect[((x / 3) * 3) + (y / 3)][k] = false;
			input[x][y] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> input[i][j];

			// 0이라면 수를 채워야하므로 저장
			if (input[i][j] == 0) {
				point.push_back(make_pair(i, j));
			}
			// 0이 아니라면 나온 수 체크
			else {
				// 행에서 나온 수 체크
				row[i][input[i][j]] = true;

				// 열에서 나온 수 체크
				col[j][input[i][j]] = true;

				// 사각형에서 나온 수 체크 
				// (위->아래, 왼쪽->오른쪽 순으로 0-9번)
				rect[((i / 3) * 3) + (j / 3)][input[i][j]] = true;
			}
		}
	}

	solve(0);
}