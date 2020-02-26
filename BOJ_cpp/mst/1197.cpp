#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
최소 스패닝 트리
*/

class Edge {
public:
	int a, b, distance;
	Edge(int a, int b, int distance) {
		this->a = a;
		this->b = b;
		this->distance = distance;
	}
	bool operator <(Edge& e) {	// 거리순으로 정렬하기 위해
		return this->distance < e.distance;
	}
};

int V, E;
int parent[10001];
vector<Edge> v;

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

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(Edge(a, b, c));
	}

	sort(v.begin(), v.end());		// 가중치 순으로 정렬


	// 싸이클 판단을 위한 union-find 실행
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	int sum = 0, edge = 0, vsize = v.size();
	for (int i = 0; i < vsize; i++) {
		if (find(v[i].a) == find(v[i].b)) continue;		// 부모가 같으면 = 싸이클 존재. 다음으로.

		sum += v[i].distance;
		merge(v[i].a, v[i].b);
		edge++;

		if (edge == V - 1) break;	// 간선을 정점-1 개 만큼만 찾으면 됨
	}

	cout << sum;
}