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
    setIO("13");
    int n;
    cin >> n;
    vector<string> sol{"0", "1"};
    for (int i = 2; i <= n; ++i) {
        sol.resize(1 << i);
        for (int j = 1 << (i - 1); j < (1 << i); ++j) {
            sol[j] = sol[(1 << i) - j - 1];
            sol[j].push_back('1');
            sol[(1 << i) - j - 1].push_back('0');
        }
    }
    for (auto &i : sol) {
        cout << i << "\n";
    }
    return 0;
}
