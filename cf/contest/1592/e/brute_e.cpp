#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = 0;
    for (int l = 0; l < n; ++l) {
        int and_sum = a[l], xor_sum = 0;
        for (int r = l; r < n; ++r) {
            and_sum &= a[r];
            xor_sum ^= a[r];
            if (and_sum > xor_sum) {
                sol = max(sol, r - l + 1);
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
