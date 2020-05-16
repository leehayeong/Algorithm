#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;
	vector<pair<int, int>> tmp;

	for (int i = 0; i < land.size() - 1; i++) {
		for (int j = 0; j < 4; j++) {
			tmp.push_back(make_pair(land[i][j], j));
		}

		sort(tmp.rbegin(), tmp.rend());

		int max = tmp[0].first;
		int idx = tmp[0].second;
		for (int k = 0; k < 4; k++) {
			if (idx == k) {
				max = tmp[1].first;
				idx = tmp[1].second;
			}

			land[i + 1][k] += max;

			max = tmp[0].first;
			idx = tmp[0].second;
		}

		tmp.clear();
	}

	for (int i = 0; i < 4; i++) {
		answer = max(answer, land[land.size() - 1][i]);
	}

	return answer;
}