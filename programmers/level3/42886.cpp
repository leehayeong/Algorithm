#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
저울
추들로 측정할 수 없는 무게의 최솟값?
*/

int solution(vector<int> weight) {
    int answer = 1;

    sort(weight.begin(), weight.end());                 // 1. 정렬하고
    
    for(int i = 0; i < weight.size(); i++){             // 2. 더해가다가, 추의 값이 더 커질 때 종료
        if(answer >= weight[i]) answer += weight[i];
        else break;
    }
    
    return answer;
}