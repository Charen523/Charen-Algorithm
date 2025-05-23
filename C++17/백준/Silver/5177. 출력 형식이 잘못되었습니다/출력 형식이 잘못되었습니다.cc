#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

string Formalize(string input) {
    stringstream ss(input);
    vector<string> words;
    string word;
    while (getline(ss, word, ' ')) { // 공백 구분
        // 대소문자 구분하지 않음
        transform(word.begin(), word.end(), word.begin(),
            [](unsigned char c) { return tolower(c); });

        for (size_t i = 0; i < word.length(); i++) {
            if (word[i] > 122 || word[i] < 97) {
                // 숫자 생략
                if (word[i] >= 48 && word[i] < 58) continue;

                char special = word[i];

                // 앞부분 캐싱
                if (i != 0) {
                    string front = word.substr(0, i);
                    words.push_back(front);
                }

                // 뒷부분 정리
                if (i + 1 != word.length()) {
                    word = word.substr(i + 1, word.length() - (i + 1));
                    i = 0;
                }
                else
                    word = "";

                switch (special) {
                case '[':
                case '{':
                    special = '('; // 여는 괄호 통일
                    break;
                case ']':
                case '}':
                    special = ')'; // 닫는 괄호 통일
                    break;
                case ';':
                    special = ','; // 쉼표 == 세미콜론
                    break;
                }

                words.push_back(string("") + special);
            }
        }

        if (word != "")
            words.push_back(word);
    }
    string output = "";
    for (const string& w : words) {
        output += w;
        output += " ";
    }

    return output;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore(); // 입력 버퍼 초기화
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << "\n";
        }

        string inputA;
        getline(cin, inputA, '\n');
        inputA = Formalize(inputA);

        string inputB;
        getline(cin, inputB, '\n');
        inputB = Formalize(inputB);

        if (inputA == inputB) {
            cout << "Data Set " << i + 1 << ": equal\n";
        }
        else {
            cout << "Data Set " << i + 1 << ": not equal\n";
        }
    }
}