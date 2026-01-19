/* Author: izhang
 * Time: 10-11-2025 13:55:11
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG

#include <debug.h>

#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct mn {
    pair<int, int> f{inf, inf}, s{inf, inf};

    void add(pair<int, int> x) {
        if (x < f) {
            swap(f, s);
            f = x;
        } else if (x < s) {
            s = x;
        }
    }
};

const int mxn = 505;
mn sol[mxn][mxn];


void test_case() {
    int r, c, n;
    cin >> r >> c >> n;
    vector<pair<int, int>> a(n);
    map<int, vector<pair<int, int>>> p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].first, --a[i].second;
        p[a[i].first].emplace_back(a[i].second, i + 1);
    }
    sort(a.begin(), a.end());
    vector<mn> vals(c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            ++vals[j].f.first;
            ++vals[j].s.first;
        }
        for (auto &j: p[i]) {
            for (int k = 0; k < c; ++k) {
                vals[k].add({abs(j.first - k), j.second});
            }
        }
        for (int j = 0; j < c; ++j) {
            sol[i][j] = vals[j];
        }
    }
    for (int i = 0; i < c; ++i) {
        vals[i] = mn{};
    }
    for (int i = r - 1; i >= 0; --i) {
        for (int j = 0; j < c; ++j) {
            ++vals[j].f.first;
            ++vals[j].s.first;
        }
        for (int j = 0; j < c; ++j) {
            sol[i][j].add(vals[j].f);
            sol[i][j].add(vals[j].s);
        }
        for (auto &j: p[i]) {
            for (int k = 0; k < c; ++k) {
                vals[k].add({abs(j.first - k), j.second});
            }
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << sol[i][j].f.second << " \n"[j == c - 1];
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << sol[i][j].s.second << " \n"[j == c - 1];
        }
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
