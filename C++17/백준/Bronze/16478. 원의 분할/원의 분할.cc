#include <iostream>

using namespace std;

int main() {
	int ab, bc, cd;
	cin >> ab >> bc >> cd;  

	double da = (double)(ab * cd) / bc;
	cout << da << '\n';
}