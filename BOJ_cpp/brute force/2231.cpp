#include <cstdio>
#include <iostream>

using namespace std;

/*
N�� ������ = N + N�� �� �ڸ����� ��
N�� �������� ������
N�� �־����� ��, ���� ���� ������?
*/

int func(int n) {
	int sum = n;

	while (n > 0) {
		sum += n % 10;
		n = n / 10;
	}

	return sum;
}

int main() { 
	// ī�� ���� N, �־��� �� M
	int N;
	scanf("%d", &N);

	// �������� N�� index�� N�� ������
	// ���ʷ� ��Ÿ���� index ���
	for (int i = 1; i <= N; i++) {
		if (func(i) == N) {
			printf("%d", i);
			return 0;
		}
	}

	printf("0");
}