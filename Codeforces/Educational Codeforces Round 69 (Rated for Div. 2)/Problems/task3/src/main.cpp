#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), gap;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) {
            gap.push_back(a[i] - a[i - 1]);
        }
    }
    sort(gap.begin(), gap.end());
    reverse(gap.begin(), gap.end());
    int sol = a[n - 1] - a[0];
    for (int i = 0; i < k - 1; ++i) {
        sol -= gap[i];
    }
    cout << sol << "\n";
    return 0;
}
