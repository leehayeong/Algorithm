#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
제일 작은 수 제거하기
*/

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int minVal = *min_element(arr.begin(), arr.end());  // 최솟값 찾고
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == minVal) continue;                  // 최솟값은 포함 안되도록 
        answer.push_back(arr[i]);
    }
    if(answer.size() == 0) answer.push_back(-1);
    
    return answer;
}