#include <iostream>
using namespace std;

int main() {
    int N, m, M, T, R;
    cin >> N >> m >> M >> T >> R;
    
    int current_pulse = m;
    int exercise_time = 0;
    int total_time = 0;

    if (M - m < T) {
        // 운동을 1분도 할 수 없는 경우
        cout << -1 << endl;
        return 0;
    }

    while (exercise_time < N) {
        if (current_pulse + T <= M) {
            // 운동할 수 있는 경우
            current_pulse += T;
            exercise_time++;
        } else {
            // 운동을 할 수 없으므로 휴식
            current_pulse = max(m, current_pulse - R);
        }
        total_time++;
    }

    cout << total_time << endl;

    return 0;
}
