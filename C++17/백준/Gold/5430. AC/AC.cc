#include <iostream>
#include <sstream>
#include <deque>
#include <string>
using namespace std;

void make_result(deque<int>& arr, string cmd) {
	bool isReverse = false;

	for (int i = 0; i < cmd.size(); i++) {
		switch (cmd[i]) {
		case 'R':
			isReverse = !isReverse;
			break;
		case 'D':
			if (arr.empty()) {
				cout << "error" << '\n';
				return;
			}
			else {
				if (isReverse) arr.pop_back();
				else arr.pop_front();
			}
			break;
		}
	}

	string result = "[";
	if (isReverse) {
		for (int i = arr.size() - 1; i >= 0; i--) {
			string c = to_string(arr[i]);
			result += c;
			result += ',';
		}
	}
	else {
		for (int i = 0; i < arr.size(); i++) {
			string c = to_string(arr[i]);
			result += c;
			result += ',';
		}
	}
	if (result.size() > 1) {
		result[result.size() - 1] = ']';
	}
	else {
		result += ']';
	}

	cout << result << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T; // 1 < T < 100.
	for (int i = 0; i < T; i++) {
		string p; cin >> p;
		int n; cin >> n;
		deque<int> arr;

		string x; cin >> x;
		stringstream ss(x);
		int num; char c;
		ss >> c;
		while (true) {
			if (ss >> num) {
				arr.push_back(num);
				continue;
			}
			ss.clear();
			if (ss >> c)
				continue;
			else
				break;
		}
		make_result(arr, p);
	}

	return 0;
}