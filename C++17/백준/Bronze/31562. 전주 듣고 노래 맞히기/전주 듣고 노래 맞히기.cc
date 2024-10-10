#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main() {
	int songCount, testCount;
	cin >> songCount >> testCount;
	cin.ignore();

	map<string, string> songs;
	for (int i = 0; i < songCount; i++) {
		string input;
		string songName, noteNames;
		string note1, note2, note3;

		getline(cin, input);
		istringstream iss(input);
		iss >> input >> songName >> note1 >> note2 >> note3;
		
		noteNames = note1 + note2 + note3;

		if (songs.find(noteNames) == songs.end()) {
			songs.insert(make_pair(noteNames, songName));
		}
		else {
			songs[noteNames] = "?";
		}
	}

	for (int i = 0; i < testCount; i++) {
		string curCase;
		for (int j = 0; j < 3; j++) {
			char value; 
			cin >> value; 
			curCase += value;
		}

		if (songs.find(curCase) == songs.end()) {
			cout << "!\n";
		}
		else {
			cout << songs[curCase] << '\n';
		}
	}
}