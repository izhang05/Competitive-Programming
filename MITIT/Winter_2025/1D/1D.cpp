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
     * Author: Emil Lenngren, Simon Lindholm
     * Date: 2011-11-29
     * License: CC0
     * Source: folklore
     * Description: Calculates a valid assignment to boolean variables a, b, c,... to a 2-SAT problem, so that an expression of the type $(a\|\|b)\&\&(!a\|\|c)\&\&(d\|\|!b)\&\&...$ becomes true, or reports that it is unsatisfiable.
     * Negated variables are represented by bit-inversions (\texttt{\tilde{}x}).
     * Usage:
     *  TwoSat ts(number of boolean variables);
     *  ts.either(0, \tilde3); // Var 0 is true or var 3 is false
     *  ts.setValue(2); // Var 2 is true
     *  ts.atMostOne({0,\tilde1,2}); // <= 1 of vars 0, \tilde1 and 2 are true
     *  ts.solve(); // Returns true iff it is solvable
     *  ts.values[0..N-1] holds the assigned values to the vars
     * Time: O(N+E), where N is the number of boolean variables, and E is the number of clauses.
     * Status: stress-tested
     */

    struct TwoSat {
        int N;
        vector<vi> gr;
        vi values; // 0 = false, 1 = true

        TwoSat(int n = 0) : N(n), gr(2 * n) {}

        int addVar() { // (optional)
            gr.emplace_back();
            gr.emplace_back();
            return N++;
        }

        void either(int f, int j) {
            f = max(2 * f, -1 - 2 * f);
            j = max(2 * j, -1 - 2 * j);
            gr[f].push_back(j ^ 1);
            gr[j].push_back(f ^ 1);
        }

        void setValue(int x) { either(x, x); }

        void atMostOne(const vi &li) { // (optional)
            if (sz(li) <= 1) return;
            int cur = ~li[0];
            rep(i, 2, sz(li)) {
                int next = addVar();
                either(cur, ~li[i]);
                either(cur, next);
                either(~li[i], next);
                cur = ~next;
            }
            either(cur, ~li[1]);
        }

        vi val, comp, z;
        int time = 0;

        int dfs(int i) {
            int low = val[i] = ++time, x;
            z.push_back(i);
            for (int e: gr[i])
                if (!comp[e])
                    low = min(low, val[e] ?: dfs(e));
            if (low == val[i])
                do {
                    x = z.back();
                    z.pop_back();
                    comp[x] = low;
                    if (values[x >> 1] == -1)
                        values[x >> 1] = x & 1;
                } while (x != i);
            return val[i] = low;
        }

        bool solve() {
            values.assign(N, -1);
            val.assign(2 * N, 0);
            comp = val;
            rep(i, 0, 2 * N) if (!comp[i]) dfs(i);
            rep(i, 0, N) if (comp[2 * i] == comp[2 * i + 1]) return 0;
            return 1;
        }
    };

}
//using namespace kactl;

struct p {
    int x, y;
    string s;
};

void test_case() {
    int n;
    cin >> n;
    vector<p> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].s;
    }
    kactl::TwoSat ts(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && a[i].s != a[j].s) {
                int c = i, d = j;
                if (a[c].s == "LR") {
                    swap(c, d);
                }
                // c is UD, d is LR
                if (a[c].x < a[d].x) {
                    if (a[c].y < a[d].y) {
                        ts.either(~c, ~d);
                    } else {
                        ts.either(c, ~d);
                    }
                } else {
                    if (a[c].y < a[d].y) {
                        ts.either(~c, d);
                    } else {
                        ts.either(c, d);
                    }
                }
            }
        }
    }
    cout << (ts.solve() ? "YES" : "NO") << "\n";
    cout << 0 << "\n";
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
