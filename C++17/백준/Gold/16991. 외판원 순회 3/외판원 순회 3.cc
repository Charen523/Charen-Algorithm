#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n; //2~16.
	
	vector<pair<int, int>> vertices(n);
	for (int i = 0; i < n; i++) {
		int x, y; // -1000~1000.
		cin >> x >> y; //일치하는 좌표 없음.

		vertices[i] = {x,y};
	}

	// 그래프 초기화
	vector<vector<double>> graph(n, vector<double>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			int x = vertices[j].first - vertices[i].first;
			int y = vertices[j].second - vertices[i].second;
			graph[i][j] = sqrt(x * x + y * y);
		}
	}

	//시작 도시 제외 방문한 도시들의 비트마스크
	int subsetSize = 1 << (n);
	// dp[i][A]: 현재 도시 i에 있고, 방문해야 할 도시들이 A일 때 최소 거리
	vector<vector<double>> dp(n, vector<double>(subsetSize, INF));
	dp[0][1] = 0;
	
	for (int A = 1; A < subsetSize - 1; A++) {
		//시작도시 방문 확인
		if (!(A & 1)) continue; 

		//A에서 현재 방문한 도시
		for (int j = 0; j < n; j++) {
			//아직 방문하지 않은 도시는 무시
			if (!(A & 1 << j)) continue;

			//현재까지의 비용
			double cost = dp[j][A];

			//다음으로 방문할 도시
			for (int i = 1; i < n; i++) {
				//이미 방문한 도시는 무시
				if (A & 1 << i) continue;

				int nextpath = A | (1 << i);
				dp[i][nextpath] = min(dp[i][nextpath], cost + graph[j][i]);
			}
		}
	}

	//시작 도시로 복귀
	double result = INF;
	for (int i = 1; i < n; i++) {
		if (dp[i][subsetSize -1] == INF) continue;
		result = min(result, dp[i][subsetSize -1] + graph[i][0]);
	}
	cout << fixed << setprecision(10) << result;
	return 0;
}