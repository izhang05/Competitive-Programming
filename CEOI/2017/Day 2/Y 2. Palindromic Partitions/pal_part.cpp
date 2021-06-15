#include <bits/stdc++.h>

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

const int maxn = 1e6 + 5;
const long long m1 = 1e9 + 9, p = 9973;

long long pw[maxn]; // Stores the powers of p modulo m1
int n;
string s;
long long hsh[maxn];

void calc_hashes() {
    hsh[0] = 1;
    for (int i = 0; i < n; ++i) {
        hsh[i + 1] = ((hsh[i] * p) % m1 + s[i]) % m1;
    }
}

long long get_hash(int a, int b) { // [a, b]
    return (hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % m1 + m1) % m1;
}

void calc_pow() {
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        pw[i] = (pw[i - 1] * p) % m1;
    }
}

int main() {
    setIO("1");

    int t;
    cin >> t;
    calc_pow();
    while (t--) {
        cin >> s;
        n = int(s.size());
        calc_hashes();
        int sol = 1;
        for (int i = 0; i < n / 2; ++i) {
            int j = i, l = n - i - 1, r = n - i - 1;
            for (; j < n / 2; ++j, --l) {
                if (get_hash(i, j) == get_hash(l, r)) {
                    sol += 2;
                    if (n % 2 == 0 && j == n / 2 - 1) {
                        --sol;
                    }
                    break;
                }
            }
            i = j;
        }
        cout << sol << "\n";
    }
    return 0;
}
