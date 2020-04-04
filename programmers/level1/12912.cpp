#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
두 정수 사이의 합
a와 b사이에 속한 모든 정수의 합
*/

long long solution(int a, int b) {
    long long answer = 0;
    
    if(a > b) swap(a, b);
    for(int i = a; i <= b; i++){
        answer += i;
    }
    
    return answer;
}