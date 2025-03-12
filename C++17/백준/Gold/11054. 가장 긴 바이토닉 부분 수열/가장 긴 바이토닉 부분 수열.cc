		#include <iostream>
		#include <vector>
		using namespace std;

		int main() {
			ios::sync_with_stdio(0);	
			cin.tie(0);

			int n;
			cin >> n; //입력받기

			vector<int> a(n);
			for (int i = 0; i < n ; i++) {
				cin >> a[i];
			}

			if (n == 1) {
				cout << 1; 
				return 0;
			}

			vector<int> inc_arr(n, 1);
			inc_arr[0] = 1;
			
			for (int i = 1; i < n; i++) {
				for (int j = 0; j < i; j++) {
					if (a[i] > a[j]) {
						inc_arr[i] = max(inc_arr[i], inc_arr[j] + 1);
					}
				}
			}

			vector<int> dec_arr(n, 1);
			for (int i = n - 2; i >= 0; i--) {
				for (int j = n - 1; j > i; j--) {
					if (a[i] > a[j]) {
						dec_arr[i] = max(dec_arr[i], dec_arr[j] + 1);
					}
				}
			}

			int result = inc_arr[0] + dec_arr[0] - 1;
			for (int i = 1; i < n; i++) {
				result = max(result, inc_arr[i] + dec_arr[i] - 1);
			}
			cout << result;
			return 0;
		}