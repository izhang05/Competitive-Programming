#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long double> miners, diamonds;
        for (int i = 0; i < 2 * n; ++i) {
            int x, y;
            cin >> x >> y;
            if (x == 0) {
                miners.push_back(abs(y));
            } else {
                diamonds.push_back(abs(x));
            }
        }
        long double sol = 0;
        sort(miners.begin(), miners.end());
        sort(diamonds.begin(), diamonds.end());
        for (int i = 0; i < n; ++i) {
            sol += sqrt(miners[i] * miners[i] + diamonds[i] * diamonds[i]);
#ifdef DEBUG
            cout << sqrt(miners[i] * miners[i] + diamonds[i] * diamonds[i]) * sqrt(miners[i] * miners[i] + diamonds[i] * diamonds[i]) << "\n";
#endif
        }
        cout << fixed << setprecision(15) << sol << "\n";
    }
    return 0;
}
