/* Author: izhang
 * Time: 01-15-2023 21:55:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    /**
     * Author: Johan Sannemo, pajenegod
     * Date: 2015-02-06
     * License: CC0
     * Source: Folklore
     * Description: Range Minimum Queries on an array. Returns
     * min(V[a], V[a + 1], ... V[b - 1]) in constant time.
     * Usage:
     *  RMQ rmq(values);
     *  rmq.query(inclusive, exclusive);
     * Time: $O(|V| \log |V| + Q)$
     * Status: stress-tested
     */

    template<class T>
    struct RMQ {
        vector<vector<T>> jmp;
        RMQ(const vector<T> &V) : jmp(1, V) {
            for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
                jmp.emplace_back(sz(V) - pw * 2 + 1);
                rep(j, 0, sz(jmp[k]))
                        jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
            }
        }
        T query(int a, int b) {
            assert(a < b); // or return inf if a == b
            int dep = 31 - __builtin_clz(b - a);
            return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
        }
    };

} // namespace kactl
//using namespace kactl;

vector<vector<int>> a;
vector<kactl::RMQ<int>> r;

int n, m;
bool pos(int l) {
    for (int i = 0; i + l <= n; ++i) {
        for (int j = 0; j + l <= m; ++j) {
            bool good = true;
            for (int k = i; k < i + l; ++k) {
                if (r[k].query(j, j + l) < l) {
                    good = false;
                    break;
                }
            }
            if (good) {
                return true;
            }
        }
    }
    return false;
}

void test_case() {
    cin >> n >> m;
    a.clear();
    if (n <= m) {
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            a[i].resize(m);
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
    } else {
        swap(n, m);
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            a[i].resize(m);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[j][i];
            }
        }
    }
    r.clear();
    r.reserve(n);
    for (int i = 0; i < n; ++i) {
        r.emplace_back(a[i]);
    }
    int lo = 0, hi = n, mid, res = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (pos(mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << res << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
