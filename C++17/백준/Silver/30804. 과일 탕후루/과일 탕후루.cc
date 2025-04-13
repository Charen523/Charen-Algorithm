#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<int> fruits(n);
    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }

    int max_size = 0;
    unordered_map<int, int> fruit_count;
    int left = 0;

    for (int right = 0; right < n; right++) {
        fruit_count[fruits[right]]++;

        // 과일 종류가 2개 초과일 경우, 왼쪽 포인터를 이동
        while (fruit_count.size() > 2) {
            fruit_count[fruits[left]]--;
            if (fruit_count[fruits[left]] == 0) {
                fruit_count.erase(fruits[left]);
            }
            left++;
        }

        // 두 종류의 과일이 포함된 구간의 크기 계산
        max_size = max(max_size, right - left + 1);
    }

    cout << max_size << endl;

    return 0;
}