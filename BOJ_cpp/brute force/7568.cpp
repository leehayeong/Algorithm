#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/*
사람의 덩치 = 키 x, 몸무게 y = (x, y)
둘 다 크면 덩치가 더 크다. 하나만 크다면 비교 불가.
각 사람의 덩치 등수를 계산하여 출력하라.
*/

int main() { 
	// 카드 개수 N, 주어진 수 M
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