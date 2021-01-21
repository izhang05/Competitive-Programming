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

// prefix for num_sheets
// set of seen unpaired magnets
// set of seen iron

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool attract[n];
        int pre[n + 1];
        memset(attract, 0, sizeof(attract));
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + s[i] == ':';
        }

        int sol = 0;
        for (int i = 0; i < n; ++i) {
            if (attract[i]) {
                ++sol;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
