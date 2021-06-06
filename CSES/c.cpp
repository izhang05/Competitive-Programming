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
    setIO("c");

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<int> a;
        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            if (b % 2 == 0) {
                a.push_front(b);
            } else {
                a.push_back(b);
            }
        }
        int sol = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (gcd(a[i], 2 * a[j]) > 1) {
                    ++sol;
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
