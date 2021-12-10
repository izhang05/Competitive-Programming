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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n = 2000;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int pre_sum = 0;
    for (int i = 0; i < 3; ++i) {
        pre_sum += a[i];
    }
    int sol = 0;
    for (int i = 0; i < n - 2; ++i) {
        int cur = 0;
        for (int j = 0; j < 3; ++j) {
            cur += a[i + j];
        }
        if (cur > pre_sum) {
            ++sol;
        }
        pre_sum = cur;
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
