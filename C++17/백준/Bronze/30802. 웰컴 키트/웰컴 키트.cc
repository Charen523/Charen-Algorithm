#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_SIZE = 6;

int main() {
	/*참가자 수*/
	int participant;
	cin >> participant;

	/*각 사이즈 당 필요 개수*/
	vector<int> shirtSizes;
	for (int i = 0; i < MAX_SIZE; i++) {
		int sizeCount;
		cin >> sizeCount;
		shirtSizes.push_back(sizeCount);
	}

	/*셔츠, 펜 묶음 개수*/
	int shirtColl, penColl;
	cin >> shirtColl >> penColl;

	/*사야 하는 묶음 개수*/
	int shirtCollCount = 0;
	for (const auto& size : shirtSizes) {
		shirtCollCount += size / shirtColl;
		if (size % shirtColl != 0) shirtCollCount++;
	}

	/*정답 출력*/
	cout << shirtCollCount << endl;
	cout << participant / penColl << " " << participant % penColl << endl;
}