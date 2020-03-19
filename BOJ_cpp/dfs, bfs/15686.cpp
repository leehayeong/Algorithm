#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

/*
치킨 배달
도시의 치킨 거리는 모든 집의 치킨 거리의 합. 
도시의 치긴 거리 최솟값은?

1. M개 치킨집 조합 구하기
2. 각 집별로 치킨집과의 거리 구하기
*/

int N, M;
int map[50][50];
vector<pair<int, int>> house, chicken;
bool checked[13];
int hsize, csize;
int ans = 1000000000;

int calDistance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int calDistanceSum() {
	int sum = 0;
	// 집이 치킨거리가 최소인 치킨집 선택
	for (int i = 0; i < hsize; i++) {
		int now = 1000000000;
		for (int j = 0; j < csize; j++) {
			if (checked[j] == true) {		// 선택된 치킨집에 대해서만 거리 계산
				now = min(now, calDistance(house[i].first, house[i].second, chicken[j].first, chicken[j].second));
			}
		}
		sum += now;
	}
	return sum;
}

void dfs(int idx, int cnt) {
	if (cnt == M) {
		// 치킨거리 계산
		ans = min(ans, calDistanceSum());
		return;
	}

	for (int i = idx; i < csize; i++) {
		if (checked[i] == false) {
			checked[i] = true;
			dfs(i, cnt + 1);
			checked[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;		// 폐업시키지 않을 치킨집 M개
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) house.push_back(make_pair(i, j));
			if (map[i][j] == 2) chicken.push_back(make_pair(i, j));
		}
	}
	hsize = house.size();
	csize = chicken.size();
	
	dfs(0, 0);
	cout << ans;
}