#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
섬 연결하기
크루스칼 알고리즘
*/

int parent[100];
   
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0; 
    
    sort(costs.begin(), costs.end(), compare);  // 1. 정렬
    
    for(int i = 0; i < n; i++){                 // 2. 부모 초기화
        parent[i] = i;
    }

    for(int i = 0; i < costs.size(); i++){      // 3. 최소비용 선택하며 union-find
        int a = find(costs[i][0]);
        int b = find(costs[i][1]);
        if(a != b){
            answer += costs[i][2];
            merge( a, b);
        }
    }
    
    return answer;
}