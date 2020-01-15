#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
검문
숫자 n개를 종이에 적고, m으로 나누었을 때
나머지가 모두 같게되는 m을 모두 찾아라.

num[i] = M * 몫1 + 나머지
여기서 나머지가 같으려면 다른 수를 뺐을 때 나머지가 사라져야 한다.
num[i+1] = M * 몫2 + 나머지

num[i] - num[i+1] = M * (몫1 - 몫2)

3, 19, 27일 때
19 = 8 * 2 + 3
27 = 8 * 3 + 3
여기서 8이 최대공약수 
M은 최대공약수의 약수 (1 제외) = 2, 4, 8
*/

int n;
long long m;
long long num[100];
vector<long long> v;

long long gcd(long long x, long long y) {
	int a, b, c;
	a = x;
	b = y;

	while (true) {
		c = a % b;

		if (c == 0) break;

		a = b;
		b = c;
	}

	return b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	
	// 입력받은 모든 수의 차이의 최대공약수 구하기
	m = num[1] - num[0];
	for (int i = 2; i < n; i++) {
		m = gcd(num[i] - num[i - 1], m);
	}

	// 구한 최대공약수의 약수
	int i;
	for (i = 2; i * i < m; i++) {
		if (m % i == 0) {
			v.push_back(i);		// 약수
			v.push_back(m / i);	// 쌍을 이루는약수
		}
	}
	if (i * i == m) v.push_back(i);
	v.push_back(m);

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}