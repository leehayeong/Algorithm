/*
���� 2206
�� �μ��� �̵��ϱ�
(1,1)->(N,M) �ִܰ��
�� �Ѱ����� �μ��� ����
2019-10-01
*/

#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

#define MAX 1001
using namespace std;

// ��N, ��M, ���� �ν�����0, �ƴϸ�1�� ǥ���ϴ� 3�����迭.
int N, M;
int map[MAX][MAX];
int visited[MAX][MAX][2] = { 0, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

// ���� x,y ��ǥ�� ���� �ν����� üũ�ϴ� ���� check. (�μ��� 1, �ƴϸ� 0)
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

		// pop�� ���� n,m�� �����ߴٸ� ����
		if (x == N-1 && y == M-1) {
			return visited[N-1][M-1][check];
		}
		
		// pop�� ���� ��� Ȯ��
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				// ���� ����, �湮 ���ߴٸ�
				if (map[nx][ny] == 0 && visited[nx][ny][check] == 0) {
					visited[nx][ny][check] = visited[x][y][check] + 1;
					queue.push({ nx,ny,check });
				}

				// ���� �ְ�, ���� �μ� �� �ִٸ�
				if (map[nx][ny] == 1 && check == 0) {
					// ���� �μ���
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
	
	// �� �Է�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	// bfs ����
	printf("%d\n", bfs());

}