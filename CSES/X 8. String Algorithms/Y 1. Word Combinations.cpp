#include <bits/stdc++.h>

#include <utility>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long m1 = 1e9 + 9, p = 9973;

long long pw[maxn]; // Stores the powers of p modulo m1

struct shash {
    int n;
    string s;
    vector<long long> hsh;
    void init(string S) {
        s = move(S);
        n = int(s.size());
        hsh.resize(n + 1);
        calc_hashes();
    }

    void calc_hashes() {
        hsh[0] = 1;
        for (int i = 0; i < n; ++i) {
            hsh[i + 1] = ((hsh[i] * p) % m1 + s[i]) % m1;
        }
    }

    long long get_hash(int a, int b) { // [a, b]
        return (hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % m1 + m1) % m1;
    }
};

void calc_pow() {
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        pw[i] = (pw[i - 1] * p) % m1;
    }
}

long long dp[maxn];

int main() {
    setIO("1");
    calc_pow();

    string tmp;
    cin >> tmp;
    shash s;
    s.init(tmp);
    int n;
    cin >> n;
    vector<shash> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        a[i].init(tmp);
        if (s.get_hash(0, a[i].n - 1) == a[i].get_hash(0, a[i].n - 1)) {
            ++dp[a[i].n - 1];
        }
    }
    for (int i = 0; i < s.n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + 1 + a[j].n - 1 >= s.n) {
                continue;
            }
            if (s.get_hash(i + 1, i + 1 + a[j].n - 1) == a[j].get_hash(0, a[j].n - 1)) {
                dp[i + 1 + a[j].n - 1] += dp[i];
                dp[i + 1 + a[j].n - 1] %= mod;
            }
        }
    }
    cout << dp[s.n - 1] << "\n";
    return 0;
}
