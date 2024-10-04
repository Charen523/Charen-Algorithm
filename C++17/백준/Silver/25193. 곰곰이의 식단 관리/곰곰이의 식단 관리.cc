#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int day;
    string diet;
    cin >> day >> diet;

    int cCount = count(diet.begin(), diet.end(), 'C');
    int block = day - cCount + 1;

    int result = (int)ceil((double)cCount / block);
    cout << result << endl;
}