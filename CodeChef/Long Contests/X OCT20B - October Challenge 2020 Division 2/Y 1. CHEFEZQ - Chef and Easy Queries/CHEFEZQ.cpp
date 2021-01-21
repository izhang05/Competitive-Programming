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
        int n, k;
        cin >> n >> k;
        long long q, cur = 0;
        bool sol = false;
        for (int i = 0; i < n; ++i) {
            cin >> q;
            cur += q - k;
            if (!sol && cur < 0) {
                cout << i + 1 << "\n";
                sol = true;
            }
        }
        if (!sol) {
            cout << n + cur / k + 1 << "\n";
        }
    }
    return 0;
}
