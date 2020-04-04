#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
콜라츠 추측
1. num 짝수면 2로 나눔 / 홀수면 3을 곱하고 1을 더함
2. 1이 될 때까지 반복
*/

int solution(int num) {
    int answer = 0;
    
    while(answer <= 500){
        if(num == 1) break;

        if(num % 2 == 0) num = num / 2;
        else if(num % 2 == 1) num = num * 3 + 1;
        answer++;
    }
    
    if(answer > 500) answer = -1;
    
    return answer;
}