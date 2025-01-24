#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string sound;
	cin >> sound;

	const string duck = "quack";
	unordered_multiset<char> ducks;

	for (char curChar : sound) {
		char prevChar = (curChar == duck.front()) ? duck.back() : duck[duck.find(curChar) - 1];
		
		auto it = ducks.find(prevChar);

		if (curChar == duck.front()) { //q일 때.
			if (it != ducks.end()) 
				ducks.erase(it); //이전 문자가 존재하면 제거.
			ducks.insert('q'); // 새 'q' 추가.
		}
		else {
			if (it == ducks.end()) { //직전 문자가 없을 시 잘못된 quack.
				cout << -1;
				return 0; //프로그램 종료.
			}
			
			ducks.erase(it);
			ducks.insert(curChar);
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