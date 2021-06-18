#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), suf(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = suf[i + 1] + a[i];
    }
    long long sol = suf[0];
    suf.erase(find(suf.begin(), suf.end(), suf[0]));
    sort(suf.begin(), suf.end());
    reverse(suf.begin(), suf.end());
    for (int i = 0; i < k - 1; ++i) {
        sol += suf[i];
    }
    cout << sol << "\n";
    return 0;
}
