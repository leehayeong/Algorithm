#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t, n;
	string s;
	string result = "";

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> s;
		for (int j = 0; j < s.length(); j++) {
			for (int k = 0; k < n; k++) {
				result += s[j];
			}
		}
		cout << result << "\n";
		result = "";
	}	
}