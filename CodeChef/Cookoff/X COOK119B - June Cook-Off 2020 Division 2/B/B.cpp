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


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int pre = a[0], next = 2, sol = 1;
        if (next == m) {
            ++next;
        }
        bool found = false;
        if (pre != 1) {
            cout << -1 << "\n";
        } else {
            for (int i = 1; i < n; ++i) {
                if (a[i] == pre) {
                    ++sol;
                } else if (a[i] == next) {
                    ++sol;
                    ++next;
                    pre = a[i];
                    if (next == m) {
                        ++next;
                    }
                } else if (!(a[i] == m && next == m + 1)) {
                    if (pre + 1 >= m) {
                        cout << sol << "\n";
                    } else {
                        cout << -1 << "\n";
                    }
                    found = true;
                    break;
                }
            }
            if (!found) {
                if (m <= a[n - 1] + 1) {
                    cout << sol << "\n";
                } else {
                    cout << -1 << "\n";
                }
            }
        }
        return 0;
    }
}s