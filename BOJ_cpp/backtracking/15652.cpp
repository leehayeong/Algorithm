#include <cstdio>
#include <vector>

using namespace std;

/*
N개 중에 M개 뽑기
같은 수를 여러 번 골라도 된다.
비내림차순 (수의 크기가 차례로 증가하게)
*/

int n, m;
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

	// m개 뽑기.
	// 같은 수를 여러 번 골라도 되므로, 
	// 이미 선택했는지 확인하기 위한 변수인 visited가 없어도 된다.
	for (int i = idx; i < n; i++) {
		v.push_back(i + 1);
		dfs(i, cnt + 1);
		v.pop_back();
	}
}

int main() {
	scanf("%d %d", &n, &m);
	dfs(0, 0);
}