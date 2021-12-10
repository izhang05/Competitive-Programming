#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 100;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int a[maxn][maxn];

int par[maxn * maxn], sz[maxn * maxn];

int get(int x) {
    return par[x] == x ? x : par[x] = get(par[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot != yroot) {
        par[xroot] = yroot;
        sz[yroot] += sz[xroot];
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < maxn && y < maxn;
}

int ind(int x, int y) {
    return x * maxn + y;
}

void solve() {
    int n = 100;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            par[ind(i, j)] = ind(i, j);
            sz[ind(i, j)] = 1;
        }
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            a[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 9) {
                continue;
            }
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k], ny = j + dy[k];
                if (valid(nx, ny) && a[nx][ny] != 9) {
                    merge(ind(nx, ny), ind(i, j));
                }
            }
        }
    }
    set<int, greater<>> sol;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sol.insert(sz[get(ind(i, j))]);
        }
    }
    long long res = 1;
    for (int i = 0; i < 3; ++i) {
        res *= *sol.begin();
        sol.erase(sol.begin());
    }
    cout << res << "\n";
}

int main() {
    setIO("9");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
