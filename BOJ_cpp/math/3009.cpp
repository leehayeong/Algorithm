#include <cstdio>
#include <algorithm>

using namespace std;

// ���簢������ �� ���� �ָ�, ������ �� ���� ������� ã��

int main() {
	int rect[3][2];
	int dx, dy;
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &rect[i][0], &rect[i][1]);
	}

	// �������� �����ϴ� x, y ã��
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			if (rect[i][0] == rect[j][0]) {
				dx = rect[i][0];
			}

			if (rect[i][1] == rect[j][1]) {
				dy = rect[i][1];
			}
		}
	}

	// �� �� �� ������ �����ϴ� x, y�� ������ ���� ���� �� ������ ��
	int rx, ry;
	for (int i = 0; i < 3; i++) {
		if (rect[i][0] != dx) rx = rect[i][0];
		if (rect[i][1] != dy) ry = rect[i][1];
	}

	printf("%d %d", rx, ry);
}