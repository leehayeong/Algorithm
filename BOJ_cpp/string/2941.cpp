#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	
	int i = 0;
	int cnt = 0;
	while(i < s.length()) {
		cnt++;
		if (s[i] == 'c') {
			if (s[i + 1] == '=' || s[i + 1] == '-') {
				i += 2;
				continue;
			}
		}
		
		if (s[i] == 'd') {
			if (s[i + 1] == 'z' && s[i + 2] == '=') {
				i += 3;
				continue;
			}
			if (s[i + 1] == '-') {
				i += 2;
				continue;
			}
		}

		if (s[i] == 'l' && s[i + 1] == 'j') {
			i += 2;
			continue;
		}

		if (s[i] == 'n' && s[i + 1] == 'j') {
			i += 2;
			continue;
		}

		if (s[i] == 's' && s[i + 1] == '=') {
			i += 2;
			continue;
		}

		if (s[i] == 'z' && s[i + 1] == '=') {
			i += 2;
			continue;
		}

		i++;
	}

	cout << cnt;
}