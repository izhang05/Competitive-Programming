/* Author: izhang05
 * Time: 10-03-2021 10:35:04
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxs = 20, maxn = 1e6 + 10;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<int> occ[2][1 << 21];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = 0;
    for (int i = 0; i < maxs; ++i) {
        vector<int> pre(n), cnt(n);
        int mult = 0;
        for (int j = i + 1; j < maxs; ++j) {
            mult |= (1 << j);
        }
        //        vector<map<int, set<int>>> occ(2);
        for (int j = 0; j < n; ++j) {
            pre[j] = a[j] & mult;
            cnt[j] = bool(a[j] & (1 << i));
            if (j) {
                pre[j] ^= pre[j - 1];
                cnt[j] += cnt[j - 1];
            }
            occ[j % 2][pre[j]].push_back(j);
        }
        for (int l = 0; l < n; ++l) {
            if (a[l] & (1 << i)) {
                int lo = l, hi = n - 1, mid, res = -1;
                while (lo <= hi) {
                    mid = (lo + hi) / 2;
                    if (cnt[mid] - cnt[l] != mid - l) {
                        hi = mid - 1;
                    } else {
                        res = mid;
                        lo = mid + 1;
                    }
                }
                assert(res != -1);
                int cur_xor = 0;
                if (l) {
                    cur_xor = pre[l - 1];
                }
                auto it = upper_bound(occ[(l % 2) ^ 1][cur_xor].begin(), occ[(l % 2) ^ 1][cur_xor].end(), res);
                if (it != occ[(l % 2) ^ 1][cur_xor].begin()) {
                    sol = max(sol, *prev(it) - l + 1);
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            occ[j % 2][pre[j]].clear();
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
