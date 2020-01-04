#include <iostream>

using namespace std;

int arr[9];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	for (int i = 1; i <= 8; i++) {
		cin >> n;
		arr[i] = n;
	}

	for (int i = 1; i <= 7; i++) {
		if (abs(arr[i + 1] - arr[i]) != 1) {
			cout << "mixed\n";
			return 0;
		}
	}

	if (arr[1] == 1) cout << "ascending\n";
	else if (arr[1] == 8) cout << "descending\n";
}