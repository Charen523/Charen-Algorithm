#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	

	int n;
	cin >> n;
	
	vector<int> input_arr(n);
	for (int i = 0; i < n; i++) {
		cin >> input_arr[i];
	}

	int result = input_arr[0], temp = input_arr[0];
	for (int i = 1; i < n; i++) {
        temp = max(input_arr[i], temp + input_arr[i]);
        result = max(result, temp);
    }

	cout << result;
	return 0;
}