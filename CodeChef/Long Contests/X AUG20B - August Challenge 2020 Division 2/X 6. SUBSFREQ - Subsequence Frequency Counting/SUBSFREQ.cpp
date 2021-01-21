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

const int mod = 1e9 + 7;

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), sol(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }

    }
    return 0;
}
