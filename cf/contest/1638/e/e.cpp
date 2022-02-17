/* Author: izhang
 * Time: 02-16-2022 21:25:08
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

namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    /**
     * Author: Lukas Polacek
     * Date: 2009-10-30
     * License: CC0
     * Source: folklore/TopCoder
     * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
     * taking the difference between the old and new value.
     * Time: Both operations are $O(\log N)$.
     * Status: Stress-tested
     */

    struct FT {
        vector<ll> s;
        explicit FT(int n) : s(n) {}
        void update(int pos, ll dif) { // a[pos] += dif
            for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
        }
        void update(int l, int r, ll dif) { // a[l, r) += dif
            update(l, dif), update(r, -dif);
        }
        ll query(int pos) { // sum of values in [0, pos)
            ll res = 0;
            for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
            return res;
        }
        int lower_bound(ll sum) { // min pos st sum of [0, pos] >= sum
            // Returns n if no sum is >= sum, or -1 if empty sum is.
            if (sum <= 0) return -1;
            int pos = 0;
            for (int pw = 1 << 25; pw; pw >>= 1) {
                if (pos + pw <= sz(s) && s[pos + pw - 1] < sum)
                    pos += pw, sum -= s[pos - 1];
            }
            return pos;
        }
    };

} // namespace kactl
//using namespace kactl;

void test_case() {
    int n, q;
    cin >> n >> q;
    vector<long long> lazy(n);
    kactl::FT a(n);
    set<pair<int, int>> change;
    change.insert({0, 0});
    change.insert({n, 0});
    while (q--) {
        string s;
        cin >> s;
        if (s == "Color") {
            int l, r, c;
            cin >> l >> r >> c;
            --l, --c;

            auto it = change.lower_bound({l, inf});
            if (it->first > r) {
                if (prev(it)->second != c) {
                    a.update(l, r, lazy[prev(it)->second] - lazy[c]);
                    int color = prev(it)->second;
                    if (prev(it)->first == l) {
                        change.erase(prev(it));
                    }
                    change.insert({l, c});
                    change.insert({r, color});
                }
            } else {
                if (prev(it)->second != c) {
                    a.update(l, it->first, lazy[prev(it)->second] - lazy[c]);
                    if (prev(it)->first == l) {
                        change.erase(prev(it));
                    }
                    change.insert({l, c});
                }
            }
            while (it->first < r) {
                if (next(it)->first <= r) {
                    a.update(it->first, next(it)->first, lazy[it->second] - lazy[c]);
                    it = change.erase(it);
                } else {
                    if (it->second != c) {
                        a.update(it->first, r, lazy[it->second] - lazy[c]);
                        int color = it->second;
                        change.erase(it);
                        change.insert({r, color});
                    } else {
                        change.erase(it);
                    }
                    break;
                }
            }
        } else if (s == "Add") {
            int x, c;
            cin >> c >> x;
            --c;
            lazy[c] += x;
        } else {
            int i;
            cin >> i;
            --i;
            int c = prev(change.lower_bound({i, inf}))->second;
            cout << lazy[c] + a.query(i + 1) << "\n";
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
