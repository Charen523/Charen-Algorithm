#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int N; cin >> N;

    vector<int> result(N, 0);
    for (int i = 0; i < N; i++) {
        int num; cin >> num;

        int ptr = 0;
        for (int j = 0; j < N; j++) {
            if (result[j] == 0) num--;
            if (num == 0 && result[j + 1] == 0) {
                ptr = j + 1;
                break;
            }
        }
        result[ptr] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << ' ';
    }

	return 0;
}