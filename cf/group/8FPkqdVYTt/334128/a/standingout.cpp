/* Author: izhang05
 * Time: 08-21-2021 14:00:04
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
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
        p.resize(n), c.resize(n), lcp.resize(n - 1);
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

vector<int> start;

int ind(int x) {
    return upper_bound(start.begin(), start.end(), x) - start.begin() - 1;
}
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

int main() {
    setIO("standingout");
    int n;
    cin >> n;
    vector<string> a(n);
    vector<int> len(n);
    vector<long long> sol(n);
    start.resize(n);
    string s;
    cin >> a[0];
    s = a[0];
    len[0] = int(a[0].size());
    sol[0] = ((long long) len[0] * (len[0] + 1)) / 2;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        s.append("\2");
        s += a[i];
        len[i] = int(a[i].size());
        start[i] = start[i - 1] + len[i - 1] + 1;
        sol[i] = ((long long) len[i] * (len[i] + 1)) / 2;
#ifdef DEBUG
        cout << a[i] << " " << len[i] << " " << start[i] << " " << sol[i] << "\n";
#endif
    }
    suf_ar suf{s};
    suf.build();
#ifdef DEBUG
    print(suf.p, "\t");
    print(suf.lcp, "\t");
#endif
    vector<int> sub(suf.n);
    for (int i = n; i < int(suf.lcp.size()); ++i) {
        int cur = ind(suf.p[i]);
        sub[i] = max(sub[i], min(start[cur] + len[cur] - suf.p[i], suf.lcp[i]));
        if (cur != ind(suf.p[i + 1])) {
            sub[i + 1] = max(sub[i + 1], min(start[cur] + len[cur] - suf.p[i], suf.lcp[i]));
        }
    }
    for (int i = n; i < suf.n; ++i) {
        sol[ind(suf.p[i])] -= sub[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}
