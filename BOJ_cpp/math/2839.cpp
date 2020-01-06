#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;		// 배달할 kg
	int X, Y;	// 3kg X개, 5kg Y개

	cin >> N;

	int remain = N; // 남은 양
	// Y가 최대한 많은 상태에서 시작하도록.
	for(int i = N; i >= 0; i -= 5) {
		Y = i / 5;
		if ((N - 5 * Y) % 3 == 0) {
			X = (N - 5 * Y) / 3;
			cout << X + Y;
			return 0;
		}
	}

	cout << -1;
}