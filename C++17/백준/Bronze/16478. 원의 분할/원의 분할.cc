#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int ab, bc, cd;
	cin >> ab >> bc >> cd;  

	double da = (double)(ab * cd) / bc;

	cout << setprecision(10) << da;
}