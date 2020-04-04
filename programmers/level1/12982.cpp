#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
예산
최대 몇 개의 부서에 물품을 지원 가능?
*/

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());               // 금액 적은 순으로 정렬하고
    
    int sum = 0;
    for(int i = 0; i < d.size(); i++){      // 예산안 넘어가면 stop
        if(sum + d[i] > budget) break;
        sum += d[i];
        answer++;
    }
    
    return answer;
}