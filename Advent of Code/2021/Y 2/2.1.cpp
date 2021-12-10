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

void solve() {
    int n = 1000;
    vector<pair<string, int>> a(n);
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first == "forward") {
            x += a[i].second;
        } else if (a[i].first == "down") {
            y += a[i].second;
        } else {
            y -= a[i].second;
        }
    }
    cout << x * y << "\n";
}

int main() {
    setIO("2");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
