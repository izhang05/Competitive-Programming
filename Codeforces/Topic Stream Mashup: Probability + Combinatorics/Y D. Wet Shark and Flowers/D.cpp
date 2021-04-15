#include <bits/stdc++.h>

using namespace std;

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    setIO("1");
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> a(n);
    vector<long double> pr(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        pr[i] = (long double) (a[i].second / p - int((a[i].first - 1) / p)) / (a[i].second - a[i].first + 1);
    }
    long double sol = 0;
    for (int i = 0; i < n; ++i) {
        int ne = (i + 1) % n;
        sol += 2000 * (pr[i] + pr[ne] - pr[i] * pr[ne]);
    }
    cout << fixed << setprecision(15) << sol << "\n";
    return 0;
}
