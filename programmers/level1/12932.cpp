#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
자연수 뒤집어 배열로 만들기
*/

vector<int> solution(long long n) {
    vector<int> answer;
    
    int i = 10;
    while(n >= 1){
        answer.push_back(n % i);
        n = n / i;
    }
    
    return answer;
}