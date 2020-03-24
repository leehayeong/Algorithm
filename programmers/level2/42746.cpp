#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
가장 큰 수
정수를 이어 붙였을 때 만들 수 있는 가장 큰 수는?
*/

// 3 34 일 때, 343과 334중에 343이 더 큰 수이다.
// 두 수를 연결했을 때, 더 큰 수대로 정렬되도록 한다.
bool compare(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    // int -> string 변환
    vector<string> tmp;
    for(int i = 0; i < numbers.size(); i++){
        tmp.push_back(to_string(numbers[i]));
    }
    
    // 이어붙였을 때, 큰 수가 앞으로 오도록 정렬
    sort(tmp.begin(), tmp.end(), compare);
    
    // 이어붙이기
    for(int i = 0; i < tmp.size(); i++){
        answer += tmp[i];
    }
    
    // 첫 번째 값이 0이라면, 00, 000 과 같이 0으로만 이루어진 것. 000 = 0 이므로 변환
    if(answer[0] == '0') answer = "0";
    
    return answer;
}