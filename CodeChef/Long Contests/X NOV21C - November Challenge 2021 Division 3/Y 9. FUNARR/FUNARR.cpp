#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bitset<maxn> dp;

void solve() {
    dp.reset();
    int n, m;
    cin >> n >> m;
    --n;
    vector<int> a(n);
    int pre;
    cin >> pre;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        a[i] = b - pre;
        pre = b;
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    if (n == 0) {
        cout << "YES" << "\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            cout << "NO" << "\n";
            return;
        }
    }
    int i = 0;
    for (int j = 0; j < m; ++j) {
        dp |= dp << b[j];
        dp[b[j]] = true;
        if (dp[a[i]]) {
            ++i;
            dp.reset();
            if (i == n) {
                cout << "YES" << "\n";
                return;
            }
        }
    }
    cout << "NO" << "\n";
}

int main() {
    setIO("3");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
