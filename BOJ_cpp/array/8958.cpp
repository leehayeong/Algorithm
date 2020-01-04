#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;

	string s;
	for (int i = 0; i < t; i++) {
		int cnt = 0;
		bool flag = true;
		int result = 0;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'O') {
				if (flag) cnt++;
				else cnt = 1;

				flag = true;
				result += cnt;
			}
			else {
				flag = false;
			}
		}

		cout << result << "\n";
	}
}