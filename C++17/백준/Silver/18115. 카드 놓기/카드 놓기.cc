#include <iostream>
#include <vector>

using namespace std;

int main() {
	int skillCount;
	cin >> skillCount;

	vector<int> skills;
	vector<int> cardSequence;
	cardSequence.resize(skillCount);

	for (int i = 0; i < skillCount; i++) {
		int value;
		cin >> value;
		skills.push_back(value);
	}

	int firstIndex = 0;
	int secIndex = 1;
	int lastIndex = skillCount - 1;
	int curCardNum = skillCount;
	
	for (int& curSkill : skills) {
		switch (curSkill) {
		case 1:
			cardSequence[firstIndex] = curCardNum;
			firstIndex = secIndex;
			if (curCardNum > 1) secIndex++;
			break;
		case 2:
			cardSequence[secIndex] = curCardNum;
			if (curCardNum > 1) secIndex++;
			break;
		case 3:
			cardSequence[lastIndex] = curCardNum;
			if (curCardNum > 1) lastIndex--;
			break;
		}
		curCardNum--;
	}

	for (const int& card : cardSequence)
		cout << card << " ";
	cout << '\n';
}