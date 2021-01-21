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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << a[0] << "\n";
            continue;
        }
        if (n == 2) {
            cout << max(a[0], a[1]) << "\n";
            continue;
        }
        sort(a.begin(), a.end(), greater<>());
        int sol = 0;
        vector<int> cur{a[0], a[1]};
        for (int i = 2; i < n; ++i) {
            sort(cur.begin(), cur.end());
            sol += cur[0];
            cur[1] -= cur[0];
            cur.erase(cur.begin());
            cur.push_back(a[i]);
        }
        sol += max(cur[0], cur[1]);
        cout << sol << "\n";
    }
    return 0;
}
