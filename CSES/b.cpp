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
const long long p = 9973, m1 = 1e9 + 9, m2 = 1e9 + 7;

int freq_s[26], freq_cur[26];

int main() {
    setIO("b");

    string s, t;
    cin >> s >> t;
    int n = (int) s.size(), m = (int) t.size();
    if (m < n) {
        cout << 0 << "\n";
        return 0;
    }
    long long poly1 = 0, poly2 = 0, p_pow1 = 1, p_pow2 = 1;
    set<pair<long long, long long>> sol;
    for (int i = 0; i < n; ++i) {
        ++freq_s[s[i] - 'a'], ++freq_cur[t[i] - 'a'];
        poly1 = (poly1 * p + t[i] - 'a') % m1;
        poly2 = (poly2 * p + t[i] - 'a') % m2;
        p_pow1 = p_pow1 * p % m1;
        p_pow2 = p_pow2 * p % m2;
    }
    bool good = true;
    for (int j = 0; j < 26; ++j) {
        if (freq_s[j] != freq_cur[j]) {
            good = false;
            break;
        }
    }
    if (good) {
        sol.insert({poly1, poly2});
    }

    for (int i = 0; i + n < m; ++i) {
        --freq_cur[t[i] - 'a'], ++freq_cur[t[i + n] - 'a'];
        poly1 = (poly1 * p - p_pow1 * (t[i] - 'a') % m1 + t[i + n] - 'a' + m1) % m1;
        poly2 = (poly2 * p - p_pow2 * (t[i] - 'a') % m2 + t[i + n] - 'a' + m2) % m2;
        good = true;
        for (int j = 0; j < 26; ++j) {
            if (freq_s[j] != freq_cur[j]) {
                good = false;
                break;
            }
        }
        if (good) {
            sol.insert({poly1, poly2});
        }
    }
    cout << sol.size() << "\n";
    return 0;
}
