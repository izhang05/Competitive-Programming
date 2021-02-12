#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int j = 0, sol = 0;
    for (int i = 0; i < n; ++i) {
        if (j > m - 1) {
            break;
        }
        while (b[j] + k < a[i]) {
            ++j;
            if (j >= m - 1) {
                break;
            }
        }
        if (j > m - 1) {
            break;
        }
        if (abs(b[j] - a[i]) <= k) {
            ++sol;
            ++j;
        }
    }
    cout << sol << "\n";
    return 0;
}
