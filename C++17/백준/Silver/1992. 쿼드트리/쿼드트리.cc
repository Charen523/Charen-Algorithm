#include <iostream>
#include <vector>
#include <string>

using namespace std;

int arrSize; //영상의 크기, 2의 제곱수, 1 <= N <= 64
vector<int> planeArr;
string result = "";
string temp = "";

string quadTree(int x, int y, int side, bool& isQuad) {
	if (side == 1) { 
		return to_string(planeArr[x + arrSize * y]);
	}

	bool merge1 = true, merge2 = true, merge3 = true, merge4 = true;

	int half = side / 2;
	string p1 = quadTree(x, y, half, merge1);
	string p2 = quadTree(x + half, y, half, merge2);
	string p3 = quadTree(x, y + half, half, merge3);
	string p4 = quadTree(x + half, y + half, half, merge4);

	if (merge1 && merge2 && merge3 && merge4
		&& (p1 == p2) && (p2 == p3) && (p3 == p4)) {
		return p1;
	}
	else {
		isQuad = false;
		return "(" + p1 + p2 + p3 + p4 + ")";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> arrSize; 

	//영상의 각 점 입력.
	planeArr.resize(arrSize * arrSize);
	for (int i = 0; i < arrSize; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < arrSize; j++) {
			planeArr[i * arrSize + j] = input[j] - 48;
		}
	}

	bool isQuad = true;
	cout << quadTree(0, 0, arrSize, isQuad);
}