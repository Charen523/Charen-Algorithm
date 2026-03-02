#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, k; cin >> n >> k;
    int result = 0;

    // N개의 물병. 시작은 모두 1L 씩.
    // 한 번에 K개씩 이동 가능
    // 이동 단 1번만.

    //같은 양 물병 2개 -> 합치기. -> 반복
    int mixedCount = n;
    long curValue = 1;
    vector<int> mixedResult;
    while (mixedCount > 1) {
        if (mixedCount % 2 != 0) {
            mixedResult.push_back(curValue);
        }
        mixedCount /= 2;
        curValue *= 2;
    }
    mixedResult.push_back(curValue);

    curValue = 2;
    while (mixedResult.size() > k) {
        result += (curValue - mixedResult[0]);
        mixedResult[0] = curValue;
        if (mixedResult[1] == mixedResult[0]) {
            mixedResult[1] *= 2;
            mixedResult.erase(mixedResult.begin());
        }
        curValue *= 2;   
    }

    cout << result;
	return 0;
}