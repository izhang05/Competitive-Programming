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

struct air {
    int a, b, p, m;
};


int main() {
    setIO("1");
    int n, m;
    cin >> n >> m;
    vector<int> c(100);
    for (int i = 0; i < n; ++i) {
        int s, t, cnt;
        cin >> s >> t >> cnt;
        for (int j = s - 1; j < t; ++j) {
            c[j] = cnt;
        }
    }

    vector<air> a(m);
    for (auto &i : a) {
        cin >> i.a >> i.b >> i.p >> i.m;
        --i.a;
    }
    int sol = 1e9;
    for (int i = 0; i < (1 << m); ++i) {
        vector<int> cur(100);
        int cost = 0;
        for (int j = 0; j < m; ++j) {
            if (i & (1 << j)) {
                cost += a[j].m;
                for (int k = a[j].a; k < a[j].b; ++k) {
                    cur[k] += a[j].p;
                }
            }
        }
        bool good = true;
        for (int j = 0; j < 100; ++j) {
            if (cur[j] < c[j]) {
                good = false;
            }
        }
        if (good) {
            sol = min(sol, cost);
        }
    }
    cout << sol << "\n";
    return 0;
}
