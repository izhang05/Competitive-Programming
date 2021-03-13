#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
int dp[10][10];

int main() {
    setIO();

    int n = 10;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
#ifdef DEBUG
            cout << i << " " << j << "\n";
            cout << dp[i][j] << "\n\n";
#endif
        }
    }


    int t;
    cin >> t;
    while (t--) {
        int p, f;
        cin >> p >> f;
        pair<int, int> num;
        cin >> num.first >> num.second;
        int s, w;
        cin >> s >> w;
        if (s > w) {
            swap(s, w);
            swap(num.first, num.second);
        }
        int sol = 0;
        for (int i = 0; i < num.first + 1; ++i) {
#ifdef DEBUG
            cout << i << ":\n";
#endif
            if (i * s > p) {
                break;
            }
            int cur = i, take = min(num.second, (f - (num.first - i) * s) / w);
#ifdef DEBUG
            cout << cur << "\n";
#endif
            cur += take;
#ifdef DEBUG
            cout << cur << "\n";
#endif
            cur += min(f / s, num.first - i);
#ifdef DEBUG
            cout << cur << "\n";
#endif
            cur += min(num.second - take, (f - s * (min(f / s, num.first - i))) / w);
#ifdef DEBUG
            cout << cur << "\n\n\n";
#endif
            sol = max(sol, cur);
        }
        cout << sol << "\n";
    }
    return 0;
}
