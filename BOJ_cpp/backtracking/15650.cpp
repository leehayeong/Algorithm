#include <cstdio>
#include <vector>

using namespace std;

/*
중복 없이 고른 수열, 고른 수열은 오름차순 = 조합
N개 중에 M개 뽑기
*/

int n, m;
bool visited[8];
vector<int> v;

void dfs(int idx, int cnt) {
	// m개 뽑기가 끝나면
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}

	// m개 뽑기. 기준점은 index부터.
	for (int i = idx; i < n; i++) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		v.push_back(i + 1);
		dfs(i, cnt + 1);
		visited[i] = false;
		v.pop_back();
	}
}

int main() {
	scanf("%d %d", &n, &m);
	dfs(0, 0);
}