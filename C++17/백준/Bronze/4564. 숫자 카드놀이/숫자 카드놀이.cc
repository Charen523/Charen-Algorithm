#include <iostream>

using namespace std;

/*각 자리수의 곱*/
int digitMul(int num) {
	int result = 1;
	while (num > 0) {
		result *= num % 10;
		num /= 10;
	}
	return result;
}

int main() {
	int num;
	cin >> num; //1 <= num <= 100,000

	while (num != 0) {
		cout << num << ' ';
		while (num >= 10) {
			num = digitMul(num);
			cout << num << ' ';
		}
		cout << '\n';
		cin >> num; //1 <= num <= 100,000
	}
}