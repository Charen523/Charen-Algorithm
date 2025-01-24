#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string sound;
	cin >> sound;

	const string duck = "quack";
	unordered_multiset<char> ducks;

	for (int i = 0; i < sound.size(); i++) {
		//prevChar, curChar 찾기.
		char prevChar, curChar = sound[i];
		if (curChar == duck.front()) prevChar = duck.back();
		else prevChar = duck[duck.find(curChar) - 1];

		if (curChar == duck.front()) { //q일 때.
			auto it = ducks.find(prevChar); //직전 문자 ('k')
			if (it != ducks.end()) ducks.erase(it); //존재하면 지우기.
			ducks.insert('q'); //없으면 추가, 있으면 대체.
		}
		else {
			auto it = ducks.find(prevChar); //직전 문자
			if (it == ducks.end()) { //직전 문자가 없을 시 잘못된 quack.
				cout << -1;
				return 0; //프로그램 종료.
			}
			else { //문자 대체.
				ducks.erase(it); 
				ducks.insert(curChar);
			}
		}
	}

	for (char c : ducks) {
		if (c != duck.back()) {
			cout << -1;
			return 0; //프로그램 종료.
		}
	}

	cout << ducks.size();
	return 0; //프로그램 종료.
}