#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int stringSize;
	cin >> stringSize;

	string imsString;
	cin >> imsString;

	vector<bool> smallRainbow(7, false);
	vector<bool> bigRainbow(7, false);

	for (int i = 0; i < stringSize; i++) {
		switch (imsString[i]) {
		case 'r':
			smallRainbow[0] = true;
			break;
		case 'o':
			smallRainbow[1] = true;
			break;
		case 'y':
			smallRainbow[2] = true;
			break;
		case 'g':
			smallRainbow[3] = true;
			break;
		case 'b':
			smallRainbow[4] = true;
			break;
		case 'i':
			smallRainbow[5] = true;
			break;
		case 'v':
			smallRainbow[6] = true;
			break;
		case 'R':
			bigRainbow[0] = true;
			break;
		case 'O':
			bigRainbow[1] = true;
			break;
		case 'Y':
			bigRainbow[2] = true;
			break;
		case 'G':
			bigRainbow[3] = true;
			break;
		case 'B':
			bigRainbow[4] = true;
			break;
		case 'I':
			bigRainbow[5] = true;
			break;
		case 'V':
			bigRainbow[6] = true;
			break;
		}
	}

	bool small = true, big = true;
	for (int i = 0; i < 7; i++) {
		if (!smallRainbow[i]) small = false;
		if (!bigRainbow[i]) big = false;
	}

	if (small) {
		if (big) {
			cout << "YeS";
		}
		else {
			cout << "yes";
		}
	}
	else if (big) {
		cout << "YES";
	}
	else {
		cout << "NO!";
	}
}