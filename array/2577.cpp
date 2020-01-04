#include <iostream>

using namespace std;

int arr[8];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int arr[10] = { 0, };

	int a, b, c;
	cin >> a >> b >> c;
	int mul = a * b * c;
	
	while (true) {
		arr[mul % 10]++;
		if (mul / 10 == 0) break;
		mul = mul / 10;
	}

	for (int i = 0; i < 10; i++) cout << arr[i] << "\n";
}