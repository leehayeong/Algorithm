#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
감시
사각지대의 최소 크기는?
*/

typedef struct {
	int num, dir;
	int x, y;
	int spreadMap[8][8];
}CCTV;

int N, M;
int map[8][8];

// cctv 조합을 위해 필요한 변수들
vector<CCTV> cctvs[8];
bool checked[8][4];
int countMap[8][8];
int answer = 64;

// CCTV 방향에 따른 모든 조합 구하기
void dfs(int idx, int cnt, int total_num) {
	// n개의 CCTV가 되면, 사각지대 수 구함
	if (cnt == total_num) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (countMap[i][j] == 0) cnt++;
			}
		}
		answer = min(answer, cnt);
		return;
	}

	for (int j = 0; j < cctvs[idx].size(); j++) {
		if (checked[idx][j] == false) {
			checked[idx][j] = true;
			CCTV cur = cctvs[idx][j];

			// 확산
			for (int p = 0; p < N; p++) {
				for (int q = 0; q < M; q++) {
					countMap[p][q] += cur.spreadMap[p][q];
				}
			}

			// 다음 CCTV 선택
			dfs(idx + 1, cnt + 1, total_num);

			// 복구
			checked[idx][j] = false;
			for (int p = 0; p < N; p++) {
				for (int q = 0; q < M; q++) {
					countMap[p][q] -= cur.spreadMap[p][q];
				}
			}
		}
	}
}

// 서
void west(int idx, int dir_num) {
	int x = cctvs[idx][dir_num].x;
	int y = cctvs[idx][dir_num].y;

	int ny = y - 1;
	while (ny >= 0 && map[x][ny] != 6) {
		cctvs[idx][dir_num].spreadMap[x][ny] = -1;
		ny--;
	}
}

// 동
void east(int idx, int dir_num) {
	int x = cctvs[idx][dir_num].x;
	int y = cctvs[idx][dir_num].y;

	int ny = y + 1;
	while (ny < M && map[x][ny] != 6) {
		cctvs[idx][dir_num].spreadMap[x][ny] = -1;
		ny++;
	}
}

// 북
void north(int idx, int dir_num) {
	int x = cctvs[idx][dir_num].x;
	int y = cctvs[idx][dir_num].y;

	int nx = x - 1;
	while (nx >= 0 && map[nx][y] != 6) {
		cctvs[idx][dir_num].spreadMap[nx][y] = -1;
		nx--;
	}
}

// 남
void south(int idx, int dir_num) {
	int x = cctvs[idx][dir_num].x;
	int y = cctvs[idx][dir_num].y;

	int nx = x + 1;
	while (nx < N && map[nx][y] != 6) {
		cctvs[idx][dir_num].spreadMap[nx][y] = -1;
		nx++;
	}
}

void spread(int num, int idx, int dir_num) {
	// 1번 CCTV
	if (num == 1) {
		if (dir_num == 0) {			// 동
			east(idx, dir_num);
		}
		else if (dir_num == 1) {	// 서
			west(idx, dir_num);
		}
		else if (dir_num == 2) {	// 남
			south(idx, dir_num);
		}
		else if (dir_num == 3) {	// 북
			north(idx, dir_num);
		}
	}

	// 2번 CCTV
	else if (num == 2) {
		if (dir_num == 0) {			// 동, 서
			east(idx, dir_num);
			west(idx, dir_num);
		}
		else if (dir_num == 1) {	// 남, 북
			south(idx, dir_num);
			north(idx, dir_num);
		}
	}

	// 3번 CCTV
	else if (num == 3) {
		if (dir_num == 0) {			// 북, 동
			north(idx, dir_num);
			east(idx, dir_num);
		}
		else if (dir_num == 1) {	// 동, 남
			east(idx, dir_num);
			south(idx, dir_num);
		}
		else if (dir_num == 2) {	// 남, 서
			south(idx, dir_num);
			west(idx, dir_num);
		}
		else if (dir_num == 3) {	// 서, 북
			west(idx, dir_num);
			north(idx, dir_num);
		}
	}

	// 4번 CCTV
	else if (num == 4) {
		if (dir_num == 0) {			// 북, 동, 남
			north(idx, dir_num);
			east(idx, dir_num);
			south(idx, dir_num);
		}
		else if (dir_num == 1) {	// 동, 남, 서
			east(idx, dir_num);
			south(idx, dir_num);
			west(idx, dir_num);
		}
		else if (dir_num == 2) {	// 남, 서, 북
			south(idx, dir_num);
			west(idx, dir_num);
			north(idx, dir_num);
		}
		else if (dir_num == 3) {	// 서, 북, 동
			west(idx, dir_num);
			north(idx, dir_num);
			east(idx, dir_num);
		}
	}

	// 5번 CCTV
	else if (num == 5) {	// 동, 서, 남, 북
		east(idx, dir_num);
		west(idx, dir_num);
		south(idx, dir_num);
		north(idx, dir_num);
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int wall = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 6) wall++;
		}
	}

	// cctv 가능한 종류만큼 다 퍼트려 저장
	int cctv_idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					cctvs[cctv_idx].push_back({ 1, k, i, j });
					cctvs[cctv_idx][k].spreadMap[i][j] = -1;
					spread(1, cctv_idx, k);
				}
				cctv_idx++;
			}
			else if (map[i][j] == 2) {
				for (int k = 0; k < 2; k++) {
					cctvs[cctv_idx].push_back({ 2, k, i, j });
					cctvs[cctv_idx][k].spreadMap[i][j] = -1;
					spread(2, cctv_idx, k);
				}
				cctv_idx++;
			}
			else if (map[i][j] == 3) {
				for (int k = 0; k < 4; k++) {
					cctvs[cctv_idx].push_back({ 3, k, i, j });
					cctvs[cctv_idx][k].spreadMap[i][j] = -1;
					spread(3, cctv_idx, k);
				}
				cctv_idx++;
			}
			else if (map[i][j] == 4) {
				for (int k = 0; k < 4; k++) {
					cctvs[cctv_idx].push_back({ 4, k, i, j });
					cctvs[cctv_idx][k].spreadMap[i][j] = -1;
					spread(4, cctv_idx, k);
				}
				cctv_idx++;
			}
			else if (map[i][j] == 5) {
				cctvs[cctv_idx].push_back({ 5, 0, i, j });
				cctvs[cctv_idx][0].spreadMap[i][j] = -1;
				spread(5, cctv_idx, 0);
				cctv_idx++;
			}
		}
	}

	// 가능한 모든 조합 계산
	dfs(0, 0, cctv_idx);

	answer -= wall;	// 벽개수도 마지막에 제외시켜 줌
	cout << answer;	
}
