#include <cstdio>

using namespace std;

// 블랙잭
// 카드 합이 21을 넘지 않는 한도 내에서 합을 최대로 크게.
// 카드에 양의 정수, 숫자 M을 외친다.
// N장의 카드 중 3장을 고른다. 
// 합이 M보다 작으면서 M과 가장 가까워야한다. 합은?

int main() { 
	// 카드 개수 N, 주어진 수 M
	int N, M, max;
	int card[100];

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &card[i]);
	}

	max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (i != j && j != k && k != i) {
					int sum = card[i] + card[j] + card[k];
					if (sum > max && sum <= M) {
						max = sum;
					}
				}
			}
		}
	}

	printf("%d\n", max);
}