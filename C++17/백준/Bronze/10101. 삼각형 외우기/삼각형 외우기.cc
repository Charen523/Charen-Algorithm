#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int sum = a + b + c;
    if (sum != 180) {
        cout << "Error" << '\n';
        return 0;
    }
    if (a == b && a == 60) {
        cout << "Equilateral" << '\n';
        return 0;
    }
    if (a == b || b == c || a == c) {
        cout << "Isosceles" << '\n';
        return 0;
    }
    cout << "Scalene" << '\n';
    return 0;
}