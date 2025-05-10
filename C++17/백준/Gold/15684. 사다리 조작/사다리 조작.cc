#include <iostream>
#include <vector>
using namespace std;

int n, m, h;
bool ladder[31][11]; // ladder[a][b] = a번째 줄에서 b번 세로선과 b+1번 세로선 사이에 사다리 있음
int result = -1;

bool check_ladder() {
	for (int i = 1; i <= n; i++) {
		int pos = i;
		for (int j = 1; j <= h; j++) {
			if (ladder[j][pos]) pos++;
			else if (ladder[j][pos - 1]) pos--;
		}
		if (pos != i) return false;
	}
	return true;
}

void dfs(int count, int x, int y) {
	if (count > 3) return;

	if (check_ladder()) {
		if (result == -1 || result > count)
			result = count;
		return;
	}

	for (int i = x; i <= h; i++) {
		for (int j = (i == x ? y : 1); j < n; j++) {
			if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1])
				continue;
			ladder[i][j] = true;
			dfs(count + 1, i, j);
			ladder[i][j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = true;
	}

	dfs(0, 1, 1);

	cout << result << '\n';
	return 0;
}
