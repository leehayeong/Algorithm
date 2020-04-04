#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
나누어 떨어지는 숫자 배열
divisor로 나누어 떨어지는 값들을 오름차순 정렬하여 반환
*/

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] % divisor == 0) answer.push_back(arr[i]);
    }
    
    if(answer.size() == 0) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    
    return answer;
}