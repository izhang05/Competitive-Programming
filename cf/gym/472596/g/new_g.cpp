/* Author: izhang
 * Time: 02-11-2024 18:15:09
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
    struct UF {
        vi e;
        UF(int n) : e(n, -1) {}
        bool sameSet(int a, int b) { return find(a) == find(b); }
        int size(int x) { return -e[find(x)]; }
        int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
        bool join(int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return false;
            if (e[a] > e[b]) swap(a, b);
            e[a] += e[b];
            e[b] = a;
            return true;
        }
    };

} // namespace kactl
using namespace kactl;

void test_case() {
    int n;
    long long k;
    cin >> n >> k;
    int rem = n - 1;
    UF dsu(n + 1);
    vector<pair<int, int>> sol;
    for (int i = n / 2; i >= 1 && k > 0; --i) {
        for (int j = i + i; j <= n; j += i) {
            if (i + rem - 1 > k) {
                int c = k - (rem - 1);
                sol.emplace_back(c, 2 * c);
                dsu.join(c, 2 * c);
                for (int l = 2; l <= n; ++l) {
                    if (!dsu.sameSet(1, l)) {
                        sol.emplace_back(1, l);
                        dsu.join(1, l);
                    }
                }
                k = 0;
                break;
            }
            if (!dsu.sameSet(i, j)) {
                dsu.join(i, j);
                sol.emplace_back(i, j);
                k -= i;
                --rem;
            }
        }
    }
    if ((int) sol.size() == n - 1 && k == 0) {
        for (auto &i : sol) {
            cout << i.first << " " << i.second << "\n";
        }
    } else {
        cout << -1 << "\n";
    }
    cout << "\n";
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
