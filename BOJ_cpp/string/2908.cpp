#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;

	string x, y;
	for (int i = 0, j = 2; i < 3; i++, j--) {
		x += a[j];
		y += b[j];
	}

	if (atoi(x.c_str()) > atoi(y.c_str())) cout << x;
	else cout << y;
}