/* Author: izhang05
 * Time: 07-22-2021 10:35:05
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 505;
const long long m1 = 1e9 + 9, p0 = 9973, p1 = 10007;

long long pw0[maxn], pw1[maxn]; // Stores the powers of p modulo m1
struct shash {
    int n;
    string s;
    long long hsh0[maxn], hsh1[maxn];

    void calc_hashes() {
        hsh0[0] = 1;
        for (int i = 0; i < n; ++i) {
            hsh0[i + 1] = ((hsh0[i] * p0) % m1 + s[i]) % m1;
        }
        hsh1[0] = 1;
        for (int i = 0; i < n; ++i) {
            hsh1[i + 1] = ((hsh1[i] * p1) % m1 + s[i]) % m1;
        }
    }

    void init(string S) {
        s = S, n = int(s.size());
        calc_pow();
        calc_hashes();
    }

    pair<long long, long long> get_hash(int a, int b) { // [a, b]
        return {(hsh0[b + 1] - (hsh0[a] * pw0[b - a + 1]) % m1 + m1) % m1,
                (hsh1[b + 1] - (hsh1[a] * pw1[b - a + 1]) % m1 + m1) % m1};
    }

    void calc_pow() {
        pw0[0] = 1;
        for (int i = 1; i < maxn; ++i) {
            pw0[i] = (pw0[i - 1] * p0) % m1;
        }
        pw1[0] = 1;
        for (int i = 1; i < maxn; ++i) {
            pw1[i] = (pw1[i - 1] * p1) % m1;
        }
    }
};

void solve() {
    string s, t;
    cin >> s >> t;
    string rev_s(s.begin(), s.end());
    reverse(rev_s.begin(), rev_s.end());
    int n = int(s.size()), m = int(t.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n && j - i < m; ++j) {
            int l = j - (m - (j - i + 1));
#ifdef DEBUG
            cout << i << " " << j << " " << l << "\n";
#endif
            if (l < 0) {
                continue;
            }
            if (s.substr(i, j - i + 1) == t.substr(0, j - i + 1)) {
                if (rev_s.substr(n - j - 1, m - (j - i)) == t.substr(j - i, m - (j - i))) {
                    cout << "YES"
                         << "\n";
                    return;
                }
            }
//            if (s.get_hash(i, j) == t.get_hash(0, j - i)) {
//#ifdef DEBUG
//                cout << s.get_hash(i, j) << " " << t.get_hash(0, j - i) << "\n";
//                cout << l << " " << j << " " << j - i << " " << t.n - 1 << "\n";
//                cout << s.get_hash(l, j) << " " << t.get_hash(j - i, t.n - 1) << "\n";
//#endif
//                if (rev_s.get_hash(s.n - j - 1, s.n - l - 1) == t.get_hash(j - i, t.n - 1)) {
//                }
//            }
        }
    }
    cout << "NO"
         << "\n";
}

int main() {
    setIO("1");

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
