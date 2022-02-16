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
        FT(int n) : s(n) {}
        void update(int pos, ll dif) {// a[pos] += dif
            for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
        }
        ll query(int pos) {// sum of values in [0, pos)
            ll res = 0;
            for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
            return res;
        }
        int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
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

}// namespace kactl
using namespace kactl;

void solve() {
    int n;
    cin >> n;
    FT f{(int) 1e5 + 5};
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        f.update(0, 1);
        f.update(a + 1, -1);
        int lo = 0, hi = n, mid, res;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (f.query(mid + 1) >= mid) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << res << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
