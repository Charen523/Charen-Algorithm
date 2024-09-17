#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(NULL); // 입출력 묶음 해제

    int pointCount;
    cin >> pointCount;

    vector<pair<int, int>> pointVector;
    pointVector.reserve(pointCount); // 벡터 크기 미리 할당 (최적화)

    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;
        pointVector.emplace_back(x, y); // push_back보다 빠른 emplace_back 사용
    }

    sort(pointVector.begin(), pointVector.end());

    for (const auto& point : pointVector) {
        cout << point.first << " " << point.second << "\n"; // endl 대신 "\n" 사용 (빠른 출력)
    }

    return 0;
}
