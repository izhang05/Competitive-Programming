#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("2.in", "r", stdin);
#endif
}

const int maxn = 1e5;

int num[maxn];

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
            num[i] = 0;
        }
        int i = 0, miss = k, sol = 0;
        for (int j = 0; j < n; ++j) {
            if (++num[a[j]] == 1) {
                --miss;
                while (!miss) {
                    if (--num[a[i++]] == 0) {
                        ++miss;
                    }
                }
            }
            sol = max(sol, j - i + 1);
        }
        cout << sol << "\n";
    }
    return 0;
}
