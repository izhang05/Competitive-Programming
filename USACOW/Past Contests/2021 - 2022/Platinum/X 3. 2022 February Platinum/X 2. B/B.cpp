#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops,Ofast")
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


int main() {
    setIO("1");
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    gp_hash_table<long long, long long> mem;
    int q;
    cin >> q;
    while (q--) {
        long long x;
        cin >> x;
        if (sum % x != 0) {
            cout << -1 << "\n";
            continue;
        }
        if (mem.find(x) != mem.end()) {
            cout << mem[x] << "\n";
            continue;
        }
        vector<long long> cur(a.begin(), a.end());
        long long sol = 0;
        for (int i = 0; i < n;) {
            if (cur[i] >= x) {
                if (cur[i] % x != 0) {
                    sol += cur[i] / x;
                    cur[i] %= x;
                } else {
                    sol += cur[i] / x - 1;
                    ++i;
                }
            } else {
                ++sol;
                cur[i + 1] += cur[i];
                ++i;
            }
        }
        cout << sol << "\n";
        mem[x] = sol;
    }
    return 0;
}
