#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    multiset<int> orderedA(A.begin(), A.end());
    multiset<int, greater<int>> orderedB(B.begin(), B.end());

    int result = 0;

    auto itA = orderedA.begin();
    auto itB = orderedB.begin();

    for (int i = 0; i < N; i++) {
        result += (*itA) * (*itB);
        ++itA;
        ++itB;
    }

    cout << result;
    return 0;
}