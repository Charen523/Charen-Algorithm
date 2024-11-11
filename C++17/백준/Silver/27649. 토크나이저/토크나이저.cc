#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 명령문 입력 받기
    string input, token = "";
    getline(cin, input);
    
    vector<string> tokens;
    for (int index = 0; index < input.length(); index++) {
        if (input[index] == '<'
            || input[index] == '>'
            || input[index] == '('
            || input[index] == ')'
            || input[index] == ' ') {
            if (token.size() > 0) {
                tokens.push_back(token);
                token = "";
            }

            if (input[index] != ' ') {
                token += input[index];
                tokens.push_back(token);
                token = "";
            }
        }
        else if (input.substr(index, 2) == "&&"
            || input.substr(index, 2) == "||") {

            if (token.size() > 0) {
                tokens.push_back(token);
                token = "";
            }

            tokens.push_back(input.substr(index, 2));
            index++;
        }
        else {
            token += input[index];
        }
    }

    if (token.size() > 0) {
        tokens.push_back(token);
    }

    for (int i = 0; i < tokens.size(); i++) {
        cout << tokens[i] << " ";
    }
}
