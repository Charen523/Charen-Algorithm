#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int A, B, C;
	while (scanf("%d %d %d", &A, &B, &C) != EOF) {
		int count = 0;

		while (true) {
			if (B - A == 1 && C - B == 1) break;

			int temp;
			if (B - A >= C - B) {
				temp = C;
				C = B;
				B = A + 1;
			}
			else {
				temp = A;
				A = B;
				B = C - 1;
			}
			count++;
		}
		cout << count << '\n';
	}
}