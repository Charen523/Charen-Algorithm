#include <iostream>
#include <string>

using namespace std;

int main() {
	int S, K, H;
	int minNum;
	string minSchool = "Soongsil";

	cin >> S;
	minNum = S;
	cin >> K;
	if (K < S) {
		minSchool = "Korea";
		minNum = K;
	}
	cin >> H;
	if (H < minNum)
		minSchool = "Hanyang";
	
	if (S + K + H >= 100) {
		cout << "OK" << endl;
	}
	else {
		cout << minSchool << endl;
	}
}