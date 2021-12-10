/* Author: izhang05
 * Time: 12-02-2021 17:11:26
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxp = 10;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long cost[maxp];

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    long long sol = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] != b[i]) {
            long long d = b[i] - a[i];
            for (int j = i; j < n; j += i + 1) {
                a[j] += d;
            }
            sol += d;
        }
    }

    int q;
    cin >> q;
    long long pre = a[0];
    while (q--) {
        long long cur;
        cin >> cur;



        pre = cur;
        cout << sol << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
0