/* Author: izhang
 * Time: 11-26-2022 15:11:47
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
//using namespace kactl;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 55;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
const int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
char grid[maxn][maxn];
int n, m;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void test_case() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 2; ++j) {
            if (grid[i][j] == '*' && grid[i][j + 1] == '*' && grid[i][j + 2] == '*') {
                cout << "NO"
                     << "\n";
                return;
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n - 2; ++i) {
            if (grid[i][j] == '*' && grid[i + 1][j] == '*' && grid[i + 2][j] == '*') {
                cout << "NO"
                     << "\n";
                return;
            }
        }
    }
    kactl::UF dsu(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                continue;
            }
            for (int k = 0; k < 8; ++k) {
                int nx = i + dx[k], ny = j + dy[k];
                if (valid(nx, ny)) {
                    if (grid[nx][ny] == '*') {
                        dsu.join()
                    }
                }
            }
        }
    }
    cout << "YES"
         << "\n";
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
