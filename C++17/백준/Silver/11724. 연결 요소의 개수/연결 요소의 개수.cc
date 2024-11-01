#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void printGraph(vector<unordered_set<int>> graphs) {
	cout << endl;
	for (int i = 0; i < graphs.size(); i++) {
		for (const int& num : graphs[i]) {
			cout << num << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<unordered_set<int>> graphs; //입력받을 여러 그래프들.
	unordered_set<int> dots; //점들의 존재 여부.

	for (int i = 0; i < M; i++) {
		int dot1, dot2;
		cin >> dot1 >> dot2;

		/*두 점 모두 처음 등장한 경우*/
		if (dots.count(dot1) == 0 && dots.count(dot2) == 0) {
			/*vertices 정보 기록*/
			dots.insert(dot1);
			dots.insert(dot2);

			/*새 그래프 생성*/
			unordered_set<int> newSet;
			newSet.insert(dot1);
			newSet.insert(dot2);
			graphs.push_back(newSet);

			/*다음 입력 받기*/
			//printGraph(graphs);
			continue;
		}

		bool isFound = false; //첫 발견 여부
		int firstFoundIdx = 0;
		
		if (dots.count(dot1) != 0) {
			for (int j = 0; j < graphs.size(); j++) {
				if (graphs[j].count(dot1) != 0) {
					if (isFound) { //또 다른 그래프가 발견된 경우
						for (const int& num : graphs[j]) {
							graphs[firstFoundIdx].insert(num);
						}
						swap(graphs[j], graphs[graphs.size() - 1]);
						graphs.pop_back();
					}
					else {
						dots.insert(dot2);

						graphs[j].insert(dot2);
						isFound = true;
						firstFoundIdx = j;
					}
				}
			}
		}
		
		if (dots.count(dot2) != 0) {
			for (int j = 0; j < graphs.size(); j++) {
				if (graphs[j].count(dot2) != 0) {
					if (isFound && j != firstFoundIdx) { //또 다른 그래프가 발견된 경우
						for (const int& num : graphs[j]) {
							graphs[firstFoundIdx].insert(num);
						}
						swap(graphs[j], graphs[graphs.size() - 1]);
						graphs.pop_back();
					}
					else {
						dots.insert(dot1);

						graphs[j].insert(dot1);
						isFound = true;
						firstFoundIdx = j;
					}
				}
			}
		}
		//printGraph(graphs);
	}

	int result = graphs.size();
	if (dots.size() < N) {
		result += N - dots.size();
	}

	cout << result;
}