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
void calc_pow() {
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        pw[i] = (pw[i - 1] * p) % m1;
    }
}

struct shash {
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

    void init(int a, string b) {
        n = a;
        s = move(b);
        calc_hashes();
    }

    bool operator==(const shash &rhs) const {
        return s == rhs.s;
    }
};

bool substring(shash a, shash b) {
    if (a.n > b.n) {
        swap(a, b);
    }
    for (int k = 0; k + a.n < b.n; ++k) {
        if (a.get_hash(0, a.n - 1) == b.get_hash(k, k + a.n - 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    setIO("c");

    calc_pow();
    vector<shash> s(3);
    vector<int> order(3);
    int total = 0;
    for (int i = 0; i < 3; ++i) {
        order[i] = i;
        string a;
        cin >> a;
        s[i].init(int(a.size()), a);
        total += int(a.size());
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (substring(s[i], s[j])) {
                total -= min(s[i].n, s[j].n);
                if (s[i].n >= s[j].n) {
                    s.erase(find(s.begin(), s.end(), s[j]));
                } else {
                    s.erase(find(s.begin(), s.end(), s[i]));
                }
                if (substring(s[0], s[1])) {
                    cout << max(s[0].n, s[1].n) << "\n";
                    return 0;
                }
                int dist = min(s[0].n, s[1].n);
                int l = s[0].n - dist, r = dist - 1;
                while (l < s[0].n && r >= 0) {
                    if (s[0].get_hash(l, s[0].n - 1) == s[1].get_hash(0, r)) {
                        break;
                    }
                    ++l, --r;
                }
                ++r;
                int sol = total - r;

                dist = min(s[0].n, s[1].n);
                l = s[1].n - dist, r = dist - 1;
                while (r >= 0) {
                    if (s[1].get_hash(l, s[1].n - 1) == s[0].get_hash(0, r)) {
                        break;
                    }
                    ++l, --r;
                }
                ++r;
                cout << min(sol, total - r) << "\n";
                return 0;
            }
        }
    }
    int sol = total;
    do {
        vector<shash> cur(int(order.size()));
        for (int i = 0; i < int(order.size()); ++i) {
            cur[i] = s[order[i]];
        }
        int cur_sol = total;
        int dist = min(cur[0].n, cur[1].n);
        int l = cur[0].n - dist, r = dist - 1;
        while (l < cur[0].n && r >= 0) {
            if (cur[0].get_hash(l, cur[0].n - 1) == cur[1].get_hash(0, r)) {
                break;
            }
            ++l, --r;
        }
        ++r;
        cur_sol -= r;
        dist = min(cur[1].n, cur[2].n);
        l = cur[1].n - dist, r = dist - 1;
        while (l < cur[1].n && r >= 0) {
            if (cur[1].get_hash(l, cur[1].n - 1) == cur[2].get_hash(0, r)) {
                break;
            }
            ++l, --r;
        }
        ++r;
        cur_sol -= r;
        sol = min(sol, cur_sol);
    } while (next_permutation(order.begin(), order.end()));
    cout << sol << "\n";
    return 0;
}
