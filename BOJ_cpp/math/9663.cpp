#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
n-queen
n*n ü���� ���� �� n���� ���� ������ �� ���� ���� ����� ����?

1. ù ��° ��, ���� ���Ҹ� ��ġ�Ѵ�. 
2. ���� �࿡�� ���� �ٸ���, ���� �밢���� ������ �ʴ´ٸ� ��ġ�Ѵ�.

3���� �迭 (����, �밢��1, �밢��2) �� ����� üũ
https://rebas.kr/761
*/

int n, cnt;
bool a[14];	// ������ [y]
bool b[27];	// �밢��1 [x+y]
bool c[27];	// �밢��2 [x-y+n-1]

void nQueen(int x) {
	// 8���� �� �������ٸ� ����
	if (x == n) {
		cnt++;
		return;
	}

	// �� ��ġ
	for (int y = 0; y < n; y++) {
		// ���� ��ġ�� �� ���ٸ� ���� ����
		if (a[y] || b[x + y] || c[x - y + n - 1]) {
			continue;
		}

		// ��ġ�� �� �ִٸ�, ��ġ�ϰ� ���� �� ��ġ
		a[y] = b[x + y] = c[x - y + n - 1] = true;
		nQueen(x + 1);
		a[y] = b[x + y] = c[x - y + n - 1] = false;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	nQueen(0);
	cout << cnt;
}