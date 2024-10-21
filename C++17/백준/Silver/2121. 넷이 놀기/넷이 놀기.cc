#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

int countRectangles(const vector<Point>& points, int A, int B) {
    unordered_map<int, unordered_set<int>> x_map; 

    for (const Point& point : points) {
        x_map[point.x].insert(point.y);
    }

    int count = 0;

    for (const auto& point : points) {
        int x = point.x;
        int y = point.y;

        if (x_map.count(x + A) && x_map[x + A].count(y) &&
            x_map.count(x) && x_map[x].count(y + B) &&
            x_map.count(x + A) && x_map[x + A].count(y + B)) {
            count++;
        }
    }

    return count;
}

int main() {
    int dotNum, width, height;
    cin >> dotNum >> width >> height;

    vector<Point> points(dotNum);

    for (int i = 0; i < dotNum; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    cout << countRectangles(points, width, height) << endl;
}
