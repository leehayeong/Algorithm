#include <cstdio>
#include <algorithm>

using namespace std;

/*
양수 A가 N의 진짜 약수라면,
1. N은 A의 배수
2. A != 1 && A != N
모든 약수가 주어질 때, N은?
*/

int n, a[50];

int main() {
	scanf("%d", &n);
	int mul = 1;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	// 가장 작은 약수와 가장 큰 약수를 곱하면 원래의 수가 나온다.
	sort(a, a + n);
	mul = a[0] * a[n - 1];

	printf("%d", mul);
}