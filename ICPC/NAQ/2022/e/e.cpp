/* Author: izhang
 * Time: 09-08-2023 02:40:34
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
     * Date: 2009-10-26
     * License: CC0
     * Source: folklore
     * Description: Disjoint-set data structure.
     * Time: $O(\alpha(N))$
     */

    struct UF {
        vi e, dot;

        UF(int n) : e(n, -1), dot(n, 0) {}

        bool sameSet(int a, int b) { return find(a) == find(b); }

        int size(int x) { return -e[find(x)]; }

        int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }

        bool join(int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return false;
            if (e[a] > e[b]) swap(a, b);
            e[a] += e[b];
            e[b] = a;
            dot[a] += dot[b];
            return true;
        }
    };

}
//using namespace kactl;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
char grid[mxn][mxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;

int ind(int x, int y) {
    return m * x + y;
}

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}


void test_case() {
    cin >> n >> m;
    string s;
    getline(cin, s);
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        for (int j = 0; j < m; ++j) {
            grid[i][j] = s[j];
        }
    }
    kactl::UF dsu(n * m);
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            if (grid[i][j] == '.') {
                dsu.dot[ind(i, j)] = 1;
            }
        }
    }
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            if (grid[i][j] == 'X') {
                continue;
            }
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k], ny = j + dy[k];
                if (!(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'X')) {
                    dsu.join(ind(i, j), ind(nx, ny));
                }
            }
        }
    }
    set<int> bad;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            bad.insert(dsu.find(ind(i, j)));
        }
    }
    dbg() << bad;
    set<int> good;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] >= 'A' && grid[i][j] <= 'W') {
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (valid(nx, ny) && !(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'X')) {
                        int cur = dsu.find(ind(nx, ny));
                        bad.erase(cur);
                        if (dsu.dot[cur]) {
                            good.insert(cur);
                        }
                    }
                }
            }
        }
    }
    cout << good.size() << " ";
    dbg() << bad;

    int sol = 0;
    for (auto &i: bad) {
        sol += dsu.dot[i];
        dbg() << i << " " << dsu.dot[i];
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
