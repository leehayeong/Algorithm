#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int apt[15][15];
	
	// 1층, 1호 가구 수 채우기
	for (int i = 0; i < 15; i++) {
		apt[0][i] = i + 1;
		apt[i][0] = 1;
	}

	// 나머지 가구 수 채우기
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 14; j++) {
			apt[i][j] = apt[i][j - 1] + apt[i - 1][j];
		}
	}

	int t, k, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		cout << apt[k][n - 1] << "\n";
	}
}