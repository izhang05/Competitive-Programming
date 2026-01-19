/* Author: izhang
 * Time: 10-11-2025 15:34:41
**/
#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
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

const long long INFL = 0x3f3f3f3f3f3f3f3f;

#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef double T; // long double, Rational, double + mod<P>...
typedef vector<T> vd;
typedef vector<vd> vvd;

const double inf = 1 / .0;
// Two-phase simplex algorithm for solving linear programs of the form
//
//     maximize     c^T x
//     subject to   Ax <= b
//                  x >= 0
// OUTPUT: value of the optimal solution (inf if unbounded
//         above, -inf if infeasible)
//
// To use this code, create an LPSolver object with A, b, and c as
// arguments.  Then, call Solve(x).

// 2018-05: added steepest edge pricing, speed up factor of ~5

template<typename DOUBLE>
struct Simplex_Steep {
    using VD = vector<DOUBLE>;
    using VVD = vector<VD>;
    using VI = vector<int>;
    const DOUBLE EPS = 1e-12;
    int m, n;
    VI B, N;
    VVD D;

    int iteration_cnt = 0;

    Simplex_Steep(const VVD &A, const VD &b, const VD &c) :
            m(b.size()), n(c.size()), B(m), N(n + 1), D(m + 2, VD(n + 2)) {
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) D[i][j] = A[i][j];
        for (int i = 0; i < m; i++) {
            B[i] = n + i;
            D[i][n] = -1;
            D[i][n + 1] = b[i];
        }
        for (int j = 0; j < n; j++) {
            N[j] = j;
            D[m][j] = -c[j];
        }
        N[n] = -1;
        D[m + 1][n] = 1;
    }

    void Pivot(int r, int s) {
        for (int i = 0; i < m + 2; i++)
            if (i != r)
                for (int j = 0; j < n + 2; j++)
                    if (j != s)
                        D[i][j] -= D[r][j] * D[i][s] / D[r][s];
        for (int j = 0; j < n + 2; j++) if (j != s) D[r][j] /= D[r][s];
        for (int i = 0; i < m + 2; i++) if (i != r) D[i][s] /= -D[r][s];
        D[r][s] = 1.0 / D[r][s];
        swap(B[r], N[s]);
    }

    bool Simplex(int phase) {
        int x = phase == 1 ? m + 1 : m;
        while (true) {
            ++iteration_cnt;
            int s = -1;
            DOUBLE c_val = -1;
            for (int j = 0; j <= n; j++) {
                if (phase == 2 && N[j] == -1) continue;
                DOUBLE norm_sq = 0;
                for (int k = 0; k <= m; ++k) { norm_sq += D[k][j] * D[k][j]; }
                if (norm_sq < EPS) norm_sq = EPS; // stop division by 0
                DOUBLE c_val_j = D[x][j] / sqrtl(norm_sq);
                if (s == -1 || c_val_j < c_val || (c_val == c_val_j && N[j] < N[s])) {
                    s = j;
                    c_val = c_val_j;
                }
            }
            if (D[x][s] >= -EPS) return true;
            int r = -1;
            for (int i = 0; i < m; i++) {
                if (D[i][s] <= EPS) continue;
                if (r == -1 || D[i][n + 1] / D[i][s] < D[r][n + 1] / D[r][s] ||
                    (D[i][n + 1] / D[i][s] == D[r][n + 1] / D[r][s] && B[i] < B[r]))
                    r = i;
            }
            if (r == -1) return false;
            Pivot(r, s);
        }
    }

    DOUBLE solve(VD &x) {
        int r = 0;
        for (int i = 1; i < m; i++) if (D[i][n + 1] < D[r][n + 1]) r = i;
        if (D[r][n + 1] <= -EPS) {
            Pivot(r, n);
            if (!Simplex(1) || D[m + 1][n + 1] < -EPS) return -inf;
            for (int i = 0; i < m; i++)
                if (B[i] == -1) {
                    int s = -1;
                    for (int j = 0; j <= n; j++)
                        if (s == -1 || D[i][j] < D[i][s] || (D[i][j] == D[i][s] && N[j] < N[s])) s = j;
                    Pivot(i, s);
                }
        }
        if (!Simplex(2)) return inf;
        x = VD(n);
        for (int i = 0; i < m; i++) if (B[i] < n) x[B[i]] = D[i][n + 1];
        //cerr << "Steepest edge iterations: " << iteration_cnt << "\n";
        return D[m][n + 1];
    }
};
//     * Description: Solves a general linear maximization problem: maximize $c^T x$ subject to $Ax \le b$, $x \ge 0$.
//     * Returns -inf if there is no solution, inf if there are arbitrarily good solutions, or the maximum value of $c^T x$ otherwise.
//     * The input vector is set to an optimal  (or in the unbounded case, an arbitrary solution fulfilling the constraints).
//     * Numerical stability is not guaranteed. For better performance, define variables such that $x = 0$ is viable.
//     * Usage:
//     * vvd A = {{1,-1}, {-1,1}, {-1,-2}};
//     * vd b = {1,1,-4}, c = {-1,-1}, x;
//     * T val = LPSolver(A, b, c).solve(x);

const int mxn = 1005;
int sol[mxn][mxn];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) { // [l, r]
    return uniform_int_distribution<long long>(l, r)(rng);
}

const int tot_val = 10000;

void test_case() {
    int n, m;
    cin >> n >> m;
    vvd A(2 * n, vd(m));
    vd b(2 * n, 1), c(m), x;
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i;
    }
    vector<int> rev_perm(n);
    shuffle(perm.begin(), perm.end(), rng);
    for (int i = 0; i < n; ++i) {
        rev_perm[perm[i]] = i;
    }
    for (int i = n; i < 2 * n; ++i) {
        b[i] = -1;
    }
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; ++i) {
        cin >> e[i].first >> e[i].second;
        --e[i].first, --e[i].second;
        e[i].first = perm[e[i].first];
        e[i].second = perm[e[i].second];
        A[e[i].first][i] = A[e[i].second][i] = 1;
        A[e[i].first + n][i] = A[e[i].second + n][i] = -1;
    }
    long double val = Simplex_Steep(A, b, c).solve(x);
    if (val == -inf) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < m; ++i) {
            int f = rev_perm[e[i].first], g = rev_perm[e[i].second];
            sol[f][g] = sol[g][f] = round(tot_val * x[i]);
//            assert(sol[f][g] == 0 || sol[f][g] == 5000 || sol[f][g] == 10000);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << sol[i][j] << " \n"[j == n - 1];
            }
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
