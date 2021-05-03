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
    setIO("11");
    int n;
    cin >> n;
    vector<int> occ(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        occ[a - 1] = i;
    }
    int sol = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (occ[i + 1] < occ[i]) {
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}
