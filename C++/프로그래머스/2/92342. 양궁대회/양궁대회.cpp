#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int vSize = 11;
int maxScore;

vector<int> peachInfo;
vector<int> answer;
vector<int> curScore;
vector<int> leftScore;

bool isBetterAnswer(vector<int>& a, vector<int>& b) {
    for (int i = vSize - 1; i >= 0; i--) {
        if (a[i] != b[i]) return a[i] > b[i];
    }

    return false;
}

void backTracking(int level, int tokenCount, int score) {
    if (level >= vSize) {
        curScore[10] += tokenCount;

        if (score > maxScore) {
            maxScore = score;
            answer = curScore;
        }
        else if (score == maxScore && isBetterAnswer(curScore, answer)) {
            answer = curScore;
        }

        curScore[10] -= tokenCount;
        return;
    }

    if (score + leftScore[level] < maxScore) return;

    int usedToken = peachInfo[level] + 1;

    curScore[level] = 0;
    backTracking(level + 1, tokenCount, score);

    if (tokenCount >= usedToken) {
        curScore[level] = usedToken;

        int newScore = score + (10 - level);
        if (peachInfo[level] > 0) {
            newScore += (10 - level);
        }

        backTracking(level + 1, tokenCount - usedToken, newScore);
    }

    curScore[level] = 0;
}

vector<int> solution(int n, vector<int> info) {
    peachInfo = info;

    answer.clear();
    curScore.clear();
    leftScore.clear();

    answer.resize(vSize);
    curScore.resize(vSize);
    leftScore.resize(vSize);

    int peachScore = 0;
    for (int i = 0; i < vSize; i++) {
        if (info[i] > 0) peachScore += 10 - i;
    }

    maxScore = -peachScore;

    leftScore[10] = 0;
    for (int i = 9; i >= 0; i--) {
        leftScore[i] = (10 - i) * 2 + leftScore[i + 1];
    }

    backTracking(0, n, -peachScore);

    if (maxScore <= 0) {
        vector<int> defaultV(1);
        defaultV[0] = -1;
        return defaultV;
    }

    return answer;
}