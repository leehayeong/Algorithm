#include <cstdio>
#include <vector>

using namespace std;

/*
N�� �߿� M�� �̱�
���� ���� ���� �� ��� �ȴ�.
�񳻸����� (���� ũ�Ⱑ ���ʷ� �����ϰ�)
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