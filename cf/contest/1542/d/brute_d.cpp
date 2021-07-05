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
const int inf = 0x3f3f3f3f, mod = 998244353;

int main() {
    setIO("4");

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == '+') {
            a[i].first = 1;
            cin >> a[i].second;
        }
    }
    long long sol = 0;
    for (int i = 0; i < (1 << n); ++i) {
        multiset<int> cur;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                if (a[j].first) {
                    cur.insert(a[j].second);
                } else if (!cur.empty()) {
                    cur.erase(cur.begin());
                }
            }
        }
        long long sum = 0;
        for (auto &j : cur) {
            sum += j;
            sum %= mod;
        }
        sol += sum;
        sol %= mod;
    }
    cout << sol << "\n";
    return 0;
}
