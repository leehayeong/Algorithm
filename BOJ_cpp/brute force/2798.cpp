#include <cstdio>

using namespace std;

// ����
// ī�� ���� 21�� ���� �ʴ� �ѵ� ������ ���� �ִ�� ũ��.
// ī�忡 ���� ����, ���� M�� ��ģ��.
// N���� ī�� �� 3���� ����. 
// ���� M���� �����鼭 M�� ���� ��������Ѵ�. ����?

int main() { 
	// ī�� ���� N, �־��� �� M
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