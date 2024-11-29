#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<char, int>> cards(5);
    for (auto& card : cards) {
        cin >> card.first >> card.second;
    }

    // 정렬 및 빈도 계산
    unordered_map<int, int> cardNumMap;
    bool isFlush = true;
    for (int i = 0; i < 5; i++) {
        cardNumMap[cards[i].second]++;
        if (i > 0 && cards[i].first != cards[0].first) {
            isFlush = false;
        }
    }
    sort(cards.begin(), cards.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
    });

    // Straight 판별
    bool isStraight = true;
    for (int i = 1; i < 5; i++) {
        if (cards[i].second != cards[i - 1].second + 1) {
            isStraight = false;
            break;
        }
    }

    if (isFlush && isStraight) { //1 : 최고숫자 + 900
        cout << 900 + cards[4].second;
        return 0;
    }

    int two1 = 0, two2 = 0, three = 0, four = 0;
    for (const auto& [num, count] : cardNumMap) {
        if (count == 4) four = num;
        else if (count == 3) three = num;
        else if (count == 2) {
            if (two1 == 0) two1 = num;
            else two2 = max(two1, num), two1 = min(two1, num);
        }
    }

    if (four) { //2 : 같은 숫자 + 800
        cout << 800 + four;
    } else if (three && two1) { //3 : x * 10 + y + 700
        cout << 700 + three * 10 + two1;
    } else if (isFlush) { //가장 큰 숫자 + 600
        cout << 600 + cards[4].second;
    } else if (isStraight) { //가장 큰 숫자 + 500
        cout << 500 + cards[4].second;
    } else if (three) { //같은 숫자 + 400
        cout << 400 + three;
    } else if (two1 && two2) { //큰 숫자 * 10 + 작은 숫자 + 300
        cout << 300 + two2 * 10 + two1;
    } else if (two1) { //같은 숫자 + 200
        cout << 200 + two1;
    } else { //가장 큰 숫자 + 100
        cout << 100 + cards[4].second;
    }

    return 0;
}