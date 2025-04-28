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


int main() {
    setIO("1");
    int n;
    long long m, k;
    cin >> n >> m >> k;
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    long long sol = 0;
    set<pair<long long, long long>> cur;
    cur.insert({-k, m});
    for (auto &i : a) {
        auto it = cur.lower_bound({i.first - k, 1e18});
        long long used = 0;
        while (used != i.second) {
            if (it == cur.begin()) {
                break;
            }
            it = prev(it);
            if (i.second - used >= it->second) {
                used += it->second;
                it = cur.erase(it);
            } else {
                cur.insert({it->first, it->second - (i.second - used)});
                it = cur.erase(it);
                used = i.second;
            }
        }
        sol += used;
        if (used) {
            cur.insert({i.first, used});
        }
    }
    cout << sol << "\n";
    return 0;
}
