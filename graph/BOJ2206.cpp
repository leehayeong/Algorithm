/*
백준 2206
벽 부수고 이동하기
(1,1)->(N,M) 최단경로
벽 한개까지 부수기 가능
2019-10-01
*/

#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

#define MAX 1001
using namespace std;

// 행N, 열M, 벽을 부쉈으면0, 아니면1로 표현하는 3차원배열.
int N, M;
int map[MAX][MAX];
int visited[MAX][MAX][2] = { 0, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

// 현재 x,y 좌표와 벽을 부쉈는지 체크하는 변수 check. (부수면 1, 아니면 0)
struct Point {
	int x, y, check;
};

int bfs() {
	queue<Point> queue;
	
	queue.push({ 0, 0, 0 });
	visited[0][0][0] = 1;

	while (!queue.empty()) {
		int x = queue.front().x;
		int y = queue.front().y;
		int check = queue.front().check;
		queue.pop();

		// pop한 것이 n,m에 도착했다면 종료
		if (x == N-1 && y == M-1) {
			return visited[N-1][M-1][check];
		}
		
		// pop한 것의 사방 확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				// 벽이 없고, 방문 안했다면
				if (map[nx][ny] == 0 && visited[nx][ny][check] == 0) {
					visited[nx][ny][check] = visited[x][y][check] + 1;
					queue.push({ nx,ny,check });
				}

				// 벽이 있고, 벽을 부술 수 있다면
				if (map[nx][ny] == 1 && check == 0) {
					// 벽을 부순다
					visited[nx][ny][1] = visited[x][y][check] + 1;
					queue.push({ nx,ny,1 });
				}
			}
		}
	}

	return -1;
}

int main(){
	scanf("%d %d", &N, &M);
	
	// 맵 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	// bfs 실행
	printf("%d\n", bfs());

}