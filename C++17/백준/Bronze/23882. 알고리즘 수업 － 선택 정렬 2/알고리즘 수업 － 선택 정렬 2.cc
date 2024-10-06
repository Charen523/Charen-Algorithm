#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int>& arr, int size, int count) {
    int lastIndex = size - 1;
    for (int i = 0; i < count; ) {
        int maxValue = arr[lastIndex];
        int maxIndex = lastIndex;
        
        for (int j = lastIndex - 1; j >= 0; j--) {
            if (maxValue < arr[j]) {
                maxValue = arr[j];
                maxIndex = j;
            }
        }

        if (maxIndex != lastIndex) {
            swap(arr[maxIndex], arr[lastIndex]);
            i++;
        }
        lastIndex--;

        if (lastIndex < 0) {
            cout << -1;
            return;
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
}

int main() {
    int size, count;
    cin >> size >> count;

    vector<int> unsortedArr(size);
    for (int i = 0; i < size; i++) {
        cin >> unsortedArr[i];
    }

    selection_sort(unsortedArr, size, count);
}