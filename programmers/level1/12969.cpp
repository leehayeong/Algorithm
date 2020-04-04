#include <iostream>

using namespace std;

/*
직사각형 별찍기
a, b 입력받아 b*a인 직사각형 찍기
*/

int main(void) {
    int a, b;
    
    cin >> a >> b;
    for(int i = 0; i < b; i++){
        for(int j = 0; j < a; j++){
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}