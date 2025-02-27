#include <iostream>

using namespace std;

int A[500001] = { 0 };
int temp[500001] = { 0, };
int cnt;
bool isEnd;

void merge_sort(int l, int r);
void merge(int left, int mid, int right);

void merge_sort(int l, int r) {
    if (isEnd) return;

    if (l < r) {
        int mid = (l + r) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        merge(l, mid, r);
    }
}

void merge(int left, int mid, int right) {
    int i = left, j = mid + 1, t = 1;

    while (i <= mid && j <= right) {
        if (A[i] <= A[j]) {
            temp[t++] = A[i++];
        }
        else {
            temp[t++] = A[j++];
        }
    }

    while (i <= mid) temp[t++] = A[i++];
    while (j <= right) temp[t++] = A[j++];

    i = left; t = 1;
    while (i <= right) {
        A[i++] = temp[t++];
        if (--cnt == 0) {
            cout << A[i - 1];
            isEnd = true;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    cnt = k;
    isEnd = false;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    merge_sort(0, n - 1);
    
    if (!isEnd) cout << -1;
}
