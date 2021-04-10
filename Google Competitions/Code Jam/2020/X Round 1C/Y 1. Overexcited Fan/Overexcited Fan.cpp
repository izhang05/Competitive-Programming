#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int maxn = 2e3 + 5, inf = 0x3f3f3f3f;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
map<char, int> c{{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};

void solve() {
    int x, y;
    cin >> x >> y;
    swap(x, y);
    string s;
    cin >> s;
    pair<int, int> cur{x, y};
    int sol=inf;
    int d = 1;
    for (auto i : s) {
        cur = {cur.first + dx[c[i]], cur.second + dy[c[i]]};
        if (abs(cur.first) + abs(cur.second) <= d) {
            sol = min(sol, d);
        }
        ++d;
    }
    if (sol == inf) {
        cout << "IMPOSSIBLE"
             << "\n";
    } else {
        cout << sol << "\n";
    }
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
