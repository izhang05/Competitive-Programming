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
/**
 * Author: Stanford
 * Source: Stanford Notebook
 * License: MIT
 * Description: Solves a general linear maximization problem: maximize $c^T x$ subject to $Ax \le b$, $x \ge 0$.
 * Returns -inf if there is no solution, inf if there are arbitrarily good solutions, or the maximum value of $c^T x$ otherwise.
 * The input vector is set to an optimal  (or in the unbounded case, an arbitrary solution fulfilling the constraints).
 * Numerical stability is not guaranteed. For better performance, define variables such that $x = 0$ is viable.
 * Usage:
 * vvd A = {{1,-1}, {-1,1}, {-1,-2}};
 * vd b = {1,1,-4}, c = {-1,-1}, x;
 * T val = LPSolver(A, b, c).solve(x);
 * Time: O(NM * \#pivots), where a pivot may be e.g. an edge relaxation. O(2^n) in the general case.
 * Status: seems to work?
 */

typedef float T; // long double, Rational, double + mod<P>...
typedef vector<T> vd;
typedef vector<vd> vvd;

const T eps = .02, inf = 1 / .0;
#define MP make_pair
#define ltj(X) if(s == -1 || MP(X[j],N[j]) < MP(X[s],N[s])) s=j

struct LPSolver {
    int m, n;
    vi N, B;
    vvd D;

    LPSolver(const vvd &A, const vd &b, const vd &c) :
            m(sz(b)), n(sz(c)), N(n + 1), B(m), D(m + 2, vd(n + 2)) {
        rep(i, 0, m) rep(j, 0, n) D[i][j] = A[i][j];
        rep(i, 0, m) {
            B[i] = n + i;
            D[i][n] = -1;
            D[i][n + 1] = b[i];
        }
        rep(j, 0, n) {
            N[j] = j;
            D[m][j] = -c[j];
        }
        N[n] = -1;
        D[m + 1][n] = 1;
    }

    void pivot(int r, int s) {
        T *a = D[r].data(), inv = 1 / a[s];
        rep(i, 0, m + 2) if (i != r && abs(D[i][s]) > eps) {
                T *b = D[i].data(), inv2 = b[s] * inv;
                rep(j, 0, n + 2) b[j] -= a[j] * inv2;
                b[s] = a[s] * inv2;
            }
        rep(j, 0, n + 2) if (j != s) D[r][j] *= inv;
        rep(i, 0, m + 2) if (i != r) D[i][s] *= -inv;
        D[r][s] = inv;
        swap(B[r], N[s]);
    }

    bool simplex(int phase) {
        int x = m + phase - 1;
        for (;;) {
            int s = -1;
            rep(j, 0, n + 1) if (N[j] != -phase) ltj(D[x]);
            if (D[x][s] >= -eps) return true;
            int r = -1;
            rep(i, 0, m) {
                if (D[i][s] <= eps) continue;
                if (r == -1 || MP(D[i][n + 1] / D[i][s], B[i])
                               < MP(D[r][n + 1] / D[r][s], B[r]))
                    r = i;
            }
            if (r == -1) return false;
            pivot(r, s);
        }
    }

    T solve(vd &x) {
        int r = 0;
        rep(i, 1, m) if (D[i][n + 1] < D[r][n + 1]) r = i;
        if (D[r][n + 1] < -eps) {
            pivot(r, n);
            if (!simplex(2) || D[m + 1][n + 1] < -eps) return -inf;
            rep(i, 0, m) if (B[i] == -1) {
                    int s = 0;
                    rep(j, 1, n + 1) ltj(D[i]);
                    pivot(i, s);
                }
        }
        bool ok = simplex(1);
        x = vd(n);
        rep(i, 0, m) if (B[i] < n) x[B[i]] = D[i][n + 1];
        return ok ? D[m][n + 1] : inf;
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
//    vector<int> perm(n);
//    for (int i = 0; i < n; ++i) {
//        perm[i] = i;
//    }
//    vector<int> rev_perm(n);
//    shuffle(perm.begin(), perm.end(), rng);
//    for (int i = 0; i < n; ++i) {
//        rev_perm[perm[i]] = i;
//    }
    for (int i = n; i < 2 * n; ++i) {
        b[i] = -1;
    }
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; ++i) {
        cin >> e[i].first >> e[i].second;
        --e[i].first, --e[i].second;
//        e[i].first = perm[e[i].first];
//        e[i].second = perm[e[i].second];
        A[e[i].first][i] = A[e[i].second][i] = 1;
        A[e[i].first + n][i] = A[e[i].second + n][i] = -1;
    }
    long double val = LPSolver(A, b, c).solve(x);
    if (val == -inf) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < m; ++i) {
            int f = e[i].first, g = e[i].second;
//            int f = rev_perm[e[i].first], g = rev_perm[e[i].second];
            sol[f][g] = sol[g][f] = round(tot_val * x[i]);
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
