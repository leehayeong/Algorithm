#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// ���� +Am, �㿡 -Bm, ����� ���� Vm
	long long A, B, V;
	cin >> A >> B >> V;

	long long day;
	if ((V - A) % (A - B) == 0) day = (V - A) / (A - B) + 1;
	else day = (V - A) / (A - B) + 2;

	// ��ĥ �ɸ����� ���
	cout << day;
}

/*
�ð��ʰ� �ڵ�

	// day�� �� ���� ���̰� Vm�� �� ������ Ȯ���ϸ� �������� ����.
	while (true) {
		// 1. �Ϸ簡 ����
		day++;

		// 2. ���� Am��ŭ �ö�
		now += A;

		// 3. ���� �ö��� ��, �� �ö󰬴ٸ�(�������뺸�� ����) ����
		if (now >= V) break;

		// 4. �ƴ϶�� ���� ���Ƿ� �ٽ� Bm��ŭ ������
		now -= B;
	}
*/