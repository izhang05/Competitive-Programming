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

int main() {
    setIO("30");
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, int> cur;
    long long sol = 0;
    int l = 0, r = 0, last = 0;
    while (r < n) {
        while (r < n && (int) cur.size() < k) {
            ++cur[a[r++]];
        }
        while (r < n && cur.find(a[r]) != cur.end()) {
            ++cur[a[r++]];
        }
        if (last > l) {
            sol += (long long) (r - last) * (r - last + 1) / 2;
            sol += (long long) (last - l) * (r - last);
        } else {
            sol += (long long) (r - l) * (r - l + 1) / 2;
        }
        last = r;
        while ((int) cur.size() >= k) {
            if (--cur[a[l]] == 0) {
                cur.erase(a[l]);
            }
            ++l;
        }
    }
    cout << sol << "\n";
    return 0;
}
