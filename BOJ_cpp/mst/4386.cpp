#include <iostream> 
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/*
별자리 만들기
별자리를 만드는 최소 비용?
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
	bool operator <(Edge& star) {
		return this->distance < star.distance;
	}
};

int N, parent[100];
vector<Edge> list;

double calDistance(pair<int, int> s1, pair<int, int> s2) {
	int x1 = s1.first, y1 = s1.second;
	int x2 = s2.first, y2 = s2.second;
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
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

	vector<pair<double, double>> points;
	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}

	// 별들의 거리 구하기
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			list.push_back(Edge(i, j, calDistance(points[i], points[j])));
		}
	}


	// 크루스칼 알고리즘
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	sort(list.begin(), list.end());

	double sum = 0;
	int edge = 0, length = list.size();
	for (int i = 0; i < length; i++) {
		if (find(list[i].a) == find(list[i].b)) continue;

		sum += list[i].distance;
		merge(find(list[i].a), find(list[i].b));
		edge++;

		if (edge == N - 1) break;
	}

	cout.setf(ios::fixed);
	cout.precision(2);
	cout << sum;
}