#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int a[26], index;
	fill_n(a, 26, 0);
	for (int i = 0; i < s.length(); i++) {
		if (isupper(s[i])) index = (int)s[i] - 65;
		else index = (int)s[i] - 97;
		a[index]++;
	}

	int max = 0;
	int m_index;
	for (int i = 0; i < 26; i++) {
		if (a[i] > max) {
			max = a[i];
			m_index = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (i != m_index && a[i] == max) {
			cout << "?";
			return 0;
		}
	}
	
	cout << (char)(m_index + 65);

}