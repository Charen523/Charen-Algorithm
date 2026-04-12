#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const bool numInfo[10][5][3] = {
    {
        {1, 1, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1}
    },
    {
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    {
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1}
    },
    {
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    },
    {
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    {
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    },
    {
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    },
    {
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    },
    {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    }
};

bool isPossible(const vector<string>& board, int startCol, int digit) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 3; c++) {
            bool cur = (board[r][startCol + c] == '#');
            bool fixed = numInfo[digit][r][c];

            if (cur && !fixed) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> board(5);
    for (int i = 0; i < 5; i++) {
        cin >> board[i];
    }

    long double answer = 0.0L;
    long double placeValue = 1.0L;

    for (int pos = N - 1; pos >= 0; pos--) {
        int startCol = pos * 4;
        int count = 0;
        int sum = 0;

        for (int digit = 0; digit <= 9; digit++) {
            if (isPossible(board, startCol, digit)) {
                count++;
                sum += digit;
            }
        }

        if (count == 0) {
            cout << -1;
            return 0;
        }

        answer += (static_cast<long double>(sum) / count) * placeValue;
        placeValue *= 10.0L;
    }

    cout << fixed << setprecision(10) << static_cast<double>(answer);
    return 0;
}