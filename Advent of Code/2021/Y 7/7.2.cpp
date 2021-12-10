#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int tri(int x) {
    return (x * (x + 1)) / 2;
}

void solve() {
    int n = 1000;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long sol = INFL;
    for (int loc = 0; loc < int(1e4); ++loc) {
        long long cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += tri(abs(a[i] - loc));
        }
        sol = min(sol, cur);
    }
    cout << sol << "\n";
}

int main() {
    setIO("7");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
