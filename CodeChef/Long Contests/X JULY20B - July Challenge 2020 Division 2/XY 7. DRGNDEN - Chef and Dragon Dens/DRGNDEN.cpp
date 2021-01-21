#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


vector<int> h;

int vmax(int low, int high) {
    if (low > high) {
        swap(low, high);
    }
    pair<int, int> m{h[low], low};
    for (int i = low + 1; i < high + 1; ++i) {
        if (h[m] > h[low]) {
            m.
        }
    }
    return m;
}


int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    h.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int d, b, c, sol;
    for (int i = 0; i < q; ++i) {
        cin >> d >> b >> c;
        sol = 0;
        --b, --c;
        if (d == 1) {
            a[b] = c;
        } else {
            if (h[b] <= h[c]) {
                cout << -1 << "\n";
            } else {
                while (vmax(b, c) != c) {
                    b = vmax(b, c);
                    sol += a[b];
                }
            }
        }
        if (sol) {
            cout << sol << "\n";
        }
    }
    return 0;
}
