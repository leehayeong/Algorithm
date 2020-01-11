#include <cstdio>

using namespace std;

/*
���� �������� �־����� ��,
ù ���� ���� �� ���� ������ ������ ���� �� ���� ���ư�����?
*/

int n, t;

// ��Ŭ���� ȣ������ ���� �ִ����� ���ϱ�
int gcd(int x, int y) {
	int a, b, c;
	a = x;
	b = y;

	while (true) {
		c = a % b;

		if (c == 0) break;

		a = b;
		b = c;
	}

	return b;
}

int main() {
	scanf("%d", &n);
	
	int first;
	scanf("%d", &first);

	for (int i = 1; i < n; i++) {
		scanf("%d", &t);

		// �ִ������� ���ϰ�,
		// first/�ִ�����, t/�ִ����� �� ��Ÿ����.
		int g = gcd(first, t);
		printf("g %d\n", g); 
		printf("%d/%d\n", first / g, t / g);
	}
}