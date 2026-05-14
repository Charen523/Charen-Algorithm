#include <string>
#include <vector>

using namespace std;

int find_char(char c) {
    switch (c) {
        case 'A':
            return 0;
        case 'E':
            return 1;
        case 'I':
            return 2;
        case 'O':
            return 3;
        case 'U':
            return 4;  
    }
    return 0;
}

int solution(string word) {
    int answer = 0;
    
    //단어의 길이가 1, 2, 3, 4, 5일 때.
    //5번째 자리 : null, a, e, i, o, u = 6
    //4번째 자리 : null(1) + 5 * 6 = 31
    //3번째 자리 : null(1) + 5 * (1 + 30) = 156
    //2번째 자리 : null(1) + 5 * (1 + 5 * 31) = 781
    
    for (int i = 0; i < word.size(); i++) {
        int counter = find_char(word[i]);
        switch (i) {
            case 0:
                answer++;
                answer += counter * 781;
                break;
            case 1:
                answer++;
                answer += counter * 156;
                break;
            case 2:
                answer++;
                answer += counter * 31; 
                break;
            case 3:
                answer++;
                answer += counter * 6;
                break;
            case 4:
                answer++;
                answer += counter;
                break;
        }
    }
    
    return answer;
}