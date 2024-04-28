# include <bits/stdc++.h>
using namespace std;

int init = [] {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ofstream out("user.out");
  cout.rdbuf(out.rdbuf());
  for (string s; getline(cin, s); cout << '\n') {
    string t;
    getline(cin, t);
    int tar = stoi(t);
    for (int i = 0, _i = 1, _n = s.length(); _i < _n; ++i, ++_i) {
      bool _neg = 0;
      if (s[_i] == '-')
        ++_i, _neg = 1;
      int v = s[_i++] & 15;
      while ((s[_i] & 15) < 10)
        v = v * 10 + (s[_i++] & 15);
      if (_neg)
        v = -v;
      if (v == tar) {
        cout << i;
        goto next;
      }
      if (v > tar)
        break;
    }
    cout << -1;
  next:;
  }
  exit(0);
  return 0;
}();

#define MAX 100000
int l, r, n, m, a[MAX];
long long k;
pair<int, long long> frequency[MAX];

bool comp(const pair<int, long long> &p1, const pair<int, long long> &p2) {
    return p1.second > p2.second;
}

int main() { 
    cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int j;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        for (j = l-1; j <= r-1; ++j) {
            frequency[j].first = j;
            frequency[j].second = frequency[j].second + 1;
        }
    }

    sort(frequency, frequency + n, comp);
    int curr;
    for (int i = 0; i < n; ++i) {
        curr = a[frequency[i].first];
        if (k <= curr) {
            a[frequency[i].first] = curr - k;
            break;
        } else {
            a[frequency[i].first] = 0;
            k = k - curr;
        }
    }

    long long total = 0;

    for (int i = 0; i < n; ++i) {
        total += a[frequency[i].first] * frequency[i].second;
    }

    cout << total << endl;
    return 0; 
}