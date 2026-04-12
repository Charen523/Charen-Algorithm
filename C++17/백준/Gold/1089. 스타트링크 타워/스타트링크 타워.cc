#include <iostream>
#include <vector>
using namespace std;

const bool numInfo[10][5][3] = {
    // 0
    {
        {1, 1, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1}
    },
    // 1
    {
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    // 2
    {
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1}
    },
    // 3
    {
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    },
    // 4
    {
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    // 5
    {
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    },
    // 6
    {
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    },
    // 7
    {
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    // 8
    {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    },
    // 9
    {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    }
};

bool isAvailable(const bool input[5][3], const bool fixedNum[5][3]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (input[i][j] == fixedNum[i][j]) continue;
            if (!input[i][j]) continue;
            return false;
        }
    }

    return true;
}

double findAvg(const bool arr[5][3]) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (isAvailable(arr, numInfo[i])) {
            sum += i;
            count++;
        }
    }

    if (count == 0) return -1;
    return (double)sum / count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int N; cin >> N; 
    vector<string> input(5);
    for (int i = 0; i < 5; i++) {
        cin >> input[i];
    }

    int rowPtr = 0;
    double result = 0;
    for (int i = N; i > 0; i--) {
        bool curNum[5][3];
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 3; y++) {
                char info = input[x][y + rowPtr];
                if (info == '#') curNum[x][y] = true;
                else if (info == '.') curNum[x][y] = false;
            }
        }

        double curResult = findAvg(curNum);
        if (curResult == -1) {
            cout << -1;
            return 0;
        }
        for (int j = 1; j < i; j++) {
            curResult *= 10;
        }
        result += curResult;

        rowPtr += 4;
    }

    cout << result;
	return 0;
}