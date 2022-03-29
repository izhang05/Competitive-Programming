#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
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
const int inf = 0x3f3f3f3f;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

long long solve(vector<int> a) {
    int n = int(a.size()), pre = a[0];
    if (n == 1) {
        return a[0];
    }
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] >= pre) {
            pre = a[i] + 1;
        } else {
            if (a[i + 1] < pre) {
                a[i + 1] = max(a[i + 1], a[i]) + 1;
            } else {
                pre = max(pre, a[i]) + 1;
            }
        }
    }
    return max(a[n - 1], pre) + 1;
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long sol = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            vector<int> cur;
            for (int i = l; i <= r; ++i) {
                cur.push_back(a[i]);
            }
            sol += solve(cur);
            dbg() << l << " " << r + 1 << " " << solve(cur);
        }
    }
    cout << sol << "\n";
    return 0;
}
