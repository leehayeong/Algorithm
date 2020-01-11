#include <cstdio>
#include <vector>

using namespace std;

/*
N�� �߿� M�� �̱�
���� ���� ���� �� ��� �ȴ�.
*/

int n, m;
vector<int> v;

void dfs(int idx, int cnt) {
	// m�� �̱Ⱑ ������
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}

	// m�� �̱�.
	// ���� ���� ���� �� ��� �ǹǷ�, 
	// �̹� �����ߴ��� Ȯ���ϱ� ���� ������ visited�� ��� �ȴ�.
	for (int i = 0; i < n; i++) {
		v.push_back(i + 1);
		dfs(i + 1, cnt + 1);
		v.pop_back();
	}
}

int main() {
	scanf("%d %d", &n, &m);
	dfs(0, 0);
}