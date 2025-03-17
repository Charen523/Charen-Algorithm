#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int n; 
	cin >> n;

	int input;
	queue<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> input;
		arr.push(input);
	}

	int idx = 0;
	stack<int> s;
	vector<char> v;
	for (int i = 0; i < n; i++) {
		int temp = arr.front();
		arr.pop();

		//push
		for (idx; idx < temp; idx++) {
			s.push(idx);
			v.push_back('+');
		}

		//pop
		if (s.top() == temp - 1) {
			s.pop();
			v.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
     
	return 0;
}