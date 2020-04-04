#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
같은 숫자는 싫어
연속으로 나타나는 숫자 제거
*/

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    answer.push_back(arr[0]);
    for(int i = 0; i < arr.size() - 1; i++){
        if(arr[i] != arr[i+1]) answer.push_back(arr[i+1]);  // 달라질 때 다음 수 push
    }
    
    return answer;
}