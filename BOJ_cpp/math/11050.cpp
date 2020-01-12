#include <cstdio>

using namespace std;

/*
이항계수
(n k) = n! / k! (n-k)!
*/

int n, k, result;

int fact(int i) {
	if (i <= 1) return 1;

	int tmp = i;
	for (int j = i - 1; j > 0; j--) {
		tmp *= j;
	}

	return tmp;
}

int main() {
	scanf("%d %d", &n, &k);
	result = fact(n) / (fact(k) * fact(n - k));
	printf("%d", result);
}