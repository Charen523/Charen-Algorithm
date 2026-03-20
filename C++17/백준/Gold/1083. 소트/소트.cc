#include <iostream>
#include <vector>
using namespace std;

int N, S;

void sort(vector<int>& v) {
    int ptr = 0; //바꿀 자리 위치

    //앞으로 끌어올릴 수의 위치
    int maxIdx, maxValue;

    while (S > 0 && ptr < N - 1) {
        //끌올 수 초기화
        maxIdx = ptr; maxValue = v[ptr];

        int limit = min(N - 1, ptr + S);
        for (int i = ptr + 1; i <= limit; i++) {
            if (maxValue < v[i]) {
                maxIdx = i;
                maxValue = v[i];
            }
        }

        for (int i = maxIdx; i > ptr; i--) {
            swap(v[i], v[i - 1]);
            S--;
        }

        ptr++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    cin >> S;
    sort(v);

    for (int i = 0; i < N; i++) {
        cout << v[i] << ' ';
    }
    return 0;
}