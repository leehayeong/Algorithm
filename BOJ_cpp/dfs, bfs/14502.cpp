#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
연구소
벽 3개를 설치했을 때, 바이러스가 퍼지지않는 안전영역의 최대 크기는?
0 빈칸, 1 벽, 2 바이러스

1. 벽 3개를 세우고
2. 바이러스를 퍼트리고
3. 안전영역의 개수 구하기
*/

int N, M, ans;
int map[8][8], copyMap[8][8];
bool checked[64], visited[8][8];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<pair<int, int>> virus, zero; int vsize, zsize;

void mapCopy(int a[8][8], int b[8][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void spreadVirus() {
	queue<pair<int, int>> q;
	
	// 바이러스 동시에 퍼트리기 위해 모두 큐에 push
	for (int i = 0; i < vsize; i++) {
		q.push(make_pair(virus[i].first, virus[i].second));
		visited[virus[i].first][virus[i].second] = true;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny]) continue;
		
			if (copyMap[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				copyMap[nx][ny] = 2;
			}
		}
	}

	// 바이러스가 다 퍼지면 안전영역의 개수 세어 최댓값 갱신
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copyMap[i][j] == 0) cnt++;
		}
	}
	
	ans = max(ans, cnt);
}

void makeWall(int idx, int cnt) {
	// 3개 세웠으면 바이러스 퍼트리기
	if (cnt == 3) {
		memset(visited, false, sizeof(visited));
		mapCopy(copyMap, map);	// 바이러스 퍼트리기 전 맵 복사
		spreadVirus();			// 복사한 맵으로 조작
		return;
	}

	// 벽 3개 만들 수 있는 모든 조합 구하기
	for (int i = idx; i < zsize; i++) {
		if (checked[i]) continue;
		checked[i] = true;
		map[zero[i].first][zero[i].second] = 1;	// 벽 세우기
		makeWall(i, cnt + 1);
		checked[i] = false;
		map[zero[i].first][zero[i].second] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
			else if (map[i][j] == 0) zero.push_back(make_pair(i, j));
		}
	}
	
	vsize = virus.size();
	zsize = zero.size();
	makeWall(0, 0);

	cout << ans;
}