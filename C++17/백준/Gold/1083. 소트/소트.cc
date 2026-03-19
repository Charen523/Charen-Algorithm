#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& v, int count) {
    int size = static_cast<int>(v.size());
    int ptr = 0;

    while (count > 0 && ptr < size) {
        int maxIdx = ptr;
        int limit = min(size - 1, ptr + count);

        for (int i = ptr; i <= limit; i++) {
            if (v[maxIdx] < v[i]) {
                maxIdx = i;
            }
        }

        if (maxIdx != ptr) {
            count -= (maxIdx - ptr);

            for (int i = maxIdx; i > ptr; i--) {
                swap(v[i], v[i - 1]);
            }
        }

        ptr++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int S;
    cin >> S;

    sort(v, S);

    for (int i = 0; i < N; i++) {
        cout << v[i] << ' ';
    }

    return 0;
}