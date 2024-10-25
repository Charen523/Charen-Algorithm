#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum class Nations {
	botswana = 0,
	ethiopia,
	kenya,
	namibia,
	south_africa,
	tanzania,
	zambia,
	zimbabwe
};

unordered_map<string, Nations> nationsMap = {
	{"botswana", Nations::botswana},
	{"ethiopia", Nations::ethiopia},
	{"kenya", Nations::kenya},
	{"namibia", Nations::namibia},
	{"south-africa", Nations::south_africa},
	{"tanzania", Nations::tanzania},
	{"zambia", Nations::zambia},
	{"zimbabwe", Nations::zimbabwe}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase;
	cin >> testCase;

	vector<Nations> visitOrder(testCase);
	for (int i = 0; i < testCase; i++) {
		string word;
		cin >> word;
		visitOrder[i] = nationsMap[word];
	}

	bool isSouthAfrica = false;
	bool isZ = false;
	int result = 0;

	for (int i = 0; i < testCase; i++) {
		switch (visitOrder[i]) {
		case Nations::botswana:
			break;
		case Nations::south_africa:
			isSouthAfrica = true;
			break;
		case Nations::namibia:
			result += isSouthAfrica ? 40 : 140;
			break;
		case Nations::ethiopia:
		case Nations::kenya:
		case Nations::tanzania:
			result += 50;
			break;
		case Nations::zambia:
			if (!isZ) result += 50;
			if (i < testCase - 1 && visitOrder[i + 1] == Nations::zimbabwe) isZ = true;
			break;
		case Nations::zimbabwe:
			if (!isZ) {
				if (i < testCase - 1 && visitOrder[i + 1] == Nations::zambia) {
					result += 50;
					isZ = true;
				}
				else result += 30;
			}
			break;
		}
	}

	cout << result;
}