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

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

int n;
const int maxn = 2e5 + 5;
vector<pair<long long, int>> a;
vector<long long> pre;

bool pos(int x) {
#ifdef DEBUG
    cout << x << ":\n";
#endif
    long long cur = pre[x];
    while (x + 1 < n) {
#ifdef DEBUG
        cout << x << " " << cur << "\n";
#endif
        auto it = lower_bound(a.begin(), a.end(), make_pair(cur, inf));
        --it;
        int ind = (int) (it - a.begin());
        if (ind == x) {
            return false;
        }
        assert(ind > x);
        x = ind;
        cur = pre[x];
    }
    return true;
}

signed main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        pre.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i + 1;
        }
        sort(a.begin(), a.end());
        pre[0] = 0;
        for (int i = 0; i < n; ++i) {
            pre[i] = pre[max(0, i - 1)] + a[i].first;
        }
        vector<int> sol;
        int lo = 0, hi = n - 1, mid, res = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (pos(mid)) {
                hi = mid - 1;
                res = mid;
            } else {
                lo = mid + 1;
            }
        }
        assert(res != -1);
        for (int i = res; i < n; ++i) {
            sol.push_back(a[i].second);
        }
        sort(sol.begin(), sol.end());
        cout << sol.size() << "\n";
        print(sol);
    }
    return 0;
}
