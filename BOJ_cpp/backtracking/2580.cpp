#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
������ 9*9 1-9
1. ����üũ
2. ����üũ
3. �簢��üũ
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
		// �� �� �� ������ ���� ����� (���� k�� �ش��ϴ� ���� ��� false)
		if (!row[x][k] && !col[y][k] && !rect[((x / 3) * 3) + (y / 3)][k]) {
			row[x][k] = true;
			col[y][k] = true;
			rect[((x / 3) * 3) + (y / 3)][k] = true;
			
			// �� �ٲٰ�, ���� ��ĭ ä�췯
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

			// 0�̶�� ���� ä�����ϹǷ� ����
			if (input[i][j] == 0) {
				point.push_back(make_pair(i, j));
			}
			// 0�� �ƴ϶�� ���� �� üũ
			else {
				// �࿡�� ���� �� üũ
				row[i][input[i][j]] = true;

				// ������ ���� �� üũ
				col[j][input[i][j]] = true;

				// �簢������ ���� �� üũ 
				// (��->�Ʒ�, ����->������ ������ 0-9��)
				rect[((i / 3) * 3) + (j / 3)][input[i][j]] = true;
			}
		}
	}

	solve(0);
}