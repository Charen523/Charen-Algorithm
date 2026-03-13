#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> nums;

void make_reduce(long long cur, int next_max) {
    nums.push_back(cur);

    for (int i = 0; i <= next_max; i++) {
        make_reduce(cur * 10 + i, i - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i <= 9; i++) {
        make_reduce(i, i - 1);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    if (N >= (int)nums.size()) cout << -1;
    else cout << nums[N];

    return 0;
}