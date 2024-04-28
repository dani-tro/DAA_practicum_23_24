#include <algorithm>
#include <ios>
#include <iostream>

using namespace std;


int n, k;
int a[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);

	//for(int i = 0; i < n;++i) cout << a[i] << " ";

	int curr_len = 0;
	int curr_min = 0;

	int best_len = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] - a[curr_min] <= k) {
			++curr_len;
		}
		else {
		
			best_len = max(best_len, curr_len);
			while(a[i] - a[curr_min] > k) {
				++curr_min;
			}
			curr_len = i - curr_min + 1;
		}
	}
	best_len = max(best_len, curr_len);
	cout << best_len << endl;

	return 0;
}
