#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    //1. 대->소, 2. 제한된 문자 제거
    for (int i = 0; i < new_id.size(); i++) {
        char c = new_id[i];
        if (c >= 'A' && c <= 'Z') {
            c += ('a' - 'A');  
        }
        else if (!((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))) {
            if (c != '-' && c != '_' && c != '.') continue;
        }
        answer += c;
    }
    
    //3. 연속된 마침표 제거
    while (answer.find("..") != string::npos) {
        answer.replace(answer.find(".."), 2, ".");
    }
    
    //4. 맨앞/뒤 마침표 제거
    if (!answer.empty() && answer.front() == '.') answer.erase(answer.begin());
    if (!answer.empty() && answer.back() == '.') answer.pop_back();    
    if (answer.empty()) answer = "a";
    
    //6. 길이제한 적용
    if (answer.size() > 15) {
        answer = answer.substr(0, 15);
        if (answer.back() == '.') answer.pop_back();  
    }
    
    //7.
    while (answer.size() < 3) {
        answer += answer.back();
    }
    
    return answer;
}