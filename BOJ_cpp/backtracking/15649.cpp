#include <cstdio>
#include <vector>

using namespace std;

/*
�ߺ� ���� �� ���� = ����
N�� �߿� M�� �̱�
*/

int n, m;
bool visited[8];
vector<int> v;

void dfs(int cnt) {
	// m�� �̱Ⱑ ������
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}

	// m�� �̱�
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		v.push_back(i + 1);
		dfs(cnt + 1);
		visited[i] = false;
		v.pop_back();
	}
}

int main() {
	scanf("%d %d", &n, &m);
	dfs(0);
}