#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;
const int WIDTH = 64;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<string> board(n);
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	// mismatch[i][j] = board[i][j]가 'W' 기준 체스보드와 다르면 true
	vector<vector<bool>> mismatch(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool color = (board[i][j] == 'W') ? 0 : 1;
			bool pos = (i + j) % 2 == 0; // pos == 0이면 흰색이 와야 함
			mismatch[i][j] = (color != pos); // 체스 규칙과 다르면 true
		}
	}

	int result = 1e9;

	// i: 슬라이딩 행의 시작점
	for (int i = 0; i <= n - SIZE; i++) {
		// cols[j]: 현재 i~i+7행에서 각 열의 mismatch 수
		vector<int> cols(m, 0);
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < SIZE; k++) {
				cols[j] += mismatch[i + k][j];
			}
		}

		// 초기 j 슬라이딩 (0 ~ 7열)
		int temp = 0;
		for (int j = 0; j < SIZE; j++) {
			temp += cols[j];
		}
		result = min(result, min(temp, WIDTH - temp));

		// j 방향 슬라이딩 (좌에서 우로 열 슬라이딩)
		for (int j = 1; j <= m - SIZE; j++) {
			// 이전 왼쪽 열 제거, 새 오른쪽 열 추가
			temp = temp - cols[j - 1] + cols[j + SIZE - 1];
			result = min(result, min(temp, WIDTH - temp));
		}
	}

	cout << result << '\n';
	return 0;
}