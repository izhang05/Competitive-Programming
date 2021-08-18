/* Author: izhang05
 * Time: 08-18-2021 17:54:06
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

template<class T>
struct rmq {
    vector<vector<T>> jmp;
    explicit rmq(const vector<T> &V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= int(V.size()); pw *= 2, ++k) {
            jmp.emplace_back(int(V.size()) - pw * 2 + 1);
            for (int j = 0; j < int(jmp[k].size()); ++j) {
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
            }
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct suf_ar {
    string s;
    int n{};
    vector<int> p{}, c{}, lcp{};
    rmq<int> r{vector<int>()};

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
        s += '\1';
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
        gen_lcp();
    }
    void gen_lcp() {
        int k = 0;
        for (int i = 0; i < n - 1; ++i) {
            int pi = c[i], j = p[pi - 1];
            while (s[i + k] == s[j + k]) {
                ++k;
            }
            lcp[pi - 1] = k;
            k = max(0, k - 1);
        }
        r = rmq(lcp);
    }
    int get_lcp(int a, int b) {
        return r.query(min(c[a], c[b]), max(c[a], c[b]));
    }
};
const int maxn = 1e5 + 5, maxx = 35;

int dp[maxn][maxx];

void solve() {
    int n, m, x;
    string s, t;
    cin >> n >> s >> m >> t >> x;
    suf_ar suf{s + '\2' + t};
    suf.build();
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= x; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            int l = suf.get_lcp(i, dp[i][j] + 1 + int(s.size()) + 1);
            dp[i + l][j + 1] = max(dp[i + l][j + 1], dp[i][j] + l);
        }
    }
    for (int i = 0; i <= x; ++i) {
        if (dp[n][i] == m - 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
