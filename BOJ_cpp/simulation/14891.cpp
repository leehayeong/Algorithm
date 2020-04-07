#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

/*
톱니바퀴
톱니바퀴를 회전할 때, 마지막 상태의 점수 합은?

n번 톱니바퀴를 어느쪽으로 회전하는지가 중요
가장 북쪽이 0번 index, 이후 오른쪽 방향으로 1번~7번
*/

int K, answer;
int arr[5][8];	// 톱니바퀴 4개(각 8칸)
bool checked[5];

// 회전
void rot(int n, int dir) {
	// 왼쪽 (반시계)
	if (dir == -1) {
		int temp = arr[n][0];
		for (int i = 0; i < 7; i++) {
			arr[n][i] = arr[n][i + 1];
		}
		arr[n][7] = temp;
	}

	// 오른쪽 (시계)
	else if (dir == 1) {
		int temp = arr[n][7];
		for (int i = 7; i > 0; i--) {
			arr[n][i] = arr[n][i - 1];
		}
		arr[n][0] = temp;
	}
}

// 주변 톱니바퀴와 확인 (같은극이면 반대방향으로 회전)
void check(int n, int dir) {
	int next;
	int ndir = dir * -1;
	checked[n] = true;

	// 1번 2번
	if (n == 1 || n == 2) {
		if (n == 1) next = 2;
		else if (n == 2) next = 1;

		if (checked[next] == false && arr[1][2] != arr[2][6]) {
			check(next, ndir);
			rot(next, ndir);
		}
	}

	// 2번 3번
	if (n == 2 || n == 3) {
		if (n == 2) next = 3;
		else if (n == 3) next = 2;

		if (checked[next] == false && arr[2][2] != arr[3][6]) {
			check(next, ndir);
			rot(next, ndir);
		}
	}

	// 3번 4번
	if (n == 3 || n == 4) {
		if (n == 3) next = 4;
		else if (n == 4) next = 3;

		if (checked[next] == false && arr[3][2] != arr[4][6]) {
			check(next, ndir);
			rot(next, ndir);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 1; i <= 4; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < 8; j++) {
			arr[i][j] = input[j] - '0';
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int n, dir;
		cin >> n >> dir;
		memset(checked, false, sizeof(checked));		
		check(n, dir);	// 주변 톱니바퀴 체크
		rot(n, dir);	// 회전
	}

	// 점수계산
	for (int i = 0; i < 4; i++) {
		if (arr[i + 1][0] == 1) answer += pow(2, i);
	}

	cout << answer;
}


/*
	cout << n << "번 회전 " << dir << "\n";
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
*/