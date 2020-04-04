#include <string>
#include <vector>

using namespace std;

/*
하샤드 수
x자릿수의 합으로 x가 나누어지면 하샤드수 (x % x자릿수 합 == 0)
*/

bool solution(int x) {
    bool answer = true;
    
    int i = 10;
    int n = x;
    int sum = 0;
    while(n >= 1){
        sum += n % i;
        n = n / i;
    }
    
    if(x % sum != 0) answer = false;
    
    return answer;
}