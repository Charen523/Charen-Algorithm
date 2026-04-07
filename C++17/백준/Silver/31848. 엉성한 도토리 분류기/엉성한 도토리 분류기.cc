#include <iostream>
#include <vector>
using namespace std;

int lowerBoundIndex(const vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;
    int answer = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= target) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> filteredValues;
    vector<int> filteredIndices;

    filteredValues.reserve(N);
    filteredIndices.reserve(N);

    int maxValue = 0;

    for (int i = 0; i < N; i++) {
        int hole;
        cin >> hole;

        int value = hole + i;

        if (filteredValues.empty() || value > maxValue) {
            filteredValues.push_back(value);
            filteredIndices.push_back(i + 1);
            maxValue = value;
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int nut;
        cin >> nut;

        int idx = lowerBoundIndex(filteredValues, nut);
        cout << filteredIndices[idx] << ' ';
    }

    return 0;
}