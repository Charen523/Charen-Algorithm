#include <iostream>

using namespace std;

void findFun(int& result, int count) {
	if (count == 1) return;
	
	int nextCount = count / 2;
	if (count % 2 == 0) {
		result += nextCount * nextCount;
		findFun(result, nextCount);
		findFun(result, nextCount);
	}
	else {
		result += nextCount * (nextCount + 1);
		findFun(result, nextCount);
		findFun(result, nextCount + 1);
	}
}

int main() {
	int pizzaCount;
	cin >> pizzaCount;

	int result = 0;
	findFun(result, pizzaCount);
	cout << result;
}