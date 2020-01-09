#include <cstdio>
#include <algorithm>

using namespace std;

// �ͷ�
// ������ x1, x2, r1, ���ȯ x2, y2, r2
// r1�� ���������κ��� ������� ���� �� �ִ� �Ÿ�. �� ���� ������
// r2�� ���������� ���ȯ�� ���� ������
// �������� ���� ���ȯ�� ���� ������ �� = ������� ���� �� �ִ� ��ǥ�� ��

int main() { 
	int t, x1, y1, r1, x2, y2, r2, result;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		result = 0;

		// 1. �� ���������� �Ÿ��� �������� ������ ���� ���Ѵ�. (�������� ��)
		int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		int rs = (r1 + r2) * (r1 + r2);
		int rm = (r1 - r2) * (r1 - r2);

		// 2. ������ ����. (�� ���� ��ġ�Ѵ�.)
		if (dist == 0 && r1 == r2) {
			result = -1;
		}

		// 3. ������ �ʴ´�.
		else if (dist == 0 || dist > rs) {
			result = 0;
		}

		// 4. �� ������ ������.
		else if (dist == rs || dist == rm) {
			result = 1;
		}

		// 5. �� ������ ������.
		else if (rm < dist && dist < rs) {
			result = 2;
		}

		printf("%d\n", result);
	}
}