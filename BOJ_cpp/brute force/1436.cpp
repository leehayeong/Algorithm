#include <cstdio>
#include <string>

using namespace std;

/*
������ ���� 666
ù ��° 666, �� �� ° 1666, ...��������
N��° ����?
*/


int main() { 
	int cnt = 0;
	int n, i;

	scanf("%d", &n);

	// i���� 666�� ã�� ������ count++
	for (i = 666; ; i++) {
		if (to_string(i).find("666") != -1) {
			cnt++;
			if (cnt == n) break;
		}
	}

	printf("%d", i);
}