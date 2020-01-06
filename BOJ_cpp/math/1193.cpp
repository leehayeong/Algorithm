#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// N을 입력하면 해당하는 분수 출력
	long long N;		
	cin >> N;

	// N번째 수가 포함되어있는 지그재그의 첫 번재 수 찾기
	// N은 k(k+1)/2 부터 a 만큼 떨어져있음
	int k, a;
	for(k = 1; k * (k + 1) / 2 < N; k++) {
		a = N - k * (k + 1) / 2;
	}
	k--;

	// k(k+1)/2 가 짝수라면 아래로, 홀수라면 오른쪽으로
	int x, y;
	if (k % 2 == 0) {
		x = k + 1;
		y = 1;
		for (int i = 1; i < a; i++) {
			x--;
			y++;
		}
	}
	else {
		x = 1;
		y = k + 1;
		for (int i = 1; i < a; i++) {
			x++;
			y--;
		}
	}

	cout << x << "/" << y;
}