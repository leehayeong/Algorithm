#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std;

/*
입력 정수 삼각형을 저장할 배열, 최대값을 저장할 배열 필요

각 행마다,
1열은		result[r][1] = num[r][1] + result[r-1][1]
마지막열은	result[r][n] = num[r][n] + result[r-1][n-1]
나머지열은	result[r][c] = num[r][c] + max(result[r-1][c], result[r-1][c-1])

가장 마지막열에서 가장 큰 값을 가지는 값이 구하고자 하는 최대값이다.
*/

int num[501][501];
int result[501][501];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> num[i][j];
		}
	}

	result[1][1] = num[1][1];
	for (int i = 2; i <= n; i++) {
		result[i][1] = num[i][1] + result[i - 1][1];

		for (int j = 2; j < i; j++) {
			result[i][j] = num[i][j] + max(result[i - 1][j], result[i - 1][j - 1]);
		}

		result[i][i] = num[i][i] + result[i - 1][i - 1];
	}

	// 가장 마지막열의 최대값을 구하면 된다.
	int max = result[n][1];
	for (int i = 2; i <= n; i++) {
		if (result[n][i] > max) max = result[n][i];
	}
	cout << max;
}