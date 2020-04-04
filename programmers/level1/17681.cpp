#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
비밀지도
둘 중 하나라도 벽이면 벽(1), 둘 다 공백이면 공백(0)
원래 비밀지도를 문자열 배열로 출력
*/

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++){
        int n1 = arr1[i];
        int n2 = arr2[i];
        string map(n, ' ');
        
        for(int j = n - 1; j >= 0; j--){
            if(n1 % 2 == 0 && n2 % 2 == 0) map[j] = ' ';    // 둘다 2로 나누어 떨어지면, 모두 공백
            else map[j] = '#';
            n1 /= 2;
            n2 /= 2;
        }
        
        answer.push_back(map);
    }
    
    return answer;
}