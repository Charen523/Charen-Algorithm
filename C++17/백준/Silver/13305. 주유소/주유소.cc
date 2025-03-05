#include <iostream>
#include <vector>
#include <algorithm>
#define ull unsigned long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	int n; //도시의 개수 : 100,000. 
	cin >> n;
	vector<int> road_length(n - 1); //최대 길이 : 1,000,000,000
	for (int i = 0; i < n - 1; i++) {
		cin >> road_length[i]; //도시i에서 도시i+1 길이
	}
	vector<int> city_price(n); //최대 길이 : 1,000,000,000
	for (int i = 0; i < n; i++) {
		cin >> city_price[i];
	}

	ull price = 0;
	for (int i = 0; i < n - 1; ) {
		int cur_price = city_price[i];
		ull cur_length = road_length[i];
		while (cur_price <= city_price[++i] && !(i >= n - 1)) {
			cur_length += road_length[i];
		}	
		price += cur_length * cur_price;
	}
	cout << price << endl;

	return 0;
}