#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

/*
경사로
길이가 L인 경사로를 놓았을 때, 갈 수 있는 정상적인 길은?
세로로 볼 때는 회전시켜서 가로로 저장해놓고 탐색하면 더 효율적임.
*/

int N, L;
int map[200][100], length[200][100];
int answer;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	// 탐색 편하도록 회전시켜 맵 아래에 이어붙임
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[j + N][i] = map[i][j];
		}
	}

	for (int i = 0; i < 2 * N; i++) {
		length[i][0] = 1;
		for (int j = 1; j < N; j++) {
			// 2칸 이상 차이나면 경사로 놓아도 갈 수 없는 길
			if (abs(map[i][j - 1] - map[i][j]) >= 2) {
				length[i][N - 1] = -1;
				break;
			}

			// 평지
			if (map[i][j - 1] == map[i][j]) {
				length[i][j] = length[i][j - 1] + 1;
			}

			// 오르막 경사로 배치
			else if (map[i][j - 1] < map[i][j]) {
				// 이전까지 경사로를 놓을 수 있는 길이가 확보되면, 경사로 놓고 현재 1로 초기화
				if (length[i][j - 1] >= L) {
					length[i][j] = 1;
				}
				// 이전까지 누적 길이가 경사로를 놓아야하는 길이보다 짧으면 불가능
				else {
					length[i][N - 1] = -1;	// 갈 수 없음을 표시
					break;
				}
			}

			// 내리막 경사로 배치
			else if (map[i][j - 1] > map[i][j]) {
				// 거꾸로 L칸만큼 배치해야하므로, 첫 칸은 1 - L
				if (length[i][j - 1] >= 0) {
					length[i][j] = 1 - L;
				}
				// 0 미만일 땐 경사로 배치 불가 (이미 있기 때문)
				else {
					length[i][N - 1] = -1;
					break;
				}
			}
		}
		// 마지막 칸이 정상적이면 지나갈 수 있는 길
		if (length[i][N - 1] >= 0) answer++;
	}

	cout << answer;
}