#include <iostream>
#include <unordered_map>
#include <string>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int U, N;
    cin >> U >> N;

    unordered_map<int, int> price_count;
    unordered_map<int, string> first_bidder;

    for (int i = 0; i < N; ++i) {
        string name;
        int price;
        cin >> name >> price;

        // 최초로 제시된 가격을 기록
        if (first_bidder.find(price) == first_bidder.end()) {
            first_bidder[price] = name;
        }

        // 가격 제시 횟수 카운팅
        price_count[price]++;
    }

    int min_count = numeric_limits<int>::max();
    int winning_price = numeric_limits<int>::max();

    // 가장 적게 제시된 최저 가격을 찾는다
    for (const auto& [price, count] : price_count) {
        if ((count < min_count) || (count == min_count && price < winning_price)) {
            min_count = count;
            winning_price = price;
        }
    }

    // 낙찰자 출력
    cout << first_bidder[winning_price] << " " << winning_price << "\n";

    return 0;
}
