#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    
    //brown 가로 = yellow 가로
    //brown 세로 = yellow 세로 + 2 로 가정하자.
    for (int i = 1; i * i <= yellow; i++) {
        if (yellow % i == 0) {
            int col = i;
            int row = yellow / i;
            int predict = (row + col + 2) * 2;
            if (predict == brown) {
                answer[0] = row + 2;
                answer[1] = col + 2;
                break;
            }
        }
    }
    
    return answer;
}