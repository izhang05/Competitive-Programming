#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        long long n, solution = 0, alice = 0, bob = 0;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            if (alice == bob && a[i] == b[i]) {
                solution += a[i];
            }
            alice += a[i];
            bob += b[i];
        }
        cout <<  solution << "\n";
    }
    return 0;
}
