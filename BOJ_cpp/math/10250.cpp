#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// ���̽� T, ���� H, �� �� W, �մ� N
	int T, H, W, N, result;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		result = 0;

		// ��������� �ƴϸ�,
		// �մ� % �� �� = YY��
		// (�մ� / �� ��) + 1 = XXȣ
		if (N % H != 0) {
			result = (N % H) * 100;
			result += N / H + 1;
		}
		// ����� ���̸� �׻� H_Xȣ (ȣ���� �մ� / �� ��)
		else {
			result = H * 100;
			result += N / H;
		}

		cout << result << "\n";
	}
}