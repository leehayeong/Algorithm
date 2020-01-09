#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/*
����� ��ġ = Ű x, ������ y = (x, y)
�� �� ũ�� ��ġ�� �� ũ��. �ϳ��� ũ�ٸ� �� �Ұ�.
�� ����� ��ġ ����� ����Ͽ� ����϶�.
*/

int main() { 
	// ī�� ���� N, �־��� �� M
	int N, x, y;
	scanf("%d", &N);

	vector<pair<int, int>> list;
	vector<int> result;

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		list.push_back(make_pair(x, y));
	}

	for (int i = 0; i < N; i++) {
		int rank = 1;

		for (int j = 0; j < N; j++) {
			if (i != j) {
				if (list[i].first < list[j].first
					&& list[i].second < list[j].second) {
					rank++;
				}
			}
		}

		result.push_back(rank);
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", result[i]);
	}
}