#include <cstdio>

using namespace std;

/*
링의 반지름이 주어졌을 때,
첫 번재 링을 한 바퀴 돌리면 나머지 링은 몇 바퀴 돌아가는지?
*/

int n, t;

// 유클리드 호제법에 의한 최대공약수 구하기
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

		// 최대공약수를 구하고,
		// first/최대공약수, t/최대공약수 로 나타낸다.
		int g = gcd(first, t);
		printf("g %d\n", g); 
		printf("%d/%d\n", first / g, t / g);
	}
}