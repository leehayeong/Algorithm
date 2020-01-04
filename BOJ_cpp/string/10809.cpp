#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int a[26];
	fill_n(a, 26, -1);
	// a는 아스키코드 97
	for (int i = 0; i < s.length(); i++) {
		int index = (int)s[i] - 97;
		if (a[index] == -1) a[index] = i;
	}

	for (int i = 0; i < 26; i++) {
		cout << a[i] << " ";
	}
}