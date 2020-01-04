#include <iostream>
#include <vector>

using namespace std;


int num[10001] = { 0, };

// �Ѽ� �Ǻ�. ��, ���ڸ� ���� �� �ڸ����� ���̰� �������� �Ǻ�
bool isHansoo(int n) {
	// 1. �� �ڸ����� �� ����
	int one, two, three;
	one = (n / 10) / 10;
	two = (n / 10) % 10;
	three = n % 10;

	// 2. �ڸ������� ���� ���ϱ�
	int first, second;
	first = one - two;
	second = two - three;

	// 3. ���̰� ���� �� �Ѽ�
	if (first == second) return true;
	return false;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, result;
	cin >> n;

	// ���ڸ� ���� ������ �Ѽ��̴�.
	if (n < 100) {
		result = n;
		cout << result;
		return 0;
	}

	// ���ڸ� ������ ���
	result = 99;
	for (int i = 100; i <= n; i++) {
		//cout << "* " << i << "\t";
		if (isHansoo(i)) result++;
	}
	cout << result;
}