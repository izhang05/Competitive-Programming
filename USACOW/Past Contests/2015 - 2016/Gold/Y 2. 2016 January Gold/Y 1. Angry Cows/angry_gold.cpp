/*
ID: izhang01
TASK: angry
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    freopen("angry.out", "w", stderr);
}
//#define DEBUG
#define int long long
const int maxn = 5e4 + 5, inf = 1e18;
int l[maxn], r[maxn];

signed main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a.begin(), a.end());
#ifdef DEBUG
    cout << "a:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
#endif
    l[0] = 0;
    for (int i = 1; i < n;) {
        int j = i;
        while (j < n && a[j] - a[i - 1] <= 2 + l[i - 1]) {
            l[j] = l[i - 1] + 2;
            ++j;
        }
        if (j != i) {
            i = j;
        } else {
            l[i] = a[i] - a[i - 1];
            ++i;
        }
    }
    r[n - 1] = 0;
    for (int i = n - 2; i >= 0;) {
        int j = i;
        while (j >= 0 && a[i + 1] - a[j] <= 2 + r[i + 1]) {
            r[j] = r[i + 1] + 2;
            --j;
        }
        if (j != i) {
            i = j;
        } else {
            r[i] = a[i + 1] - a[i];
            --i;
        }
    }
#ifdef DEBUG
    cout << "l:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << l[i] << " ";
    }
    cout << "\n";
    cout << "r:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << r[i] << " ";
    }
    cout << "\n";
#endif
    int sol = inf;
    for (int i = 0; i < n; ++i) {
        if (l[i] >= r[i]) {
            assert(i != 0);
            sol = max(l[i], r[i]);
            for (int j = a[i - 1]; j < a[i]; ++j) {
                sol = min(sol, max({j - a[i - 1], l[i - 1] + 2, a[i] - j, r[i] + 2}));
#ifdef DEBUG
                cout << j << " " << sol << " " << max({j - a[i - 1], l[i - 1] + 2, a[i] - j, r[i] + 2}) << "\n";
#endif
            }
            break;
        }
    }
    assert(sol != inf);
    cout << fixed << setprecision(1) << double(sol) / 2 << "\n";
    return 0;
}
