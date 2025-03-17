#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int k;
	cin >> k;

	vector<int> arr;
	for (int i = 0; i < k; i++){
		int input;
		cin >> input;
		if (input == 0) {
			arr.pop_back();
		}
		else {
			arr.push_back(input);
		}
	}

	cout << accumulate(arr.begin(), arr.end(), 0);
    
	return 0;
}