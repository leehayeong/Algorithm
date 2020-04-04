#include <string>
#include <vector>

using namespace std;

/*
1부터 n사이에 있는 소수의 개수를 반환
*/

bool isNotPrime[1000001];   // 소수가 아니면 true, 소수이면 false

void func(int n){
    for(int i = 2; i <= n; i++){
        // 에라토스테네의 체 = 배수는 모두 소수가 아니므로 모두 거름
        for(int j = 2; i * j <= n; j++){
            isNotPrime[i*j] = true;
        }
    }
}

int solution(int n) {
    int answer = 0;
    
    func(n);                                    // 에라토스테네의 체
    for(int i = 2; i <= n; i++){
        if(isNotPrime[i] == false) answer++;    // 소수의 개수 세기
    }    
    
    return answer;
}