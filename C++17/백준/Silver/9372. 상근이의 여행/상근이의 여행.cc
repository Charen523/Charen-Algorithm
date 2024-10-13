#include <iostream>
#include <vector>

using namespace std;

int main() {
	int testCase; 
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int nationCount, planeCount;
		cin >> nationCount >> planeCount;

		for (int j = 0; j < planeCount; j++) {
			int nation1, nation2;
			cin >> nation1 >> nation2;
		}
		cout << nationCount - 1 << '\n';
	}
}