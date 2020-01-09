#include <cstdio>
#include <iostream>

using namespace std;

/*
N의 분해합 = N + N의 각 자리수의 합
N은 분해합의 생성자
N이 주어졌을 때, 가장 작은 생성자?
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
	// 카드 개수 N, 주어진 수 M
	int N;
	scanf("%d", &N);

	// 분해합이 N인 index가 N의 생성자
	// 최초로 나타나는 index 출력
	for (int i = 1; i <= N; i++) {
		if (func(i) == N) {
			printf("%d", i);
			return 0;
		}
	}

	printf("0");
}