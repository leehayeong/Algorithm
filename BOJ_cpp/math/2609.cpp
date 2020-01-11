#include <cstdio>

using namespace std;

/*
최대공약수와 최소공배수

유클리드 호제법
두 수 a, b

a % b = c
b % c = d
c % d = e

나머지가 0일때까지 반복
루프가 종료되었을 때, 
최대공약수 = b, 최소공약수 = n * m / b
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