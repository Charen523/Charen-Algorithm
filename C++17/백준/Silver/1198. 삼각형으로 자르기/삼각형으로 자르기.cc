#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> // 출력 포맷 설정에 필요

using namespace std;

struct Point {
    long long x; // 좌표 범위가 크므로 long long 사용
    long long y;
};

double calculateTriangleArea(const Point& p1, const Point& p2, const Point& p3) {
    // 넓이 계산 중간값은 정수 범위에서 계산되므로 double로 변환
    double area = abs(static_cast<double>(p1.x) * (p2.y - p3.y) +
        static_cast<double>(p2.x) * (p3.y - p1.y) +
        static_cast<double>(p3.x) * (p1.y - p2.y)) / 2.0;
    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double result = 0.0;

    // 모든 조합 탐색
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                double area = calculateTriangleArea(points[i], points[j], points[k]);
                result = max(result, area);
            }
        }
    }

    // 결과 출력: 소수점 9자리까지
    cout << fixed << setprecision(9) << result << endl;

    return 0;
}
