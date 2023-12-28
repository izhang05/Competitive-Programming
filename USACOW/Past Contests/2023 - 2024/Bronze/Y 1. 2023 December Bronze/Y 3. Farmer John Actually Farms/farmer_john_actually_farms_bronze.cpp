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

struct plant {
    long long h, a, t;
    bool operator<(const plant &rhs) const {
        return t < rhs.t;
    }
};
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<plant> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].h;
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i].a;
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i].t;
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    pair<long long, long long> sol = {0, INFL};
    for (int i = 1; i < n; ++i) {
        if (p[i].a == p[i - 1].a) {
            if (p[i].h <= p[i - 1].h) {
                cout << -1 << "\n";
                return;
            }
        } else if (p[i].a > p[i - 1].a) {
            if (p[i - 1].h - p[i].h < 0) {
                sol.first = max(sol.first, (p[i - 1].h - p[i].h) / (p[i].a - p[i - 1].a));
            } else {
                sol.first = max(sol.first, (p[i - 1].h - p[i].h) / (p[i].a - p[i - 1].a) + 1);
            }
        } else {
            if (p[i].h - p[i - 1].h <= 0) {
                cout << -1 << "\n";
                return;
            }
            sol.second = min(sol.second, (p[i].h - p[i - 1].h - 1) / (p[i - 1].a - p[i].a));
        }
    }
    if (sol.first <= sol.second) {
        cout << sol.first << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
