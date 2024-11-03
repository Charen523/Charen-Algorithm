#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int romCount;
	cin >> romCount; //I, V, X, L
	
	vector<int> findSameNum;
	for (int i = 0; i <= romCount; i++) {
		for (int v = 0; v <= romCount - i; v++) {
			for (int x = 0; x <= (romCount - (i + v)); x++) {
				int l = romCount - (i + v + x);
				findSameNum.push_back(i * 1 + v * 5 + x * 10 + l * 50);
			}
		}
	}

	sort(findSameNum.begin(), findSameNum.end());
	findSameNum.erase(unique(findSameNum.begin(), findSameNum.end()), findSameNum.end());

	cout << findSameNum.size();
}