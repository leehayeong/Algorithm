#include <cstdio>

using namespace std;

/*
�ִ������� �ּҰ����

��Ŭ���� ȣ����
�� �� a, b

a % b = c
b % c = d
c % d = e

�������� 0�϶����� �ݺ�
������ ����Ǿ��� ��, 
�ִ����� = b, �ּҰ���� = n * m / b
*/

int n, m;

int main() {
	scanf("%d %d", &n, &m);
	int a, b, c;
	a = n;
	b = m;

	while (true) {
		c = a % b;	// a % b = c
		
		if (c == 0) break;

		// b % c = d;
		a = b;		
		b = c;
	}

	printf("%d\n", b);
	printf("%d\n", n * m / b);
}