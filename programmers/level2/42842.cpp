#include <string>
#include <vector>

using namespace std;

/*
카펫
갈색, 빨강 카펫의 수를 보고 가로, 세로의 크기를 구하라.
*/

vector<int> solution(int brown, int red) {
    vector<int> answer;
    
    int h, w;
    int area = brown + red;
    for(h = 3; h <= area; h++){
        if(area % h != 0) continue;     // 나누어떨어지지 않는다면 가로, 세로에 해당 x
        
        w = area / h;
        int calBrown = w * 2 + (h - 2) * 2;
        
        if(calBrown == brown) break;
    }
    
    answer.push_back(w);
    answer.push_back(h);
    
    return answer;
}

/*
풀이법
1. 갈색 + 빨강 = 전체 카펫의 넓이 구함
2. 넓이를 가능하게 하는 전체 조합 구함
3. 갈색 테두리가 모두 둘러싸고 있으므로, h = 3부터. w = area / h
4. brown = w * 2 + (h - 2) * 2   
   => 위, 아래 카펫 수 + 왼, 오른쪽 카펫 수 (위, 아래 한 줄 총 2줄 빼고 * 2)
5. 계산한 brwon이 주어진 brown 개수와 같으면 이 때의 w, h 가 답
*/