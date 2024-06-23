#include <iostream>
#include <vector>

long long MOD = 1000000007;

long long mod(long long x) {
	return (x % MOD + MOD) % MOD;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int s;
	std::cin >> s;

	std::vector<std::vector<std::vector<long long>>> 
		l(s + 1, std::vector<std::vector<long long>>(s + 1, std::vector<long long>(s + 1, 0)));
	
	std::vector<std::vector<std::vector<long long>>>
		h(s + 1, std::vector<std::vector<long long>>(s + 1, std::vector<long long>(s + 1, 0)));

	std::vector<std::vector<std::vector<long long>>>
		lPref(s + 1, std::vector<std::vector<long long>>(s + 1, std::vector<long long>(s + 1, 0)));

	std::vector<std::vector<std::vector<long long>>>
		hPref(s + 1, std::vector<std::vector<long long>>(s + 1, std::vector<long long>(s + 1, 0)));

	for (int i = 1; i <= s; i++) {
		l[i][1][i] = 1;
		lPref[i][1][i] = i;
		h[i][1][i] = 1;
		hPref[i][1][i] = i;
	}



	for (int c = 2; c <= s; c++) {
		for (int i = c; i <= s; i++) {
			for (int j = 1; j <= i; j++) {
				l[i][c][j] = mod(l[i][c][j] + hPref[i - j][c - 1][s] - hPref[i - j][c - 1][j]);
				h[i][c][j] = mod(h[i][c][j] + lPref[i - j][c - 1][j - 1]);
			}

			lPref[i][c][0] = 0;
			hPref[i][c][0] = 0;
			for (int j = 1; j <= s; j++) {
				lPref[i][c][j] = mod(lPref[i][c][j - 1] + l[i][c][j]);
				hPref[i][c][j] = mod(hPref[i][c][j - 1] + h[i][c][j]);
			}
		}


	}

	long long result = 0;

	for (int i = 1; i <= s; i++) {
		result = mod(result + lPref[s][i][s]);
		result = mod(result + hPref[s][i][s]);
	}

	std::cout << result << std::endl;

	return 0;
}