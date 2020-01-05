#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	
	int time = 0;
	for (int i = 0; i < s.length(); i++) {
		time += 2;
		switch (s[i]) {
		case 'A':
		case 'B':
		case 'C':
			time += 1;
			break;
		case 'D':
		case 'E':
		case 'F':
			time += 2;
			break;
		case 'G':
		case 'H':
		case 'I':
			time += 3;
			break;
		case 'J':
		case 'K':
		case 'L':
			time += 4;
			break;
		case 'M':
		case 'N':
		case 'O':
			time += 5;
			break;
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			time += 6;
			break;
		case 'T':
		case 'U':
		case 'V':
			time += 7;
			break;
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			time += 8;
			break;
		}
	}

	cout << time;
}