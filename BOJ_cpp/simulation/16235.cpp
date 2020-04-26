#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

/*
 나무 재테크
 k년 후, 살아있는 나무 수는?
*/

int N, M, K;
int map[10][10], add[10][10];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
deque<int> live[10][10];
queue<int> dead[10][10];


// 봄. 나이만큼 양분 먹고, 나이 + 1
void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int size = live[i][j].size();
			for (int k = 0; k < size; k++) {
				int age = live[i][j].front();
				live[i][j].pop_front();

				// 양분 먹을 수 있으면 나이 증가
				if (map[i][j] >= age) {
					map[i][j] -= age;
					live[i][j].push_back(age + 1);	// 나이가 더 커지므로 뒤에 push
				}
				// 먹을 수 없으면 죽음
				else {
					dead[i][j].push(age);
				}
			}
		}
	}
}

// 여름. 죽은 나무를 (나이/2) 만큼 양분으로.
void summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			while (!dead[i][j].empty()) {
				map[i][j] += dead[i][j].front() / 2;
				dead[i][j].pop();
			}
		}
	}
}

// 가을. 나이가 5의 배수인 나무들을 8방향으로 번식
void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int size = live[i][j].size();
			for (int k = 0; k < size; k++) {
				int age = live[i][j][k];

				// 8방향 번식
				if (age % 5 == 0) {
					for (int dir = 0; dir < 8; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						live[nx][ny].push_front(1);		// 가장 적은 나이이므로 앞에 push
					}
				}
			}
		}
	}
}

// 겨울. 양분 추가
void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] += add[i][j];
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;

	// 양분 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> add[i][j];
			map[i][j] = 5;
		}
	}

	// 나무 심기
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		live[x - 1][y - 1].push_front(z);
	}

	// k년만큼 반복
	while (K--) {
		spring();
		summer();
		fall();
		winter();
	}

	// 살아있는 나무 수
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (live[i][j].empty()) continue;
			cnt += live[i][j].size();
		}
	}
	cout << cnt;
}