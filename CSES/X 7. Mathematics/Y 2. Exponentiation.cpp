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

const int mod = 1e9 + 7, maxlog = 31;


long long e[maxlog];

int main() {
    setIO();
    int t;
    cin >> t;
    int a, b;
    while (t--) {
        cin >> a >> b;
        e[0] = a;
        for (int i = 1; i < maxlog; ++i) {
            if (i <= b) {
                e[i] = e[i - 1] * e[i - 1];
                e[i] %= mod;
            }
        }
        long long sol = 1;
        while (b) {
            sol *= e[(int) log2(b)];
            b -= pow(2, (int) log2(b));
            sol %= mod;
        }
        cout << sol << endl;
    }
    return 0;
}
