#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// N�� �Է��ϸ� �ش��ϴ� �м� ���
	long long N;		
	cin >> N;

	// N��° ���� ���ԵǾ��ִ� ��������� ù ���� �� ã��
	// N�� k(k+1)/2 ���� a ��ŭ ����������
	int k, a;
	for(k = 1; k * (k + 1) / 2 < N; k++) {
		a = N - k * (k + 1) / 2;
	}
	k--;

	// k(k+1)/2 �� ¦����� �Ʒ���, Ȧ����� ����������
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