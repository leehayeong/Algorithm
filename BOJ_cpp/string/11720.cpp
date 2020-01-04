#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	string s;
	cin >> n >> s;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += s[i] - 48;
	}

	cout << sum;
}