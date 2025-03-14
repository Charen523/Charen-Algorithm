#include <iostream>
#include <vector>
using namespace std;

int s1 = 1, s2 = 0;

int fib(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		s1++;
		return fib(n - 1) + fib(n - 2);
	}
}

int fibonacci(int n) {
	vector<int> f(n + 1);
	f[1] = 1; f[2] = 1;

	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		s2++;
	}

	return f[n];
}

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int n;
	cin >> n;
	fib(n); 
	fibonacci(n);
	cout << s1 << ' ' << s2;
    
	return 0;
}