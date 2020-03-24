#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
H-index
h번 이상 인용된 논문이 h편 이상이고, 나머지가 h편 이하일 때 h의 최댓값
*/

int solution(vector<int> citations) {
    int answer = 0;
    
    // 인용 횟수 내림차순
    sort(citations.begin(), citations.end(), greater<int>());
    
    int h = 1;  // h-index
    for(int i = 0; i < citations.size(); i++){
        if(citations[i] < h) break; // 인용된 논문의 횟수가 h-index보다 작아질 때 멈춤 
        h++;                        // 다음 논문으로 넘어가면서 h-index도 증가 
    }
    answer = h - 1;                 // 멈추기 직전의 index가 최종 h-index
    
    return answer;
}