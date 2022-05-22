/* Author: izhang
 * Time: 05-21-2022 14:00:05
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
        void update(int pos, ll dif) { // a[pos] += dif
            for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
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

    /**
     * Author: Simon Lindholm
     * Date: 2017-05-11
     * License: CC0
     * Source: folklore
     * Description: Computes sums a[i,j] for all i<I, j<J, and increases single elements a[i,j].
     *  Requires that the elements to be updated are known in advance (call fakeUpdate() before init()).
     * Time: $O(\log^2 N)$. (Use persistent segment trees for $O(\log N)$.)
     * Status: stress-tested
     */

    struct FT2 {
        vector<vi> ys;
        vector<FT> ft;
        FT2(int limx) : ys(limx) {}
        void fakeUpdate(int x, int y) {
            for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
        }
        void init() {
            for (vi &v : ys) sort(all(v)), ft.emplace_back(sz(v));
        }
        int ind(int x, int y) {
            return (int) (lower_bound(all(ys[x]), y) - ys[x].begin());
        }
        void update(int x, int y, ll dif) {
            for (; x < sz(ys); x |= x + 1)
                ft[x].update(ind(x, y), dif);
        }
        ll query(int x, int y) {
            ll sum = 0;
            for (; x; x &= x - 1)
                sum += ft[x - 1].query(ind(x - 1, y));
            return sum;
        }
    };

} // namespace kactl
//using namespace kactl;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    kactl::FT2 fen(maxn + 1);
    for (int i = 0; i < n; ++i) {
        fen.fakeUpdate(i, i + b[i]);
    }
    fen.init();
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        sol += fen.query(maxn, maxn);
        sol -= fen.query(maxn, i);
        if (i - a[i] >= 0) {
            sol -= fen.query(i - a[i], maxn);
            sol += fen.query(i - a[i], i);
        }
        fen.update(i, i + b[i], 1);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
