#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int rabbitCount, dayCount;
	cin >> rabbitCount >> dayCount;

	int blockSize = static_cast<int>(std::sqrt(rabbitCount));
	
	vector<int> matchGroup(rabbitCount, 0); //성냥갑에 들어있는 성냥의 수.
	vector<int> cupGroup(blockSize + 1, 0); //컵에 들어있는 성냥의 수.
	
	if (blockSize * blockSize == rabbitCount) {
		cupGroup.pop_back();
	}

	for (int i = 0; i < dayCount; i++) {
		vector<int*> ptrVec;
		int repeat, idx;
		cin >> repeat >> idx;
		idx--;

		/*첫번째 블럭*/

		while (repeat > 0 && idx % blockSize != 0) {
			ptrVec.push_back(&matchGroup[idx]); //성냥갑 주소 저장.
			matchGroup[idx]++; //성냥 추가.
			
			idx++; repeat--;
		}

		/*컵*/
		int cupIdx = idx / blockSize;
		while (repeat >= blockSize) {
			ptrVec.push_back(&cupGroup[cupIdx]); //컵 주소 저장.
			cupGroup[cupIdx]++; //성냥 추가.

			idx += blockSize;
			repeat -= blockSize;
			cupIdx++;
		}

		/*마지막 블럭*/
		if (repeat != 0 && repeat == rabbitCount - idx) {
			ptrVec.push_back(&cupGroup[cupIdx]); //컵 기억
			cupGroup[cupIdx]++;
		}
		else {
			while (repeat > 0) {
				ptrVec.push_back(&matchGroup[idx]); //성냥갑 기억.		
				matchGroup[idx]++; //성냥 추가

				idx++; //group의 끝 저장
				repeat--; //딸기 소모.
			}
		}

		/*결과 정리 & 출력*/
		int result = 0;
		for (int* ptr : ptrVec) {
			result += *ptr;
		}

		cout << result << '\n';
	}
}