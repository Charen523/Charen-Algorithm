#include <iostream>
#include <vector>

using namespace std;

void printResult(bool isSuccess) {
	if (isSuccess) cout << "권병장님, 중대장님이 찾으십니다";
	else cout << "엄마 나 전역 늦어질 것 같아";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase;
	cin >> testCase;

	vector<pair<int, int>>soldiers(testCase); //position, throwDistance
	for (int i = 0; i < testCase; i++) {
		cin >> soldiers[i].first;
	}
	for (int i = 0; i < testCase - 1; i++) {
		cin >> soldiers[i].second;
	}

	if (testCase == 1) {
		printResult(true);
		return 0;
	}

	int curThrower = 0;
	const int targetPos = soldiers[soldiers.size() - 1].first;

	if (soldiers[curThrower].first + soldiers[curThrower].second >= targetPos) {
		printResult(true);
		return 0;
	}

	while (true) {
		//내가 던질 수 있는 최선
		int curMaxPos = soldiers[curThrower].first + soldiers[curThrower].second;
		
		//다음 사람이 던질 수 있는 최선
		int nextMaxPos = curMaxPos;
		
		//내가 던졌을 때 받을 수 있는 사람들 중 더 오른쪽으로 보낼 수 있는 사람 찾기
		for (int i = curThrower + 1; i < testCase && soldiers[i].first <= curMaxPos; i++) {
			//새로운 사람이 던질 수 있는 최우단 위치
			int reachPos = soldiers[i].first + soldiers[i].second;
			
			if (nextMaxPos < reachPos) { //더 멀리 던질 수 있다면
				nextMaxPos = reachPos; //닿는 최우단 위치 변경
				curThrower = i; //다음 던질 사람으로 지정
			}
		}

		if (nextMaxPos >= targetPos) { //목표지점에 닿았다
			printResult(true);
			return 0;
		}

		if (curMaxPos == nextMaxPos) { //나보다 멀리 던질 사람도 없고, 목표에 도달하지도 못함.
			printResult(false);
			return 0;
		}
	}
}