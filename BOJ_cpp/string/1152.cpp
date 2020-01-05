#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	int cnt = 1;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') cnt++;
	}

	if (s[0] == ' ') cnt--;
	if (s[s.length() - 1] == ' ') cnt--;

	cout << cnt;
}