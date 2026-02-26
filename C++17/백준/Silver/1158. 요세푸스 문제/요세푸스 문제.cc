#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a;
    a.reserve(n);
    for (int i = 1; i <= n; i++) a.push_back(i);

    vector<int> ans;
    ans.reserve(n);

    int idx = 0;
    while (!a.empty()) {
        idx = (idx + k - 1) % (int)a.size();
        ans.push_back(a[idx]);
        a.erase(a.begin() + idx);
        // idx는 erase 후 이미 다음 원소를 가리키는 인덱스가 됨
        // (벡터가 줄었으니 그대로 두면 됨)
        if (idx == (int)a.size()) idx = 0;
    }

    cout << "<";
    for (int i = 0; i < n; i++) {
        if (i) cout << ", ";
        cout << ans[i];
    }
    cout << ">";
    return 0;
}