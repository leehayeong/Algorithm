#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	bool a[26];
	int t, cnt = 0;
	bool isGroup = true;
	string s;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		fill_n(a, 26, false);
		isGroup = true;

		for (int j = 0; j < s.length(); j++) {
			int index = (int)s[j] - 97;
			
			// ������ ���� ���ĺ��̸� ����ߴٰ� ǥ��
			if (!a[index]) {
				a[index] = true;
			}

			// �̹� �������� �ְ�, 
			// ���ӵ� ���ĺ��� �ƴϸ� (�� ���ĺ��� �ٸ� ���ڸ�) �׷� �ܾ� X
			else {
				if (s[j] != s[j - 1]) {
					isGroup = false;
					break;
				}
			}
		}

		if (isGroup) cnt++;
	}

	cout << cnt;
}