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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
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
    setIO("b");
    string t;
    cin >> t >> s;
    n = int(s.size());
    calc_pow();
    calc_hashes();
    int zero = 0, one = 0;
    for (auto &i : t) {
        if (i == '0') {
            ++zero;
        } else {
            ++one;
        }
    }
    if (zero < one) {
        swap(zero, one);
        for (auto &i : t) {
            if (i == '1') {
                i = '0';
            } else {
                i = '1';
            }
        }
    }
    int sol = 0;
    for (int i = 1; i * zero < n; ++i) {
        if ((n - i * zero) % one == 0) {
            long long hash0 = -1, hash1 = -1;
            int s1 = (n - i * zero) / one;
            bool pos = true;
            int ind = 0;
            for (auto &j : t) {
                if (j == '0') {
                    if (hash0 == -1) {
                        hash0 = get_hash(ind, ind + i - 1);
                    } else if (get_hash(ind, ind + i - 1) != hash0) {
                        pos = false;
                        break;
                    }
                    ind += i;
                } else {
                    if (hash1 == -1) {
                        hash1 = get_hash(ind, ind + s1 - 1);
                    } else if (get_hash(ind, ind + s1 - 1) != hash1) {
                        pos = false;
                        break;
                    }
                    ind += s1;
                }
            }
            if (pos && hash0 != hash1) {
                ++sol;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
