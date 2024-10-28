#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//left : big frequency, less sequence
void quickSort(vector<pair<int, int>>& arr, int left, int right, unordered_map<int, pair<int, int>>& map) {
	if (left >= right) return;

	auto pivot = arr[(left + right) / 2];
	int i = left, j = right;

	while (i <= j) {
		while (pivot.second < arr[i].second 
			|| (pivot.second == arr[i].second 
				&& map[pivot.first].second > map[arr[i].first].second)) {
			i++;
		}

		while (pivot.second > arr[j].second
			|| (pivot.second == arr[j].second
				&& map[pivot.first].second < map[arr[j].first].second)) {
			j--;
		}

		if (i <= j) {
			swap(arr[i], arr[j]);
			i++; j--;
		}
	}

	if (left < j) quickSort(arr, left, j, map);
	if (i < right) quickSort(arr, i, right, map);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, C;
	cin >> N >> C;

	unordered_map<int, pair<int, int>> numMap; //value, frequency, sequence
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		if (numMap.count(value) == 0) {
			numMap.emplace(value, make_pair(1, i));
		}
		else {
			numMap[value].first++;
		}
	}

	vector<pair<int, int>> sortedNums; //value, frequency
	for (const auto& item : numMap) {
		sortedNums.push_back({ item.first, item.second.first });
	}

	quickSort(sortedNums, 0, sortedNums.size() - 1, numMap);

	for (const auto& [value, frequency] : sortedNums) {
		for (int i = 0; i < frequency; i++)
			cout << value << ' ';
	}
}