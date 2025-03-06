#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);
    
	//0~9, _, -의 문자만으로 이루어짐.
	string input; 
	cin >> input;

	//결과
	int result = 0;
	char symbol = 0;
	bool is_minus = false;

	//수식 해석
	for (int i = 0; i < input.size(); ) {
		string str_number = "";

		if (!(input[i] >= '0' && input[i] <= '9')) {
			symbol = input[i];
			i++;
		}

		while (i < input.size() && input[i] >= '0' && input[i] <= '9') {
			str_number += input[i];
			i++;
		}

		int int_number = stoi(str_number);

		if (symbol == 0) {
			result = int_number;
		}
		else {
			if (symbol == '+') {
				if (is_minus) {
					result -= int_number;
				}
				else {
					result += int_number;
				}
				
			}
			else if (symbol == '-') {
				result -= int_number;
				is_minus = true;
			}
		}
	}

	cout << result;
	return 0;
}