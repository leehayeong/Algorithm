#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;		// ����� kg
	int X, Y;	// 3kg X��, 5kg Y��

	cin >> N;

	int remain = N; // ���� ��
	// Y�� �ִ��� ���� ���¿��� �����ϵ���.
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