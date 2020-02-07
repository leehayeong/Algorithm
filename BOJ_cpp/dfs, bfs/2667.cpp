#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

/*
단지번호붙이기
이웃한 집들끼리 묶어 단지 번호를 붙인다.

입력
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

출력
3
7
8
9
*/

int N; // 지도 크기
int graph[25][25];
bool checked[25][25];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int cnt;
vector<int> result;

// dfs 탐색
void dfs(int x, int y) {
	if (checked[x][y]) return;

	// 방문하지 않았으면, 방문하고 인접 탐색
	checked[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 범위 벗어나면 종료
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (graph[nx][ny] == 1 && !checked[nx][ny]) {
			dfs(nx, ny);
			cnt++;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			graph[i][j] = s[j] - '0';
		}
	}

	// 첫 집 찾기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 1 && !checked[i][j]) {
				cnt++;
				dfs(i, j);

				// 한 단지에대한 모든 탐색이 끝남. 결과 저장하고 초기화
				result.push_back(cnt);
				cnt = 0;
			}
		}
	}

	// 결과 정렬하여 출력
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}