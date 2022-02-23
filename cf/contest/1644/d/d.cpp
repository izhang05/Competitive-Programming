/* Author: izhang
 * Time: 02-22-2022 15:57:31
**/
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
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long binpow(long long x, long long n, long long m) {
    assert(n >= 0);
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

void test_case() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<pair<int, int>> a(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].first, --a[i].second;
    }
    reverse(a.begin(), a.end());
    set<int> cols, rows;
    int sol = 0;
    for (auto &i : a) {
        if (!((cols.find(i.first) != cols.end() || int(rows.size()) == m) && (rows.find(i.second) != rows.end() || int(cols.size()) == n))) {
            ++sol;
        }
        cols.insert(i.first);
        rows.insert(i.second);
    }
    cout << binpow(k, sol, mod) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
