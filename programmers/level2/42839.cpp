#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string nums;
bool visited[7];
map<int, int> prime;   // 중복 계산 막기 위해 map 사용
int answer = 0;

// 소수면 true, 아니면 false 반환
bool isPrime(int n){
    if(n == 0) return false;
    if(n == 1) return false;
    
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    
    return true;
}

void dfs(string cur, int cnt, int length){
    if(cnt == length) return;
    
    for(int i = 0; i < length; i++){
        if(visited[i] == false){
            // 수로 변환하고
            int n = atoi((cur + nums[i]).c_str());
            
            // 중복 계산 막기 위해, 처음 나오는 수만 소수인지 확인
            if(prime[n] == 0) {
                if(isPrime(n)) answer++;  // 소수이면 답 ++
                prime[n] = 1;             // 계산했음을 표시
            }   
                        
            // 다음 조합 구하기
            visited[i] = true;
            dfs(cur + nums[i], cnt + 1, length);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    nums = numbers; // 전역변수로 사용하기 위한 것
    
    dfs("", 0, numbers.length());
    
    return answer;
}