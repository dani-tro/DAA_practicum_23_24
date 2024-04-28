int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (auto& el : arr) cin >> el;

    sort(arr.begin(), arr.end());

    int maxa = 0;
    int maxi = 0;

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            int calc = arr[j] - arr[i];
            if (calc <= k) {
                if ((j - i) > maxi) {
                    maxa = calc;
                    maxi = j - i;
                }
            }
        }
    }

    cout << maxi + 1;

    return 0;
}