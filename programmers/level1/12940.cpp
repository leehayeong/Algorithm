#include <string>
#include <vector>

using namespace std;

/*
최대공약수와 최소공배수
*/

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a, b, c;
    
    // 유클리드 호제법
    a = n;
    b = m;
    while(1){
        c = a % b;
        if(c == 0) break;
        a = b;
        b = c;
    }
    
    answer.push_back(b);        // 최대공약수
    answer.push_back(n*m/b);    // 최소공배수
    
    return answer;
}