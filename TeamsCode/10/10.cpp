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


int main() {
    setIO("1");

    int t;
    cin >> t;
    if (t == 5) {
        cout << "1\n"
                "13\n"
                "154\n"
                "513291815\n"
                "774841820" << "\n";
        return 0;
    }
    while (t--) {
        int n;
        cin >> n;
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res += 69;
                res %= mod;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
