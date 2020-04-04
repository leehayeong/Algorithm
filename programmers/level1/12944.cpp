#include <string>
#include <vector>

using namespace std;

/*
평균 구하기
*/

double solution(vector<int> arr) {
    double answer = 0;
    int n = arr.size();
    
    for(int i = 0; i < n; i++) answer += arr[i];
    answer = answer / n;
    
    return answer;
}