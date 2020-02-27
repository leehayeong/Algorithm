#include <iostream> 
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/*
행성 터널
3차원 행성의 터널을 연결할 때 드는 비용 =  min(|xA-xB|, |yA-yB|, |zA-zB|)
모든 행성을 터널로 연결하는데 필요한 최소 비용?

모든 행성의 거리를 계산하는 것이 아닌,
x, y, z로 각각 나누어서 정렬한 뒤, 인접한 행성만 vlist에 넣어주어야 한다.
*/

class Edge {
public:
	int a, b;
	long long distance;
	Edge(int a, int b, long long distance) {
		this->a = a;
		this->b = b;
		this->distance = distance;
	}
	bool operator <(Edge& e) {
		return this->distance < e.distance;
	}
};

typedef struct {
	int num, x, y, z;
}Point;

int N, parent[100000];
vector<Point> list;
vector<Edge> v;

bool cmpx(Point a, Point b) {
	return a.x < b.x;
}

bool cmpy(Point a, Point b) {
	return a.y < b.y;
}

bool cmpz(Point a, Point b) {
	return a.z < b.z;
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

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		list.push_back({ i, x, y, z });
	}

	// x정렬, 인접행성 push
	sort(list.begin(), list.end(), cmpx);
	for (int i = 0; i < N - 1; i++) {
		v.push_back(Edge(list[i].num, list[i + 1].num, abs(list[i].x - list[i + 1].x)));
	}

	// y정렬, 인접행성 push
	sort(list.begin(), list.end(), cmpy);
	for (int i = 0; i < N - 1; i++) {
		v.push_back(Edge(list[i].num, list[i + 1].num, abs(list[i].y - list[i + 1].y)));
	}

	// z정렬, 인접행성 push
	sort(list.begin(), list.end(), cmpz);
	for (int i = 0; i < N - 1; i++) {
		v.push_back(Edge(list[i].num, list[i + 1].num, abs(list[i].z - list[i + 1].z)));
	}

	// 크루스칼
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
	sort(v.begin(), v.end());
	long long sum = 0;
	int edge = 0, vsize = v.size();
	for (int i = 0; i < vsize; i++) {
		if (find(v[i].a) == find(v[i].b)) continue;
		sum += v[i].distance;
		merge(v[i].a, v[i].b);
		edge++;
		if (edge == N - 1) break;
	}

	cout << sum;
}