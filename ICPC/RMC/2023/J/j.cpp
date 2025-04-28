#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> cnt(86405);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int l, r;
            cin >> l >> r;
            for (int k = l; k <= r; ++k) {
                ++cnt[k];
            }
        }
    }
    int mx = 0, s = 0;
    for (auto &i: cnt) {
        if (i > mx) {
            mx = i;
            s = 1;
        } else if (i == mx) {
            ++s;
        }
    }
    cout << mx << "\n" << s << "\n";
}
