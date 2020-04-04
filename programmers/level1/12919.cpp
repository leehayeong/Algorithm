#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
서울에서 김서방 찾기
Kim이 있는 index 반환
*/

string solution(vector<string> seoul) {
    string answer = "";
    
    for(int i = 0; i < seoul.size(); i++){
        if(seoul[i] == "Kim"){
            answer = "김서방은 " + to_string(i) + "에 있다";
            break;
        }
    }
    
    return answer;
}