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
			
			// 사용된적 없는 알파벳이면 사용했다고 표시
			if (!a[index]) {
				a[index] = true;
			}

			// 이미 사용된적이 있고, 
			// 연속된 알파벳이 아니면 (앞 알파벳과 다른 문자면) 그룹 단어 X
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