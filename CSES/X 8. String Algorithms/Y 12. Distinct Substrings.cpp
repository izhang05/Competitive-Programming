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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct suf_ar {
    string s;
    int n{};
    vector<int> p{}, c{}, lcp{};

    void count_sort() {
        vector<int> cnt(n);
        for (auto &i : c) {
            ++cnt[i];
        }
        vector<int> new_p(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; ++i) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto &i : p) {
            new_p[pos[c[i]]++] = i;
        }
        swap(p, new_p);
    }

    void build() {
        s += '$';
        n = (int) s.size();
        p.resize(n), c.resize(n), lcp.resize(n);
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = {s[i], i};
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        for (int k = 0; (1 << k) < n; ++k) {
            for (int i = 0; i < n; ++i) {
                p[i] = (p[i] - (1 << k) + n) % n;
            }
            count_sort();
            vector<int> c_new(n);
            c_new[p[0]] = 0;
            for (int i = 1; i < n; ++i) {
                pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
                pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
                if (prev == cur) {
                    c_new[p[i]] = c_new[p[i - 1]];
                } else {
                    c_new[p[i]] = c_new[p[i - 1]] + 1;
                }
            }
            swap(c, c_new);
        }
        int k = 0;
        for (int i = 0; i < n - 1; ++i) {
            int pi = c[i], j = p[pi - 1];
            while (s[i + k] == s[j + k]) {
                ++k;
            }
            lcp[pi] = k;
            k = max(0, k - 1);
        }
    }
};

int main() {
    setIO("12");
    string s;
    cin >> s;
    suf_ar suf{s};
    suf.build();
    long long sum = 0;
    for (int i = 0; i < suf.n; ++i) {
        sum += suf.lcp[i];
    }
    cout << ((long long) suf.n * (suf.n - 1)) / 2 - sum << "\n";
    return 0;
}