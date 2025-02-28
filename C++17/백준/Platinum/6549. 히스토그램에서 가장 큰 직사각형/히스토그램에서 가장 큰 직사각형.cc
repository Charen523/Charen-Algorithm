#include <iostream>
#include <stack>
#define ll long long

using namespace std;

int histogram[100000];
int histogramSize = 0;

//인자 : 시작idx, 끝idx, 너비유지 최대높이
//반환값 : 다음 계산 여부
ll largestRectangle() {
	stack<int> s;
	ll maxArea = 0;

	for (int i = 0; i <= histogramSize; i++) {
		int curHeight = (i == histogramSize) ? 0 : histogram[i];

		while (!s.empty() && histogram[s.top()] > curHeight) {
			int h = histogram[s.top()];
			s.pop();
			ll width = s.empty() ? i : (i - s.top() - 1);
			maxArea = max(maxArea, h * width);
		}
		s.push(i);
	}

	return maxArea;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> histogramSize) {
		if (histogramSize == 0) break;

		//히스토그램 입력
		for (int i = 0; i < histogramSize; i++) {
			cin >> histogram[i];
		}
		cout << largestRectangle() << '\n';
	}
}