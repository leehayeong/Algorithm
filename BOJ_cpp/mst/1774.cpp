#include <iostream> 
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/*
우주신과의 교감
우주신 개수 N, 이미 연결된 통로 개수 M
*/

class Edge {
public:
	int a, b;
	double distance;
	Edge(int a, int b, double distance) {
		this->a = a;
		this->b = b;
		this->distance = distance;
	}
	bool operator <(Edge& e) {
		return this->distance < e.distance;
	}
};

int N, M, parent[1001];
pair<int, int> list[1001];	// 우주신들의 좌표 저장
vector<Edge> v;	// 연결된 통로 정보 저장

double calDistance(pair<int, int> a, pair<int, int> b) {
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	// 좌표 입력 후 거리 계산하여 리스트에 삽입
	for (int i = 1; i <= N; i++) {
		cin >> list[i].first >> list[i].second;
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = i + 1; j <= N; j++) {
			v.push_back(Edge(i, j, calDistance(list[i], list[j])));
		}
	}

	// 크루스칼 알고리즘
	sort(v.begin(), v.end());
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);	// 이미 연결된 통로 union
	}

	double sum = 0;
	int edge = 0, size = v.size();
	for (int i = 0; i < size; i++) {
		if (find(v[i].a) == find(v[i].b)) continue;	// cycle 생김
		merge(v[i].a, v[i].b);	// union
		sum += v[i].distance;
		edge++;
		if (edge == N - 1) break;	// 모두 연결 완료
	}

	cout.setf(ios::fixed);
	cout.precision(2);
	cout << sum;
}