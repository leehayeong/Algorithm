#include <string>
#include <vector>

using namespace std;

/*
약수의 합
n의 약수를 모두 더한 합을 리턴
*/

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++){
        if(n % i == 0) answer += i;
    }
    
    return answer;
}