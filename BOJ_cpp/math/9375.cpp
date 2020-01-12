#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

/*
�мǿ� ������
�ǻ� �� n / �ǻ� �̸��� ���� 
������ ���� ���� ���� + 1(���Դ� ����� ��)�� ��� ���� ��, �˸��� ������ 1�� ���ش�.
*/

int t;
int n;				// �ǻ� ��
map<string, int> m;	// �ǻ� �з�, ����

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	
	while (t--){
		cin >> n;
		m.clear();

		for (int i = 0; i < n; i++) {
			string name, type;
			cin >> name >> type;

			m[type]++;
		}

		long long mul = 1;
		map<string, int>::iterator i;
		for (i = m.begin(); i != m.end(); i++) {
			mul *= (long long)i->second + 1;
		}

		cout << mul - 1 << "\n";
	}
}