#include <iostream>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; //듣도 못한 사람
	int M; //보도 못한 사람
	cin >> N >> M;

	unordered_set<string> nList;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		nList.insert(name);
	}

	set<string>nmList;
	for (int i = 0; i < M; i++) {
		string name;
		cin >> name;
		
		if (nList.find(name) != nList.end()) {
			nmList.insert(name);
		}
	}

	cout << nmList.size() << '\n';
	for (string name : nmList) {
		cout << name << '\n';
	}
}