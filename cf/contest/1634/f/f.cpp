/* Author: izhang
 * Time: 02-06-2022 09:35:02
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
int mod;

void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

const int maxn = 3e5 + 5;
int fib[maxn];
void test_case() {
    int n, q;
    cin >> n >> q >> mod;
    fib[0] = 0, fib[1] = 1 % mod;
    for (int i = 2; i < maxn; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        sub(a[i], b);
    }
    vector<int> c(n);
    c[0] = a[0], c[1] = (a[1] - a[0] + mod) % mod;
    for (int i = 2; i < n; ++i) {
        c[i] = (((a[i] - a[i - 1] - a[i - 2]) % mod + mod) % mod);
    }
    set<int> bad;
    for (int i = 0; i < n; ++i) {
        if (c[i]) {
            bad.insert(i);
        }
    }
    while (q--) {
        char t;
        int l, r;
        cin >> t >> l >> r;
        --l;
        if (t == 'A') {
            add(c[l], 1);
            if (r < n) {
                sub(c[r], fib[r - l + 1]); // fib[r - l + 1] = fib[r - l] + fib[r - l - 1]
            }
            if (r + 1 < n) {
                sub(c[r + 1], fib[r - l]);
            }
        } else {
            sub(c[l], 1);
            if (r < n) {
                add(c[r], fib[r - l + 1]);
            }
            if (r + 1 < n) {
                add(c[r + 1], fib[r - l]);
            }
        }
        for (auto &i : vector<int>{l, r, r + 1}) {
            if (i >= n) {
                break;
            }
            if (c[i]) {
                bad.insert(i);
            } else {
                bad.erase(i);
            }
        }
        cout << (bad.empty() ? "YES" : "NO") << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
