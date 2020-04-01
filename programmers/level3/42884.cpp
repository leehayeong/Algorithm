#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
단속카메라
모든 차량을 단속하게 하는 최소 카메라 대수는?
*/

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    
    // 카메라가 단속할 수 있는 끝 길이를 갱신하면서
    int end = routes[0][1];
    for(int i = 1; i < routes.size() - 1; i++){
        if(routes[i][1] < end){
            end = routes[i][1];
        }
        if(routes[i+1][0] > end) {      // 다음 차량의 시작점이 단속 범위를 벗어나면 카메라 개수 추가
            answer++;
            end = routes[i+1][1];
        }
    }
    
    return answer;
}