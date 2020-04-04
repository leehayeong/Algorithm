#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

/*
정수 제곱근 판별
x^2 = n 이라면 (x+1)^2, 아니면 -1 리턴
*/

long long solution(long long n) {
    long long answer = 0;
    
    if(sqrt(n) - (int)sqrt(n) == 0) answer = pow(sqrt(n) + 1, 2);   // 소수점 있는지 판별
    else answer = -1;
    
    return answer;
}