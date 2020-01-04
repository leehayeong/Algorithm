#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int arr[43] = { 0, };

	int a;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		arr[a % 42]++;
	}

	int cnt = 0;
	for (int i = 0; i < 43; i++) {
		if (arr[i] != 0) cnt++;
	}

	cout << cnt << "\n";
}